#pragma once

#include <QString>

#include <cstdint>
#include <vector>

namespace ball_lora_dashboard {

struct TelemetryRecord {
  std::uint64_t frame_index;
  qint64 timestamp_ms;
  std::vector<float> values;
};

struct ExcelExportResult {
  bool success;
  QString message;
  std::size_t row_count;
};

ExcelExportResult writeExcel(const QString& path,
                            const std::vector<TelemetryRecord>& records);

}  // namespace ball_lora_dashboard
