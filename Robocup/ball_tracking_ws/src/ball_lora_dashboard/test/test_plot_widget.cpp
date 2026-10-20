#include "ball_lora_dashboard/plot_widget.hpp"

#include <QApplication>
#include <QCoreApplication>
#include <QSignalSpy>
#include <QTest>
#include <QWheelEvent>

#include <cmath>
#include <iostream>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  ball_lora_dashboard::PlotWidget plot;
  plot.resize(900, 500);
  plot.show();
  plot.setSelectedChannels({0, 1});
  const qint64 base_time = 1700000000000LL;
  for (int i = 0; i < 500; ++i) {
    plot.addSample({static_cast<float>(std::sin(i * 0.03)),
                    static_cast<float>(std::cos(i * 0.02))}, base_time + i * 50);
  }
  QTest::qWait(150);
  const auto live = plot.visibleRange();
  if (!plot.isFollowingLive() ||
      std::abs((live.second - live.first) - 15000.0) > 1.0) return 1;

  plot.zoomIn();
  const auto zoomed = plot.visibleRange();
  if (plot.isFollowingLive() || zoomed.second - zoomed.first >= live.second - live.first) {
    std::cerr << "Zoom in failed\n";
    return 1;
  }
  plot.zoomOut();
  if (plot.visibleRange().second - plot.visibleRange().first <=
      zoomed.second - zoomed.first) return 1;

  plot.resetView();
  if (!plot.isFollowingLive()) return 1;
  QWheelEvent wheel(QPointF(400, 230), QPointF(400, 230), QPoint(), QPoint(0, 120),
                    Qt::NoButton, Qt::NoModifier, Qt::NoScrollPhase, false);
  QCoreApplication::sendEvent(&plot, &wheel);
  if (plot.isFollowingLive()) {
    std::cerr << "Mouse wheel zoom failed\n";
    return 1;
  }

  plot.resetView();
  QTest::mousePress(&plot, Qt::LeftButton, Qt::NoModifier, QPoint(250, 220));
  QTest::mouseMove(&plot, QPoint(550, 220));
  QTest::mouseRelease(&plot, Qt::LeftButton, Qt::NoModifier, QPoint(550, 220));
  if (plot.isFollowingLive()) {
    std::cerr << "Drag selection zoom failed\n";
    return 1;
  }
  QTest::mouseDClick(&plot, Qt::LeftButton, Qt::NoModifier, QPoint(400, 220));
  if (!plot.isFollowingLive()) return 1;

  QSignalSpy toggles(&plot, &ball_lora_dashboard::PlotWidget::channelToggled);
  QTest::mouseClick(&plot, Qt::LeftButton, Qt::NoModifier,
                    QPoint(95, plot.height() - 48));
  if (toggles.count() != 1 || toggles[0][0].toInt() != 0) {
    std::cerr << "Legend click failed\n";
    return 1;
  }

  plot.clear();
  plot.setSelectedChannels({0});
  for (int i = 0; i <= 305; ++i) plot.addSample({static_cast<float>(i)}, base_time + i * 1000);
  if (plot.oldestTimestampMs() != base_time + 5000 ||
      plot.latestTimestampMs() != base_time + 305000) {
    std::cerr << "Five-minute history retention failed\n";
    return 1;
  }
  plot.seekToTime(base_time + 165000);
  if (plot.isFollowingLive() ||
      std::abs(plot.visibleRange().second - (base_time + 165000.0)) > 1.0) {
    std::cerr << "Timeline seek failed\n";
    return 1;
  }
  plot.resetView();
  if (!plot.isFollowingLive()) return 1;
  plot.expireBefore(base_time + 305001);
  if (plot.oldestTimestampMs() != 0 || plot.latestTimestampMs() != 0) {
    std::cerr << "Expired history was still retained\n";
    return 1;
  }
  return 0;
}
