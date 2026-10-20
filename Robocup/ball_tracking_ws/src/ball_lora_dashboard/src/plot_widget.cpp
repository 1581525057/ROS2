#include "ball_lora_dashboard/plot_widget.hpp"

#include <QDateTime>
#include <QFontMetrics>
#include <QMouseEvent>
#include <QPainter>
#include <QPolygonF>
#include <QWheelEvent>

#include <algorithm>
#include <cmath>
#include <iterator>
#include <limits>

namespace ball_lora_dashboard {
namespace {

const QColor kColors[] = {
    QColor("#2563eb"), QColor("#e11d48"), QColor("#059669"), QColor("#d97706"),
    QColor("#7c3aed"), QColor("#0891b2"), QColor("#be185d"), QColor("#4d7c0f")};

}  // namespace

PlotWidget::PlotWidget(QWidget* parent) : QWidget(parent) {
  setMinimumSize(500, 350);
  setMouseTracking(true);
  setFocusPolicy(Qt::StrongFocus);
  redraw_timer_.setInterval(16);
  connect(&redraw_timer_, &QTimer::timeout, this, [this] { renderTick(); });
  tick_clock_.start();
  redraw_timer_.start();
}

void PlotWidget::requestFrame() { dirty_ = true; }

void PlotWidget::renderTick() {
  const qint64 elapsed = tick_clock_.restart();
  if (follow_live_ && !samples_.empty()) {
    const double target = static_cast<double>(samples_.back().timestamp_ms);
    if (target - display_right_ > 1.0) {
      const double alpha = 1.0 - std::exp(-std::max<qint64>(1, elapsed) / 70.0);
      display_right_ += (target - display_right_) * alpha;
      requestFrame();
    } else if (display_right_ != target) {
      display_right_ = target;
      requestFrame();
    }
  }
  if (dirty_) {
    update();
    dirty_ = false;
  }
}

void PlotWidget::addSample(const std::vector<float>& values, qint64 timestamp_ms) {
  if (timestamp_ms < 0) timestamp_ms = QDateTime::currentMSecsSinceEpoch();
  if (!samples_.empty()) timestamp_ms = std::max(timestamp_ms, samples_.back().timestamp_ms);
  samples_.push_back({next_id_++, timestamp_ms, values});
  while (!samples_.empty() &&
         timestamp_ms - samples_.front().timestamp_ms > kHistoryDurationMs) {
    samples_.pop_front();
  }
  if (samples_.size() == 1 ||
      display_right_ < static_cast<double>(samples_.front().timestamp_ms)) {
    display_right_ = static_cast<double>(timestamp_ms);
  }
  if (!follow_live_ && manual_left_ < static_cast<double>(samples_.front().timestamp_ms)) {
    const double span = manual_right_ - manual_left_;
    setManualRange(static_cast<double>(samples_.front().timestamp_ms),
                   static_cast<double>(samples_.front().timestamp_ms) + span);
  }
  emit timelineChanged();
  requestFrame();
}

void PlotWidget::expireBefore(qint64 cutoff_ms) {
  if (samples_.empty() || samples_.front().timestamp_ms >= cutoff_ms) return;
  while (!samples_.empty() && samples_.front().timestamp_ms < cutoff_ms) {
    samples_.pop_front();
  }
  if (samples_.empty()) {
    display_right_ = 0.0;
    follow_live_ = true;
    drag_mode_ = DragMode::None;
    hovering_ = false;
    emit followModeChanged(true);
  } else if (!follow_live_ && manual_left_ < samples_.front().timestamp_ms) {
    const double span = manual_right_ - manual_left_;
    setManualRange(samples_.front().timestamp_ms,
                   samples_.front().timestamp_ms + span);
  }
  emit timelineChanged();
  requestFrame();
}

void PlotWidget::setSelectedChannels(std::vector<int> channels) {
  if (channels.size() > 8) channels.resize(8);
  if (channels == selected_channels_) return;
  selected_channels_ = std::move(channels);
  requestFrame();
}

void PlotWidget::clear() {
  samples_.clear();
  selected_channels_.clear();
  next_id_ = 0;
  display_right_ = 0.0;
  manual_left_ = 0.0;
  manual_right_ = 0.0;
  follow_live_ = true;
  drag_mode_ = DragMode::None;
  hovering_ = false;
  emit followModeChanged(true);
  emit timelineChanged();
  requestFrame();
}

QRectF PlotWidget::plotRect() const {
  return QRectF(95, 65, std::max(1, width() - 125), std::max(1, height() - 160));
}

std::pair<double, double> PlotWidget::visibleRange() const {
  if (samples_.empty()) return {0.0, static_cast<double>(kLiveWindowMs)};
  if (!follow_live_) return {manual_left_, manual_right_};
  const double right = std::max(display_right_,
      static_cast<double>(samples_.front().timestamp_ms + kLiveWindowMs));
  return {right - kLiveWindowMs, right};
}

qint64 PlotWidget::oldestTimestampMs() const {
  return samples_.empty() ? 0 : samples_.front().timestamp_ms;
}

qint64 PlotWidget::latestTimestampMs() const {
  return samples_.empty() ? 0 : samples_.back().timestamp_ms;
}

void PlotWidget::setManualRange(double left, double right) {
  if (samples_.empty()) return;
  const double oldest = static_cast<double>(samples_.front().timestamp_ms);
  const double newest = static_cast<double>(samples_.back().timestamp_ms);
  const double max_span = std::max(1000.0, newest - oldest);
  const double span = std::clamp(right - left, 1000.0, max_span);
  left = std::clamp(left, oldest, std::max(oldest, newest - span));
  manual_left_ = left;
  manual_right_ = left + span;
  if (follow_live_) {
    follow_live_ = false;
    emit followModeChanged(false);
  }
  emit timelineChanged();
  requestFrame();
}

void PlotWidget::seekToTime(qint64 right_ms) {
  if (samples_.empty()) return;
  if (right_ms >= latestTimestampMs()) {
    resetView();
    return;
  }
  const auto [left, right] = visibleRange();
  const double span = right - left;
  setManualRange(static_cast<double>(right_ms) - span, static_cast<double>(right_ms));
}

void PlotWidget::zoomAround(double anchor, double factor) {
  const auto [left, right] = visibleRange();
  setManualRange(anchor - (anchor - left) * factor,
                 anchor + (right - anchor) * factor);
}

void PlotWidget::zoomIn() {
  if (samples_.empty()) return;
  const auto [left, right] = visibleRange();
  zoomAround((left + right) / 2.0, 0.75);
}

void PlotWidget::zoomOut() {
  if (samples_.empty()) return;
  const auto [left, right] = visibleRange();
  zoomAround((left + right) / 2.0, 1.5);
}

void PlotWidget::resetView() {
  if (!follow_live_) {
    follow_live_ = true;
    if (!samples_.empty()) display_right_ = static_cast<double>(samples_.back().timestamp_ms);
    emit followModeChanged(true);
    emit timelineChanged();
    requestFrame();
  }
}

void PlotWidget::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.fillRect(rect(), QColor("#ffffff"));
  const QRectF plot = plotRect();
  const auto [left, right] = visibleRange();

