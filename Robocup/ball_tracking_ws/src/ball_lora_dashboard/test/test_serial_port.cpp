#include "ball_lora_dashboard/serial_port.hpp"

#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>

#include <pty.h>
#include <sys/select.h>
#include <unistd.h>

#include <iostream>

int main(int argc, char* argv[]) {
  QCoreApplication app(argc, argv);
  int master = -1;
  int slave = -1;
  char path[128]{};
  if (openpty(&master, &slave, path, nullptr, nullptr) != 0) return 1;
  ::close(slave);

  ball_lora_dashboard::SerialPort port;
  QString error;
  if (!port.openPort(QString::fromLocal8Bit(path), 9600, &error)) {
    std::cerr << error.toStdString() << '\n';
    ::close(master);
    return 1;
  }

  QByteArray received;
  QEventLoop loop;
  QObject::connect(&port, &ball_lora_dashboard::SerialPort::bytesReceived,
                   &loop, [&](const QByteArray& bytes) {
                     received.append(bytes);
                     loop.quit();
                   });
  QTimer::singleShot(1000, &loop, &QEventLoop::quit);
  const QByteArray input = QByteArray::fromHex("aa020000803f0000004055");
  if (::write(master, input.constData(), input.size()) != input.size()) return 1;
  loop.exec();
  if (received != input) {
    std::cerr << "Serial receive mismatch\n";
    return 1;
  }

  const QByteArray output = QByteArray::fromHex("a55a010001ff");
  port.send(output);
  fd_set read_set;
  FD_ZERO(&read_set);
  FD_SET(master, &read_set);
  timeval timeout{1, 0};
  if (::select(master + 1, &read_set, nullptr, nullptr, &timeout) != 1) {
    std::cerr << "Serial send timed out\n";
    return 1;
  }
  char buffer[32]{};
  const ssize_t count = ::read(master, buffer, sizeof(buffer));
  port.closePort();
  ::close(master);
  if (QByteArray(buffer, static_cast<int>(count)) != output) {
    std::cerr << "Serial send mismatch\n";
    return 1;
  }
  return 0;
}
