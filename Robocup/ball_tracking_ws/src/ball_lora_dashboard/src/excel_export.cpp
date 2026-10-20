#include "ball_lora_dashboard/excel_export.hpp"

#include <QByteArray>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QTemporaryFile>
#include <QXmlStreamWriter>

#include <zip.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

namespace ball_lora_dashboard {
namespace {

constexpr const char* kSpreadsheetNamespace =
    "http://schemas.openxmlformats.org/spreadsheetml/2006/main";

QString columnName(int zero_based_column) {
  QString result;
  for (int value = zero_based_column + 1; value > 0; value /= 26) {
    --value;
    result.prepend(QChar('A' + value % 26));
  }
  return result;
}

void textCell(QXmlStreamWriter& xml, int column, std::size_t row,
              const QString& text, bool heading = false) {
  xml.writeStartElement(QStringLiteral("c"));
  xml.writeAttribute(QStringLiteral("r"), columnName(column) + QString::number(row));
  xml.writeAttribute(QStringLiteral("t"), QStringLiteral("inlineStr"));
  if (heading) xml.writeAttribute(QStringLiteral("s"), QStringLiteral("1"));
  xml.writeStartElement(QStringLiteral("is"));
  xml.writeTextElement(QStringLiteral("t"), text);
  xml.writeEndElement();
  xml.writeEndElement();
}

void numberCell(QXmlStreamWriter& xml, int column, std::size_t row,
                const QString& number) {
  xml.writeStartElement(QStringLiteral("c"));
  xml.writeAttribute(QStringLiteral("r"), columnName(column) + QString::number(row));
  xml.writeTextElement(QStringLiteral("v"), number);
  xml.writeEndElement();
}

bool writeWorksheet(QIODevice* output, const std::vector<TelemetryRecord>& records,
                    std::size_t channel_count) {
  QXmlStreamWriter xml(output);
  xml.setAutoFormatting(false);
  xml.writeStartDocument();
  xml.writeStartElement(QStringLiteral("worksheet"));
  xml.writeDefaultNamespace(QString::fromLatin1(kSpreadsheetNamespace));
  xml.writeStartElement(QStringLiteral("sheetViews"));
  xml.writeStartElement(QStringLiteral("sheetView"));
  xml.writeAttribute(QStringLiteral("workbookViewId"), QStringLiteral("0"));
  xml.writeStartElement(QStringLiteral("pane"));
  xml.writeAttribute(QStringLiteral("ySplit"), QStringLiteral("1"));
  xml.writeAttribute(QStringLiteral("topLeftCell"), QStringLiteral("A2"));
  xml.writeAttribute(QStringLiteral("activePane"), QStringLiteral("bottomLeft"));
  xml.writeAttribute(QStringLiteral("state"), QStringLiteral("frozen"));
  xml.writeEndElement();
  xml.writeEndElement();
  xml.writeEndElement();
  xml.writeStartElement(QStringLiteral("sheetFormatPr"));
  xml.writeAttribute(QStringLiteral("defaultRowHeight"), QStringLiteral("16"));
  xml.writeEndElement();
  xml.writeStartElement(QStringLiteral("cols"));
  for (std::size_t i = 0; i < channel_count + 2; ++i) {
    xml.writeStartElement(QStringLiteral("col"));
    xml.writeAttribute(QStringLiteral("min"), QString::number(i + 1));
    xml.writeAttribute(QStringLiteral("max"), QString::number(i + 1));
    xml.writeAttribute(QStringLiteral("width"),
                       i == 0 ? QStringLiteral("25") : QStringLiteral("15"));
    xml.writeAttribute(QStringLiteral("customWidth"), QStringLiteral("1"));
    xml.writeEndElement();
  }
  xml.writeEndElement();

  xml.writeStartElement(QStringLiteral("sheetData"));
  xml.writeStartElement(QStringLiteral("row"));
  xml.writeAttribute(QStringLiteral("r"), QStringLiteral("1"));
  textCell(xml, 0, 1, QStringLiteral("接收时间"), true);
  textCell(xml, 1, 1, QStringLiteral("帧号"), true);
  for (std::size_t i = 0; i < channel_count; ++i) {
    textCell(xml, static_cast<int>(i + 2), 1,
             QStringLiteral("num%1").arg(i + 1), true);
  }
  xml.writeEndElement();

  for (std::size_t i = 0; i < records.size(); ++i) {
    const auto& record = records[i];
    const std::size_t row = i + 2;
    xml.writeStartElement(QStringLiteral("row"));
    xml.writeAttribute(QStringLiteral("r"), QString::number(row));
    textCell(xml, 0, row, QDateTime::fromMSecsSinceEpoch(record.timestamp_ms)
                              .toString(QStringLiteral("yyyy-MM-dd HH:mm:ss.zzz")));
    numberCell(xml, 1, row, QString::number(static_cast<qulonglong>(record.frame_index)));
    for (std::size_t channel = 0; channel < record.values.size(); ++channel) {
      if (std::isfinite(record.values[channel])) {
        numberCell(xml, static_cast<int>(channel + 2), row,
                   QString::number(record.values[channel], 'g', 9));
      }
    }
    xml.writeEndElement();
  }
  xml.writeEndElement();
  xml.writeStartElement(QStringLiteral("autoFilter"));
  xml.writeAttribute(QStringLiteral("ref"),
                     QStringLiteral("A1:%1%2")
                         .arg(columnName(static_cast<int>(channel_count + 1)))
                         .arg(records.size() + 1));
  xml.writeEndElement();
  xml.writeEndElement();
  xml.writeEndDocument();
  return !xml.hasError();
}

}  // namespace

ExcelExportResult writeExcel(const QString& path,
                            const std::vector<TelemetryRecord>& records) {
  if (records.empty()) return {false, QStringLiteral("没有可导出的数据"), 0};
  if (records.size() >= 1048576) {
    return {false, QStringLiteral("数据行数超过 Excel 工作表上限"), 0};
  }
  const std::size_t channel_count = std::min<std::size_t>(64,
      std::max_element(records.begin(), records.end(),
          [](const auto& a, const auto& b) {
            return a.values.size() < b.values.size();
          })->values.size());

  QTemporaryFile worksheet_file;
  if (!worksheet_file.open() ||
      !writeWorksheet(&worksheet_file, records, channel_count) ||
      !worksheet_file.flush()) {
    return {false, QStringLiteral("生成 Excel 工作表失败"), 0};
  }
  const QByteArray native_worksheet = QFile::encodeName(worksheet_file.fileName());
  worksheet_file.close();

  std::vector<std::pair<const char*, QByteArray>> parts{
      {"[Content_Types].xml", QByteArray(R"(<?xml version="1.0" encoding="UTF-8"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types"><Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/><Default Extension="xml" ContentType="application/xml"/><Override PartName="/xl/workbook.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"/><Override PartName="/xl/worksheets/sheet1.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"/><Override PartName="/xl/styles.xml" ContentType="application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"/></Types>)")},
      {"_rels/.rels", QByteArray(R"(<?xml version="1.0" encoding="UTF-8"?>
<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships"><Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument" Target="xl/workbook.xml"/></Relationships>)")},
      {"xl/workbook.xml", QByteArray(R"(<?xml version="1.0" encoding="UTF-8"?>
<workbook xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:r="http://schemas.openxmlformats.org/officeDocument/2006/relationships"><sheets><sheet name="MCU Data" sheetId="1" r:id="rId1"/></sheets></workbook>)")},
      {"xl/_rels/workbook.xml.rels", QByteArray(R"(<?xml version="1.0" encoding="UTF-8"?>
<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships"><Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet" Target="worksheets/sheet1.xml"/><Relationship Id="rId2" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles" Target="styles.xml"/></Relationships>)")},
      {"xl/styles.xml", QByteArray(R"(<?xml version="1.0" encoding="UTF-8"?>
<styleSheet xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main"><fonts count="2"><font><sz val="11"/><name val="Calibri"/></font><font><b/><sz val="11"/><color rgb="FFFFFFFF"/><name val="Calibri"/></font></fonts><fills count="3"><fill><patternFill patternType="none"/></fill><fill><patternFill patternType="gray125"/></fill><fill><patternFill patternType="solid"><fgColor rgb="FF2563EB"/><bgColor indexed="64"/></patternFill></fill></fills><borders count="1"><border><left/><right/><top/><bottom/><diagonal/></border></borders><cellStyleXfs count="1"><xf numFmtId="0" fontId="0" fillId="0" borderId="0"/></cellStyleXfs><cellXfs count="2"><xf numFmtId="0" fontId="0" fillId="0" borderId="0" xfId="0"/><xf numFmtId="0" fontId="1" fillId="2" borderId="0" xfId="0" applyFont="1" applyFill="1"/></cellXfs><cellStyles count="1"><cellStyle name="Normal" xfId="0" builtinId="0"/></cellStyles></styleSheet>)")},
  };

  QTemporaryFile temporary(QFileInfo(path).absolutePath() +
                           QStringLiteral("/.ball_lora_excel_XXXXXX"));
  if (!temporary.open()) {
    return {false, QStringLiteral("无法在目标目录创建临时文件"), 0};
  }
  temporary.setAutoRemove(false);
  const QString temp_path = temporary.fileName();
  temporary.close();

  int zip_error = 0;
  const QByteArray native_temp = QFile::encodeName(temp_path);
  zip_t* archive = zip_open(native_temp.constData(), ZIP_CREATE | ZIP_TRUNCATE,
                            &zip_error);
  if (!archive) {
    QFile::remove(temp_path);
    return {false, QStringLiteral("无法创建 XLSX 文件（ZIP 错误 %1）").arg(zip_error), 0};
  }
  for (auto& part : parts) {
    zip_source_t* source = zip_source_buffer(archive, part.second.constData(),
                                             static_cast<zip_uint64_t>(part.second.size()), 0);
    if (!source || zip_file_add(archive, part.first, source, ZIP_FL_ENC_UTF_8) < 0) {
      if (source) zip_source_free(source);
      const QString message = QString::fromLocal8Bit(zip_strerror(archive));
      zip_discard(archive);
      QFile::remove(temp_path);
      return {false, QStringLiteral("写入 XLSX 失败：%1").arg(message), 0};
    }
  }
  zip_source_t* worksheet_source = zip_source_file(
      archive, native_worksheet.constData(), 0, -1);
  if (!worksheet_source || zip_file_add(archive, "xl/worksheets/sheet1.xml",
                                        worksheet_source, ZIP_FL_ENC_UTF_8) < 0) {
    if (worksheet_source) zip_source_free(worksheet_source);
    const QString message = QString::fromLocal8Bit(zip_strerror(archive));
    zip_discard(archive);
    QFile::remove(temp_path);
    return {false, QStringLiteral("写入 Excel 工作表失败：%1").arg(message), 0};
  }
  if (zip_close(archive) < 0) {
    const QString message = QString::fromLocal8Bit(zip_strerror(archive));
    zip_discard(archive);
    QFile::remove(temp_path);
    return {false, QStringLiteral("完成 XLSX 失败：%1").arg(message), 0};
  }
  const QByteArray native_target = QFile::encodeName(path);
  if (std::rename(native_temp.constData(), native_target.constData()) != 0) {
    QFile::remove(temp_path);
    return {false, QStringLiteral("无法将 XLSX 文件保存到指定位置"), 0};
  }
  return {true, QStringLiteral("已导出 %1 帧数据").arg(records.size()), records.size()};
}

}  // namespace ball_lora_dashboard