  painter.setPen(QColor("#334155"));
  QFont heading = painter.font();
  heading.setPointSize(13);
  heading.setBold(true);
  painter.setFont(heading);
  painter.drawText(QRectF(20, 12, width() - 40, 30),
                   follow_live_ ? QStringLiteral("实时曲线 · 自动跟随")
                                : QStringLiteral("历史曲线 · 回到实时可继续跟随"));
  QFont axis_font = painter.font();
  axis_font.setPointSize(9);
  axis_font.setBold(false);
  painter.setFont(axis_font);

  if (samples_.empty() || selected_channels_.empty()) {
    painter.setPen(QColor("#64748b"));
    QFont body = painter.font();
    body.setBold(false);
    body.setPointSize(11);
    painter.setFont(body);
    painter.drawText(plot, Qt::AlignCenter,
                     samples_.empty() ? QStringLiteral("等待单片机数据…")
                                      : QStringLiteral("在左侧勾选要绘制的通道"));
    return;
  }

  const auto visible_begin = std::lower_bound(samples_.begin(), samples_.end(), left,
      [](const Sample& sample, double time) { return sample.timestamp_ms < time; });
  const auto visible_end = std::upper_bound(visible_begin, samples_.end(), right,
      [](double time, const Sample& sample) { return time < sample.timestamp_ms; });
  double minimum = std::numeric_limits<double>::infinity();
  double maximum = -std::numeric_limits<double>::infinity();
  {
    for (auto it = visible_begin; it != visible_end; ++it) {
      const auto& sample = *it;
      for (const int channel : selected_channels_) {
        if (channel < 0 || static_cast<std::size_t>(channel) >= sample.values.size()) continue;
        const double value = sample.values[channel];
        if (!std::isfinite(value)) continue;
        minimum = std::min(minimum, value);
        maximum = std::max(maximum, value);
      }
    }
  }
  const bool has_visible_values = std::isfinite(minimum);
  if (!has_visible_values) {
    minimum = -1.0;
    maximum = 1.0;
  }
  const double padding = std::max(0.05, (maximum - minimum) * 0.12);
  minimum -= padding;
  maximum += padding;

