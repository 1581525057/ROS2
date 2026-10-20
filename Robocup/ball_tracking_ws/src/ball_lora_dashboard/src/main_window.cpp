#include "ball_lora_dashboard/main_window.hpp"

#include <QComboBox>
#include <QDateTime>
#include <QFileDialog>
#include <QFutureWatcher>
#include <QGroupBox>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QSignalBlocker>
#include <QSlider>
#include <QSplitter>
#include <QStatusBar>
#include <QTableWidget>
#include <QTimer>
#include <QVBoxLayout>
#include <QtConcurrent/QtConcurrent>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

namespace ball_lora_dashboard {

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), serial_(new SerialPort(this)) {
  setWindowTitle(QStringLiteral("LoRa 小球上位机"));
  resize(1160, 740);
  setMinimumSize(850, 560);

  auto* central = new QWidget(this);
  setCentralWidget(central);
  auto* root = new QVBoxLayout(central);
  root->setContentsMargins(18, 18, 18, 18);
  root->setSpacing(14);

  auto* title = new QLabel(QStringLiteral("LoRa 单片机数据监控"), central);
  title->setObjectName(QStringLiteral("pageTitle"));
  root->addWidget(title);

  auto* connection_group = new QGroupBox(QStringLiteral("串口连接"), central);
  auto* connection_row = new QHBoxLayout(connection_group);
  connection_row->addWidget(new QLabel(QStringLiteral("设备")));
  port_combo_ = new SerialDeviceComboBox(connection_group);
  port_combo_->setEditText(QStringLiteral("/dev/ttyUSB0"));
  connection_row->addWidget(port_combo_, 2);
  auto* refresh_button = new QPushButton(QStringLiteral("刷新设备"), connection_group);
  refresh_button->setObjectName(QStringLiteral("secondaryButton"));
  connection_row->addWidget(refresh_button);
  connection_row->addWidget(new QLabel(QStringLiteral("波特率")));
  baud_combo_ = new QComboBox(connection_group);
  for (const int baud : {9600, 19200, 38400, 57600, 115200}) {
    baud_combo_->addItem(QString::number(baud), baud);
  }
  connection_row->addWidget(baud_combo_);
  connect_button_ = new QPushButton(QStringLiteral("连接"), connection_group);
  connection_row->addWidget(connect_button_);
  connection_label_ = new QLabel(QStringLiteral("未连接"), connection_group);
  connection_label_->setMinimumWidth(200);
  connection_row->addWidget(connection_label_);
  root->addWidget(connection_group);

  auto* splitter = new QSplitter(Qt::Horizontal, central);
  auto* left = new QWidget(splitter);
  auto* left_layout = new QVBoxLayout(left);
  left_layout->setContentsMargins(0, 0, 0, 0);
  left_layout->setSpacing(12);

  auto* data_group = new QGroupBox(QStringLiteral("单片机实时数据"), left);
  auto* data_layout = new QVBoxLayout(data_group);
  frame_label_ = new QLabel(QStringLiteral("等待数据帧"), data_group);
  data_layout->addWidget(frame_label_);
  auto* channel_actions = new QHBoxLayout();
  auto* select_first_button = new QPushButton(QStringLiteral("选择前 8 路"), data_group);
  auto* clear_selection_button = new QPushButton(QStringLiteral("清空选择"), data_group);
  auto* export_button = new QPushButton(QStringLiteral("导出 Excel"), data_group);
  select_first_button->setObjectName(QStringLiteral("secondaryButton"));
  clear_selection_button->setObjectName(QStringLiteral("secondaryButton"));
  export_button->setObjectName(QStringLiteral("secondaryButton"));
  channel_actions->addWidget(select_first_button);
  channel_actions->addWidget(clear_selection_button);
  channel_actions->addWidget(export_button);
  data_layout->addLayout(channel_actions);
  table_ = new QTableWidget(0, 2, data_group);
  table_->setHorizontalHeaderLabels({QStringLiteral("通道 / 曲线"), QStringLiteral("当前值")});
  table_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  table_->verticalHeader()->hide();
  table_->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table_->setSelectionMode(QAbstractItemView::NoSelection);
  table_->setAlternatingRowColors(true);
  data_layout->addWidget(table_, 1);
  selection_label_ = new QLabel(QStringLiteral("勾选通道绘制曲线，最多显示 8 条"), data_group);
  data_layout->addWidget(selection_label_);
  raw_label_ = new QLabel(QStringLiteral("原始帧：—"), data_group);
  raw_label_->setWordWrap(true);
  raw_label_->setTextInteractionFlags(Qt::TextSelectableByMouse);
  data_layout->addWidget(raw_label_);
  left_layout->addWidget(data_group, 1);

  auto* control_group = new QGroupBox(QStringLiteral("启停与目标颜色"), left);
  auto* control_layout = new QVBoxLayout(control_group);
  control_layout->addWidget(new QLabel(
      QStringLiteral("key1：启动/停止    key2：红球/蓝球"), control_group));
  auto* buttons = new QHBoxLayout();
  start_button_ = new QPushButton(QStringLiteral("启动"), control_group);
  red_button_ = new QPushButton(QStringLiteral("选择红球  RED"), control_group);
  blue_button_ = new QPushButton(QStringLiteral("选择蓝球  BLUE"), control_group);
  start_button_->setObjectName(QStringLiteral("startButton"));
  red_button_->setObjectName(QStringLiteral("redButton"));
  blue_button_->setObjectName(QStringLiteral("blueButton"));
  start_button_->setCheckable(true);
  red_button_->setCheckable(true);
  blue_button_->setCheckable(true);
  blue_button_->setChecked(true);
  start_button_->setEnabled(false);
  red_button_->setEnabled(false);
  blue_button_->setEnabled(false);
  buttons->addWidget(start_button_);
  buttons->addWidget(red_button_);
  buttons->addWidget(blue_button_);
  control_layout->addLayout(buttons);
  control_status_label_ = new QLabel(QStringLiteral("状态：停止 · 蓝球"), control_group);
  control_layout->addWidget(control_status_label_);
  left_layout->addWidget(control_group);

  auto* chart_group = new QGroupBox(QStringLiteral("数据曲线"), splitter);
  auto* chart_layout = new QVBoxLayout(chart_group);
  auto* chart_tools = new QHBoxLayout();
  auto* zoom_in_button = new QPushButton(QStringLiteral("＋ 放大"), chart_group);
  auto* zoom_out_button = new QPushButton(QStringLiteral("－ 缩小"), chart_group);
  auto* live_button = new QPushButton(QStringLiteral("回到实时"), chart_group);
  auto* save_button = new QPushButton(QStringLiteral("保存图像"), chart_group);
  zoom_in_button->setObjectName(QStringLiteral("secondaryButton"));
  zoom_out_button->setObjectName(QStringLiteral("secondaryButton"));
  live_button->setObjectName(QStringLiteral("secondaryButton"));
  save_button->setObjectName(QStringLiteral("secondaryButton"));
  auto* view_label = new QLabel(QStringLiteral("● 实时跟随"), chart_group);
  chart_tools->addWidget(zoom_in_button);
  chart_tools->addWidget(zoom_out_button);
  chart_tools->addWidget(live_button);
  chart_tools->addWidget(save_button);
  chart_tools->addStretch();
  chart_tools->addWidget(view_label);
  chart_layout->addLayout(chart_tools);
  plot_ = new PlotWidget(chart_group);
  plot_->setObjectName(QStringLiteral("telemetryPlot"));
  chart_layout->addWidget(plot_);
  chart_layout->addWidget(new QLabel(QStringLiteral("时间轴 · 最多保留 5 分钟"), chart_group));
  auto* timeline_row = new QHBoxLayout();
  timeline_row->addWidget(new QLabel(QStringLiteral("较早"), chart_group));
  timeline_slider_ = new QSlider(Qt::Horizontal, chart_group);
  timeline_slider_->setObjectName(QStringLiteral("historyTimeline"));
  timeline_slider_->setEnabled(false);
  timeline_row->addWidget(timeline_slider_, 1);
  timeline_row->addWidget(new QLabel(QStringLiteral("实时"), chart_group));
  chart_layout->addLayout(timeline_row);
  chart_layout->addWidget(new QLabel(
      QStringLiteral("拖动时间轴查看历史 · 滚轮缩放 · 左键框选 · 右键拖动 · 双击回到实时"),
      chart_group));
  splitter->addWidget(left);
  splitter->addWidget(chart_group);
  splitter->setStretchFactor(0, 1);
  splitter->setStretchFactor(1, 2);
  root->addWidget(splitter, 1);

  setStyleSheet(QStringLiteral(R"(
    QMainWindow, QWidget { background: #f4f7fb; color: #1e293b; font-size: 13px; }
    QLabel#pageTitle { font-size: 23px; font-weight: 700; padding: 4px 0; }
    QGroupBox { background: white; border: 1px solid #dbe3ee; border-radius: 10px;
                margin-top: 12px; padding: 14px; font-weight: 600; }
    QGroupBox::title { subcontrol-origin: margin; left: 14px; padding: 0 5px; }
    QLineEdit, QComboBox { background: white; border: 1px solid #cbd5e1;
                         border-radius: 6px; padding: 6px; }
    QPushButton { background: #2563eb; color: white; border: 0; border-radius: 7px;
                  padding: 9px 14px; font-weight: 600; }
    QPushButton:hover { background: #1d4ed8; }
    QPushButton:disabled { background: #94a3b8; }
    QPushButton#redButton { background: #dc2626; }
    QPushButton#redButton:hover { background: #b91c1c; }
    QPushButton#blueButton { background: #2563eb; }
    QPushButton#startButton:checked { background: #16a34a; }
    QPushButton#redButton:checked, QPushButton#blueButton:checked {
      border: 3px solid #0f172a; padding: 6px 11px; }
    QPushButton#startButton:disabled, QPushButton#redButton:disabled,
    QPushButton#blueButton:disabled { background: #94a3b8; }
    QPushButton#secondaryButton { background: #edf3fc; color: #1e40af;
                                  border: 1px solid #cbdaf3; padding: 6px 10px; }
    QPushButton#secondaryButton:hover { background: #dbeafe; }
    QTableWidget { background: white; alternate-background-color: #f8fafc;
                   border: 1px solid #e2e8f0; gridline-color: #e2e8f0; }
    QHeaderView::section { background: #eaf0f8; padding: 7px; border: 0; }
  )"));

  key_timer_ = new QTimer(this);
  key_timer_->setInterval(200);
  partial_timer_ = new QTimer(this);
  partial_timer_->setInterval(50);
  partial_timer_->start();
  demo_timer_ = new QTimer(this);
  demo_timer_->setInterval(50);
  auto* history_timer = new QTimer(this);
  history_timer->setInterval(1000);
  connect(history_timer, &QTimer::timeout, this, [this] {
    const qint64 cutoff_ms = QDateTime::currentMSecsSinceEpoch() - kHistoryDurationMs;
    const bool had_records = !records_.empty();
    while (!records_.empty() && records_.front().timestamp_ms < cutoff_ms) {
      records_.pop_front();
    }
    plot_->expireBefore(cutoff_ms);
    if (had_records && records_.empty()) {
      table_->setRowCount(0);
      updateSelectedChannels();
      frame_label_->setText(QStringLiteral("最近 5 分钟没有收到数据"));
      raw_label_->setText(QStringLiteral("原始帧：—"));
    }
  });
  history_timer->start();

  connect(connect_button_, &QPushButton::clicked, this, [this] { toggleConnection(); });
  connect(refresh_button, &QPushButton::clicked, port_combo_,
          [this] { port_combo_->refreshDevices(); });
  connect(start_button_, &QPushButton::clicked, this, [this](bool checked) {
    started_ = checked;
    updateControlStatus();
    sendKey();
  });
  connect(red_button_, &QPushButton::clicked, this, [this] {
    blue_ = false;
    red_button_->setChecked(true);
    blue_button_->setChecked(false);
    updateControlStatus();
    sendKey();
  });
  connect(blue_button_, &QPushButton::clicked, this, [this] {
    blue_ = true;
    red_button_->setChecked(false);
    blue_button_->setChecked(true);
    updateControlStatus();
    sendKey();
  });
  connect(key_timer_, &QTimer::timeout, this, [this] { sendKey(); });
  connect(partial_timer_, &QTimer::timeout, this, [this] {
    if (decoder_.hasPartialFrame() && last_byte_clock_.isValid() &&
        last_byte_clock_.elapsed() > 200) decoder_.reset();
  });
  connect(table_, &QTableWidget::itemChanged, this, [this] { updateSelectedChannels(); });
  connect(select_first_button, &QPushButton::clicked, this, [this] {
    QSignalBlocker blocker(table_);
    for (int i = 0; i < table_->rowCount(); ++i) {
      if (auto* item = table_->item(i, 0)) {
        item->setCheckState(i < 8 ? Qt::Checked : Qt::Unchecked);
      }
    }
    updateSelectedChannels();
  });
  connect(clear_selection_button, &QPushButton::clicked, this, [this] {
    QSignalBlocker blocker(table_);
    for (int i = 0; i < table_->rowCount(); ++i) {
      if (auto* item = table_->item(i, 0)) item->setCheckState(Qt::Unchecked);
    }
    updateSelectedChannels();
  });
  connect(export_button, &QPushButton::clicked, this, [this, export_button] {
    if (records_.empty()) {
      QMessageBox::information(this, QStringLiteral("暂无数据"),
                               QStringLiteral("收到单片机数据后再导出。"));
      return;
    }
    QString path = QFileDialog::getSaveFileName(
        this, QStringLiteral("导出 Excel 表格"), QStringLiteral("ball_lora_data.xlsx"),
        QStringLiteral("Excel 工作簿 (*.xlsx)"));
    if (path.isEmpty()) return;
    if (!path.endsWith(QStringLiteral(".xlsx"), Qt::CaseInsensitive)) {
      path += QStringLiteral(".xlsx");
    }
    std::vector<TelemetryRecord> snapshot(records_.begin(), records_.end());
    export_button->setEnabled(false);
    export_button->setText(QStringLiteral("正在导出…"));
    auto* watcher = new QFutureWatcher<ExcelExportResult>(this);
    connect(watcher, &QFutureWatcher<ExcelExportResult>::finished, this,
            [this, watcher, export_button] {
              const ExcelExportResult result = watcher->result();
              export_button->setEnabled(true);
              export_button->setText(QStringLiteral("导出 Excel"));
              if (result.success) {
                statusBar()->showMessage(result.message, 8000);
              } else {
                QMessageBox::warning(this, QStringLiteral("导出失败"), result.message);
              }
              watcher->deleteLater();
            });
    watcher->setFuture(QtConcurrent::run(
        [path, snapshot = std::move(snapshot)] { return writeExcel(path, snapshot); }));
  });
  connect(zoom_in_button, &QPushButton::clicked, plot_, &PlotWidget::zoomIn);
  connect(zoom_out_button, &QPushButton::clicked, plot_, &PlotWidget::zoomOut);
  connect(live_button, &QPushButton::clicked, plot_, &PlotWidget::resetView);
  connect(save_button, &QPushButton::clicked, this, [this] {
    const QString path = QFileDialog::getSaveFileName(
        this, QStringLiteral("保存曲线图"), QStringLiteral("ball_lora_chart.png"),
        QStringLiteral("PNG 图像 (*.png)"));
    if (!path.isEmpty() && !saveChart(path)) {
      QMessageBox::warning(this, QStringLiteral("保存失败"),
                           QStringLiteral("无法将曲线图保存到指定位置。"));
    }
  });
  connect(plot_, &PlotWidget::followModeChanged, this,
          [view_label](bool following) {
            view_label->setText(following ? QStringLiteral("● 实时跟随")
                                          : QStringLiteral("● 历史查看"));
          });
  connect(plot_, &PlotWidget::timelineChanged, this, [this] { updateTimeline(); });
  connect(timeline_slider_, &QSlider::valueChanged, this, [this](int position_ms) {
    plot_->seekToTime(plot_->oldestTimestampMs() + position_ms);
  });
  connect(plot_, &PlotWidget::channelToggled, this, [this](int channel) {
    auto* item = table_->item(channel, 0);
    if (item) item->setCheckState(item->checkState() == Qt::Checked
                                      ? Qt::Unchecked : Qt::Checked);
  });
  connect(serial_, &SerialPort::bytesReceived, this,
          [this](const QByteArray& bytes) { onSerialBytes(bytes); });
  connect(serial_, &SerialPort::errorOccurred, this,
          [this](const QString& message) { onSerialError(message); });
  connect(demo_timer_, &QTimer::timeout, this, [this] {
    constexpr double pi = 3.14159265358979323846;
    const double t = 0.05 * static_cast<double>(demo_sample_++);
    const std::vector<float> values{
        static_cast<float>(0.62 * std::sin(2 * pi * 0.22 * t) + 0.06 * std::sin(4.7 * t)),
        static_cast<float>(0.38 * std::cos(2 * pi * 0.14 * t)),
        static_cast<float>(0.22 + 0.07 * std::sin(2 * pi * 0.09 * t)),
        static_cast<float>(0.48 + 0.18 * std::sin(2 * pi * 0.16 * t + 0.8)),
        static_cast<float>(0.52 + 0.13 * std::cos(2 * pi * 0.12 * t + 1.4)),
    };
    QByteArray frame;
    frame.reserve(3 + 4 * static_cast<int>(values.size()));
    frame.append(static_cast<char>(0xAA));
    frame.append(static_cast<char>(values.size()));
    for (const float value : values) {
      std::uint32_t bits = 0;
      std::memcpy(&bits, &value, sizeof(bits));
      for (int shift = 0; shift < 32; shift += 8) {
        frame.append(static_cast<char>((bits >> shift) & 0xFF));
      }
    }
    frame.append(static_cast<char>(0x55));
    onSerialBytes(frame);
  });
}

void MainWindow::startDemo() {
  if (serial_->isOpen()) serial_->closePort();
  key_timer_->stop();
  start_button_->setEnabled(false);
  decoder_.reset();
  plot_->clear();
  table_->setRowCount(0);
  frame_count_ = 0;
  records_.clear();
  demo_sample_ = 0;
  setWindowTitle(QStringLiteral("LoRa 小球上位机 · 模拟演示"));
  connect_button_->setText(QStringLiteral("连接真实串口"));
  connection_label_->setText(QStringLiteral("模拟数据运行中 · 5 路浮点数"));
  red_button_->setEnabled(false);
  blue_button_->setEnabled(false);
  demo_timer_->start();
}

bool MainWindow::saveChart(const QString& path) {
  return plot_->grab().save(path, "PNG");
}

void MainWindow::toggleConnection() {
  if (demo_timer_->isActive()) {
    demo_timer_->stop();
    setWindowTitle(QStringLiteral("LoRa 小球上位机"));
  }
  if (serial_->isOpen()) {
    key_timer_->stop();
    serial_->closePort();
    decoder_.reset();
    connect_button_->setText(QStringLiteral("连接"));
    connection_label_->setText(QStringLiteral("未连接"));
    start_button_->setEnabled(false);
    red_button_->setEnabled(false);
    blue_button_->setEnabled(false);
    return;
  }

  QString error;
  if (!serial_->openPort(port_combo_->currentText().trimmed(),
                         baud_combo_->currentData().toInt(), &error)) {
    connection_label_->setText(QStringLiteral("连接失败"));
    QMessageBox::warning(this, QStringLiteral("串口连接失败"), error);
    return;
  }
  decoder_.reset();
  plot_->clear();
  table_->setRowCount(0);
  frame_count_ = 0;
  records_.clear();
  raw_label_->setText(QStringLiteral("原始帧：—"));
  frame_label_->setText(QStringLiteral("等待数据帧"));
  connect_button_->setText(QStringLiteral("断开"));
  connection_label_->setText(QStringLiteral("已连接 %1 · %2 baud")
                                 .arg(port_combo_->currentText().trimmed())
                                 .arg(baud_combo_->currentData().toInt()));
  start_button_->setEnabled(true);
  red_button_->setEnabled(true);
  blue_button_->setEnabled(true);
  updateControlStatus();
  sendKey();
  key_timer_->start();
}

void MainWindow::onSerialBytes(const QByteArray& bytes) {
  if (decoder_.hasPartialFrame() && last_byte_clock_.isValid() &&
      last_byte_clock_.elapsed() > 200) decoder_.reset();
  last_byte_clock_.restart();
  const auto* data = reinterpret_cast<const std::uint8_t*>(bytes.constData());
  for (const auto& frame : decoder_.feed(data, static_cast<std::size_t>(bytes.size()))) {
    showFrame(frame);
  }
}

void MainWindow::showFrame(const McuFrame& frame) {
  ++frame_count_;
  const qint64 clock_ms = QDateTime::currentMSecsSinceEpoch();
  const qint64 timestamp_ms = records_.empty() ? clock_ms
      : std::max(clock_ms, records_.back().timestamp_ms);
  records_.push_back({frame_count_, timestamp_ms, frame.values});
  while (!records_.empty() &&
         timestamp_ms - records_.front().timestamp_ms > kHistoryDurationMs) {
    records_.pop_front();
  }
  frame_label_->setText(QStringLiteral("已接收 %1 帧 · 本帧 %2 个数值 · %3")
                            .arg(frame_count_)
                            .arg(frame.values.size())
                            .arg(QDateTime::fromMSecsSinceEpoch(timestamp_ms)
                                     .toString("HH:mm:ss.zzz")));

  const bool first_frame = table_->rowCount() == 0;
  const bool channel_count_changed = table_->rowCount() != static_cast<int>(frame.values.size());
  {
    QSignalBlocker blocker(table_);
    table_->setRowCount(static_cast<int>(frame.values.size()));
    for (int i = 0; i < static_cast<int>(frame.values.size()); ++i) {
      auto* channel = table_->item(i, 0);
      if (!channel) {
        channel = new QTableWidgetItem(QStringLiteral("num%1").arg(i + 1));
        channel->setFlags(channel->flags() | Qt::ItemIsUserCheckable);
        channel->setCheckState(first_frame && i < 3 ? Qt::Checked : Qt::Unchecked);
        table_->setItem(i, 0, channel);
      }
      auto* value = table_->item(i, 1);
      if (!value) {
        value = new QTableWidgetItem();
        table_->setItem(i, 1, value);
      }
      value->setText(QString::number(frame.values[i], 'g', 8));
    }
  }
  const QByteArray raw(reinterpret_cast<const char*>(frame.raw.data()),
                       static_cast<int>(frame.raw.size()));
  raw_label_->setText(QStringLiteral("原始帧：%1").arg(QString::fromLatin1(raw.toHex(' ').toUpper())));
  plot_->addSample(frame.values, timestamp_ms);
  if (channel_count_changed) updateSelectedChannels();
}

void MainWindow::updateSelectedChannels() {
  std::vector<int> selected;
  for (int i = 0; i < table_->rowCount(); ++i) {
    const auto* item = table_->item(i, 0);
    if (item && item->checkState() == Qt::Checked) selected.push_back(i);
  }
  const std::size_t shown = std::min<std::size_t>(selected.size(), 8);
  selection_label_->setText(QStringLiteral("已选 %1 个通道 · 显示前 %2 条曲线（最多 8 条）")
                                .arg(selected.size()).arg(shown));
  plot_->setSelectedChannels(std::move(selected));
}

void MainWindow::updateTimeline() {
  const qint64 oldest = plot_->oldestTimestampMs();
  const qint64 newest = plot_->latestTimestampMs();
  const int duration_ms = static_cast<int>(std::max<qint64>(0, newest - oldest));
  const auto [left, right] = plot_->visibleRange();
  const int span_ms = static_cast<int>(std::max(0.0, std::ceil(right - left)));
  const int minimum = std::min(duration_ms, span_ms);
  const QSignalBlocker blocker(timeline_slider_);
  timeline_slider_->setRange(minimum, duration_ms);
  timeline_slider_->setValue(plot_->isFollowingLive() ? duration_ms
      : std::clamp(static_cast<int>(std::llround(right - oldest)), minimum, duration_ms));
  timeline_slider_->setEnabled(duration_ms > minimum);
}

void MainWindow::sendKey() {
  if (!serial_->isOpen()) return;
  const auto frame = encodeKeyFrame(sequence_, started_, blue_);
  serial_->send(QByteArray(reinterpret_cast<const char*>(frame.data()),
                           static_cast<int>(frame.size())));
  sequence_ = static_cast<std::uint8_t>(sequence_ + 1);
}

void MainWindow::updateControlStatus() {
  start_button_->setText(started_ ? QStringLiteral("停止") : QStringLiteral("启动"));
  control_status_label_->setText(QStringLiteral("状态：%1 · %2")
      .arg(started_ ? QStringLiteral("启动") : QStringLiteral("停止"))
      .arg(blue_ ? QStringLiteral("蓝球") : QStringLiteral("红球")));
}

void MainWindow::onSerialError(const QString& message) {
  key_timer_->stop();
  start_button_->setEnabled(false);
  decoder_.reset();
  connect_button_->setText(QStringLiteral("连接"));
  connection_label_->setText(message);
  red_button_->setEnabled(false);
  blue_button_->setEnabled(false);
}

}  // namespace ball_lora_dashboard
