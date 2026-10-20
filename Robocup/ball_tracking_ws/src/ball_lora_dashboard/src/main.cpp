#include "ball_lora_dashboard/main_window.hpp"

#include <QApplication>
#include <QString>
#include <QTimer>

int main(int argc, char* argv[]) {
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication app(argc, argv);
  ball_lora_dashboard::MainWindow window;
  const QStringList arguments = app.arguments();
  if (arguments.contains(QStringLiteral("--demo"))) window.startDemo();
  window.show();
  for (const QString& argument : arguments) {
    const QString prefix = QStringLiteral("--demo-snapshot=");
    if (argument.startsWith(prefix)) {
      if (!arguments.contains(QStringLiteral("--demo"))) window.startDemo();
      const QString path = argument.mid(prefix.size());
      QTimer::singleShot(5000, &window, [&window, &app, path] {
        app.exit(window.saveChart(path) ? 0 : 1);
      });
    }
  }
  return app.exec();
}