  painter.setPen(QPen(QColor("#e2e8f0"), 1));
  for (int i = 0; i <= 4; ++i) {
    const double y = plot.top() + plot.height() * i / 4.0;
    painter.drawLine(QPointF(plot.left(), y), QPointF(plot.right(), y));
    painter.setPen(QColor("#64748b"));
    double tick = maximum - (maximum - minimum) * i / 4.0;
    if (std::abs(tick) < (maximum - minimum) * 0.001) tick = 0.0;
    painter.drawText(QRectF(4, y - 9, 82, 18), Qt::AlignRight | Qt::AlignVCenter,
                     QString::number(tick, 'g', 4));
    painter.setPen(QPen(QColor("#e2e8f0"), 1));
  }
  const double span = std::max(1.0, right - left);
  const QDateTime first_date = QDateTime::fromMSecsSinceEpoch(
      static_cast<qint64>(std::llround(left)));
  const QDateTime last_date = QDateTime::fromMSecsSinceEpoch(
      static_cast<qint64>(std::llround(right)));
  const bool same_day = first_date.date() == last_date.date();
  const bool show_milliseconds = span < 5000;
  const qint64 tick_options[] = {100, 200, 500, 1000, 2000, 5000, 10000,
                                 15000, 30000, 60000, 120000, 300000};
  const double desired_interval = span / (show_milliseconds || !same_day ? 3.0 : 5.0);
  qint64 tick_interval = tick_options[std::size(tick_options) - 1];
  for (const qint64 option : tick_options) {
    if (option >= desired_interval) {
      tick_interval = option;
      break;
    }
  }
  const QString time_format = !same_day ? QStringLiteral("MM-dd HH:mm:ss")
      : show_milliseconds ? QStringLiteral("HH:mm:ss.zzz")
                          : QStringLiteral("HH:mm:ss");
  const qint64 first_tick = static_cast<qint64>(std::ceil(left / tick_interval)) *
                            tick_interval;
  for (qint64 tick = first_tick; tick <= right; tick += tick_interval) {
    const double x = plot.left() + plot.width() * (tick - left) / span;
    painter.setPen(QPen(QColor("#e2e8f0"), 1));
    painter.drawLine(QPointF(x, plot.top()), QPointF(x, plot.bottom()));
    const QString label = QDateTime::fromMSecsSinceEpoch(tick).toString(time_format);
    const int text_width = QFontMetrics(painter.font()).horizontalAdvance(label) + 8;
    const double text_left = std::clamp(x - text_width / 2.0, 2.0,
                                        std::max(2.0, width() - text_width - 2.0));
    painter.setPen(QColor("#64748b"));
    painter.drawText(QRectF(text_left, plot.bottom() + 7, text_width, 19),
                     Qt::AlignCenter, label);
  }
  painter.setPen(QColor("#94a3b8"));
  painter.drawText(QRectF(plot.left(), 44, plot.width(), 17),
                   Qt::AlignRight,
                   same_day ? QStringLiteral("时间 · %1").arg(first_date.toString("yyyy-MM-dd"))
                            : QStringLiteral("时间（本地）"));

  if (!has_visible_values) {
    painter.setPen(QColor("#64748b"));
    painter.drawText(plot, Qt::AlignCenter, QStringLiteral("当前时间范围暂无数据"));
    return;
  }

