#include "ball_lora_dashboard/excel_export.hpp"

#include <QByteArray>
#include <QFile>
#include <QTemporaryDir>

#include <zip.h>

#include <iostream>
#include <limits>
#include <vector>

QByteArray readPart(zip_t* archive, const char* name) {
  zip_stat_t stat;
  if (zip_stat(archive, name, 0, &stat) != 0) return {};
  zip_file_t* file = zip_fopen(archive, name, 0);
  if (!file) return {};
  QByteArray bytes(static_cast<int>(stat.size), Qt::Uninitialized);
  const zip_int64_t count = zip_fread(file, bytes.data(), stat.size);
  zip_fclose(file);
  return count == static_cast<zip_int64_t>(stat.size) ? bytes : QByteArray();
}

int main(int argc, char* argv[]) {
  QTemporaryDir directory;
  const QString path = argc > 1 ? QString::fromLocal8Bit(argv[1])
                                : directory.filePath(QStringLiteral("数据.xlsx"));
  const std::vector<ball_lora_dashboard::TelemetryRecord> records{
      {1, 1700000000000LL, {1.25f, -2.0f}},
      {2, 1700000000100LL,
       {std::numeric_limits<float>::quiet_NaN(), 3.5f, 4.0f}},
  };
  const auto result = ball_lora_dashboard::writeExcel(path, records);
  if (!result.success || result.row_count != 2 || !QFile::exists(path)) {
    std::cerr << result.message.toStdString() << '\n';
    return 1;
  }
  int error = 0;
  const QByteArray native = QFile::encodeName(path);
  zip_t* archive = zip_open(native.constData(), ZIP_RDONLY, &error);
  if (!archive) return 1;
  const QByteArray types = readPart(archive, "[Content_Types].xml");
  const QByteArray workbook = readPart(archive, "xl/workbook.xml");
  const QByteArray styles = readPart(archive, "xl/styles.xml");
  const QByteArray sheet = readPart(archive, "xl/worksheets/sheet1.xml");
  zip_close(archive);
  if (types.isEmpty() || workbook.isEmpty() || styles.isEmpty() ||
      !sheet.contains("num3") || !sheet.contains("r=\"C2\"><v>1.25</v>") ||
      !sheet.contains("r=\"E3\"><v>4</v>") || sheet.contains("r=\"C3\"")) {
    std::cerr << "Unexpected XLSX contents\n";
    return 1;
  }
  return 0;
}
