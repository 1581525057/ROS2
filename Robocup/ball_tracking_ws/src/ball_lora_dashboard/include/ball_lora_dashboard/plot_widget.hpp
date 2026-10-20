#pragma once

#include "ball_lora_dashboard/history.hpp"

#include <QElapsedTimer>
#include <QPoint>
#include <QRectF>
#include <QTimer>
#include <QWidget>

#include <cstdint>
#include <deque>
#include <utility>
#include <vector>

class QMouseEvent;
class QWheelEvent;

namespace ball_lora_dashboard {

class PlotWidget : public QWidget {
  Q_OBJECT

 public:
  explicit PlotWidget(QWidget* parent = nullptr);
  void addSample(const std::vector<float>& values, qint64 timestamp_ms = -1);
  void expireBefore(qint64 cutoff_ms);
  void setSelectedChannels(std::vector<int> channels);
  void clear();
  void zoomIn();
  void zoomOut();
  void resetView();
  bool isFollowingLive() const { return follow_live_; }
  std::pair<double, double> visibleRange() const;
  qint64 oldestTimestampMs() const;
  qint64 latestTimestampMs() const;
  void seekToTime(qint64 right_ms);

 signals:
  void channelToggled(int channel);
  void followModeChanged(bool following_live);
  void timelineChanged();

 protected:
  void paintEvent(QPaintEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseDoubleClickEvent(QMouseEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;
  void leaveEvent(QEvent* event) override;

 private:
  struct Sample {
    std::uint64_t id;
    qint64 timestamp_ms;
    std::vector<float> values;
  };
  enum class DragMode { None, Select, Pan };

  static constexpr qint64 kLiveWindowMs = 15000;
  QRectF plotRect() const;
  void setManualRange(double left, double right);
  void zoomAround(double anchor, double factor);
  void requestFrame();
  void renderTick();

  std::deque<Sample> samples_;
  std::vector<int> selected_channels_;
  std::uint64_t next_id_ = 0;
  QTimer redraw_timer_;
  QElapsedTimer tick_clock_;
  double display_right_ = 0.0;
  bool follow_live_ = true;
  double manual_left_ = 0.0;
  double manual_right_ = 0.0;
  bool dirty_ = true;
  bool hovering_ = false;
  QPoint hover_pos_;
  DragMode drag_mode_ = DragMode::None;
  QPoint drag_start_;
  QPoint drag_current_;
};

}  // namespace ball_lora_dashboard
