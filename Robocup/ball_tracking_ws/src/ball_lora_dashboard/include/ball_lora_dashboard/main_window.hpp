#pragma once

#include "ball_lora_dashboard/excel_export.hpp"
#include "ball_lora_dashboard/history.hpp"
#include "ball_lora_dashboard/plot_widget.hpp"
#include "ball_lora_dashboard/protocol.hpp"
#include "ball_lora_dashboard/serial_port.hpp"
#include "ball_lora_dashboard/serial_device_combo.hpp"

#include <QElapsedTimer>
#include <QMainWindow>

#include <cstdint>
#include <deque>

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTimer;
class QSlider;

namespace ball_lora_dashboard {

class MainWindow : public QMainWindow {
 public:
  explicit MainWindow(QWidget* parent = nullptr);
  void startDemo();
  bool saveChart(const QString& path);

 private:
  void toggleConnection();
  void onSerialBytes(const QByteArray& bytes);
  void showFrame(const McuFrame& frame);
  void updateSelectedChannels();
  void sendKey();
  void updateControlStatus();
  void onSerialError(const QString& message);
  void updateTimeline();

  SerialPort* serial_;
  McuFrameDecoder decoder_;
  QElapsedTimer last_byte_clock_;
  QTimer* partial_timer_;
  QTimer* key_timer_;
  QTimer* demo_timer_;
  SerialDeviceComboBox* port_combo_;
  QComboBox* baud_combo_;
  QPushButton* connect_button_;
  QPushButton* start_button_;
  QPushButton* red_button_;
  QPushButton* blue_button_;
  QLabel* control_status_label_;
  QLabel* connection_label_;
  QLabel* frame_label_;
  QLabel* raw_label_;
  QLabel* selection_label_;
  QTableWidget* table_;
  PlotWidget* plot_;
  QSlider* timeline_slider_;
  std::uint8_t sequence_ = 0;
  bool started_ = false;
  bool blue_ = true;
  std::uint64_t frame_count_ = 0;
  std::uint64_t demo_sample_ = 0;
  std::deque<TelemetryRecord> records_;
};

}  // namespace ball_lora_dashboard