  painter.save();
  painter.setClipRect(plot.adjusted(-2, -2, 2, 2));
  for (std::size_t series = 0; series < selected_channels_.size(); ++series) {
    const int channel = selected_channels_[series];
    painter.setPen(QPen(kColors[selected_channels_[series] % 8], 2.2));
    QPolygonF segment;
    {
      for (auto it = visible_begin; it != visible_end; ++it) {
        const auto& sample = *it;
        if (channel < 0 || static_cast<std::size_t>(channel) >= sample.values.size() ||
            !std::isfinite(sample.values[channel])) {
          if (segment.size() > 1) painter.drawPolyline(segment);
          segment.clear();
          continue;
        }
        const double x = plot.left() + plot.width() *
            (sample.timestamp_ms - left) / span;
        const double y = plot.bottom() - plot.height() *
            (sample.values[channel] - minimum) / (maximum - minimum);
        segment.append(QPointF(x, y));
      }
    }
    if (segment.size() > 1) painter.drawPolyline(segment);
    if (segment.size() == 1) painter.drawEllipse(segment.first(), 2.5, 2.5);
  }
  painter.restore();

  QFont legend_font = painter.font();
  legend_font.setPointSize(9);
  legend_font.setBold(false);
  painter.setFont(legend_font);
  for (std::size_t i = 0; i < selected_channels_.size(); ++i) {
    const int column = static_cast<int>(i % 4);
    const int row = static_cast<int>(i / 4);
    const int x = static_cast<int>(plot.left()) + column * 115;
    const int y = height() - 48 + row * 17;
    painter.setPen(QPen(kColors[selected_channels_[i] % 8], 3));
    painter.drawLine(x, y, x + 18, y);
    painter.setPen(QColor("#334155"));
    painter.drawText(x + 24, y + 4, QStringLiteral("num%1").arg(selected_channels_[i] + 1));
  }

  if (hovering_ && drag_mode_ == DragMode::None && plot.contains(hover_pos_)) {
    const double position = left +
        (hover_pos_.x() - plot.left()) / plot.width() * span;
    auto nearest = std::lower_bound(visible_begin, visible_end, position,
        [](const Sample& sample, double time) { return sample.timestamp_ms < time; });
    if (nearest == visible_end) nearest = visible_end - 1;
    else if (nearest != visible_begin &&
             position - (nearest - 1)->timestamp_ms < nearest->timestamp_ms - position) {
      --nearest;
    }
    const auto& sample = *nearest;
    const double cross_x = plot.left() + plot.width() *
        (sample.timestamp_ms - left) / span;
    painter.setPen(QPen(QColor("#64748b"), 1, Qt::DashLine));
    painter.drawLine(QPointF(cross_x, plot.top()), QPointF(cross_x, plot.bottom()));
    for (std::size_t series = 0; series < selected_channels_.size(); ++series) {
      const int channel = selected_channels_[series];
      if (channel < 0 || static_cast<std::size_t>(channel) >= sample.values.size() ||
          !std::isfinite(sample.values[channel])) continue;
      const double y = plot.bottom() - plot.height() *
          (sample.values[channel] - minimum) / (maximum - minimum);
      painter.setPen(QPen(Qt::white, 2));
      painter.setBrush(kColors[selected_channels_[series] % 8]);
      painter.drawEllipse(QPointF(cross_x, y), 5, 5);
    }
    painter.setBrush(Qt::NoBrush);

    const int rows = static_cast<int>(selected_channels_.size());
    const QRectF box(
        std::min<double>(hover_pos_.x() + 15, plot.right() - 190),
        std::min<double>(hover_pos_.y() + 15, plot.bottom() - (42 + rows * 19)),
        185, 38 + rows * 19);
    painter.setPen(QPen(QColor("#cbd5e1"), 1));
    painter.setBrush(QColor(255, 255, 255, 245));
    painter.drawRoundedRect(box, 7, 7);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QColor("#334155"));
    painter.drawText(QRectF(box.left() + 10, box.top() + 6, box.width() - 20, 20),
                     QStringLiteral("第 %1 帧 · %2")
                         .arg(static_cast<qulonglong>(sample.id + 1))
                         .arg(QDateTime::fromMSecsSinceEpoch(sample.timestamp_ms)
                                  .toString("HH:mm:ss.zzz")));
    for (int i = 0; i < rows; ++i) {
      const int channel = selected_channels_[i];
      painter.setPen(kColors[selected_channels_[i] % 8]);
      const QString value = channel >= 0 &&
          static_cast<std::size_t>(channel) < sample.values.size()
          ? QString::number(sample.values[channel], 'g', 7) : QStringLiteral("—");
      painter.drawText(QRectF(box.left() + 10, box.top() + 26 + i * 19,
                              box.width() - 20, 18),
                       QStringLiteral("num%1  %2").arg(channel + 1).arg(value));
    }
  }

  if (drag_mode_ == DragMode::Select) {
    const double a = std::clamp<double>(drag_start_.x(), plot.left(), plot.right());
    const double b = std::clamp<double>(drag_current_.x(), plot.left(), plot.right());
    const QRectF selection(std::min(a, b), plot.top(), std::abs(a - b), plot.height());
    painter.fillRect(selection, QColor(37, 99, 235, 35));
    painter.setPen(QPen(QColor("#2563eb"), 1, Qt::DashLine));
    painter.drawRect(selection);
  }
}

void PlotWidget::mousePressEvent(QMouseEvent* event) {
  const QRectF plot = plotRect();
  if (event->button() == Qt::LeftButton) {
    for (std::size_t i = 0; i < selected_channels_.size(); ++i) {
      const int x = static_cast<int>(plot.left()) + static_cast<int>(i % 4) * 115;
      const int y = height() - 48 + static_cast<int>(i / 4) * 17;
      if (QRectF(x - 5, y - 14, 105, 20).contains(event->pos())) {
        emit channelToggled(selected_channels_[i]);
        event->accept();
        return;
      }
    }
  }
  if (!samples_.empty() && plot.contains(event->pos())) {
    if (event->button() == Qt::LeftButton) drag_mode_ = DragMode::Select;
    if (event->button() == Qt::RightButton) drag_mode_ = DragMode::Pan;
    drag_start_ = drag_current_ = event->pos();
    if (drag_mode_ == DragMode::Pan) setCursor(Qt::ClosedHandCursor);
    requestFrame();
    event->accept();
    return;
  }
  QWidget::mousePressEvent(event);
}

void PlotWidget::mouseMoveEvent(QMouseEvent* event) {
  const QRectF plot = plotRect();
  hovering_ = plot.contains(event->pos());
  hover_pos_ = event->pos();
  if (drag_mode_ == DragMode::Pan) {
    const auto [left, right] = visibleRange();
    const double shift = (drag_current_.x() - event->pos().x()) /
        plot.width() * (right - left);
    setManualRange(left + shift, right + shift);
  }
  drag_current_ = event->pos();
  requestFrame();
  event->accept();
}

void PlotWidget::mouseReleaseEvent(QMouseEvent* event) {
  if (drag_mode_ == DragMode::Select && event->button() == Qt::LeftButton) {
    const QRectF plot = plotRect();
    const double a = std::clamp<double>(drag_start_.x(), plot.left(), plot.right());
    const double b = std::clamp<double>(event->pos().x(), plot.left(), plot.right());
    if (std::abs(a - b) >= 8) {
      const auto [left, right] = visibleRange();
      const double start = left + (std::min(a, b) - plot.left()) /
          plot.width() * (right - left);
      const double end = left + (std::max(a, b) - plot.left()) /
          plot.width() * (right - left);
      setManualRange(start, end);
    }
  }
  drag_mode_ = DragMode::None;
  unsetCursor();
  requestFrame();
  event->accept();
}

void PlotWidget::mouseDoubleClickEvent(QMouseEvent* event) {
  if (plotRect().contains(event->pos())) {
    resetView();
    event->accept();
    return;
  }
  QWidget::mouseDoubleClickEvent(event);
}

void PlotWidget::wheelEvent(QWheelEvent* event) {
  if (samples_.empty() || !plotRect().contains(event->position())) {
    QWidget::wheelEvent(event);
    return;
  }
  const QRectF plot = plotRect();
  const auto [left, right] = visibleRange();
  const double anchor = left + (event->position().x() - plot.left()) /
      plot.width() * (right - left);
  zoomAround(anchor, std::pow(0.8, event->angleDelta().y() / 120.0));
  event->accept();
}

void PlotWidget::leaveEvent(QEvent* event) {
  hovering_ = false;
  requestFrame();
  QWidget::leaveEvent(event);
}

}  // namespace ball_lora_dashboard
