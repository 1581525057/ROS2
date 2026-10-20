#include "ball_lora_dashboard/serial_port.hpp"

#include <QFile>
#include <QSocketNotifier>

#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

namespace ball_lora_dashboard {
namespace {

speed_t serialSpeed(int baud_rate) {
  switch (baud_rate) {
    case 9600: return B9600;
    case 19200: return B19200;
    case 38400: return B38400;
    case 57600: return B57600;
    case 115200: return B115200;
    default: return 0;
  }
}

QString systemError(const QString& action) {
  return action + QStringLiteral(": ") + QString::fromLocal8Bit(std::strerror(errno));
}

}  // namespace

SerialPort::SerialPort(QObject* parent) : QObject(parent) {}

SerialPort::~SerialPort() { closePort(); }

bool SerialPort::openPort(const QString& path, int baud_rate, QString* error) {
  closePort();
  const speed_t speed = serialSpeed(baud_rate);
  if (path.isEmpty() || speed == 0) {
    if (error) *error = QStringLiteral("串口路径为空或波特率不支持");
    return false;
  }

  const QByteArray native_path = QFile::encodeName(path);
  const int fd = ::open(native_path.constData(), O_RDWR | O_NOCTTY | O_NONBLOCK | O_CLOEXEC);
  if (fd < 0) {
    if (error) *error = systemError(QStringLiteral("打开串口失败"));
    return false;
  }

  termios settings{};
  if (tcgetattr(fd, &settings) != 0) {
    if (error) *error = systemError(QStringLiteral("读取串口设置失败"));
    ::close(fd);
    return false;
  }
  cfmakeraw(&settings);
  settings.c_cflag |= CLOCAL | CREAD;
  settings.c_cflag &= ~CSIZE;
  settings.c_cflag |= CS8;
  settings.c_cflag &= ~(PARENB | CSTOPB | CRTSCTS);
  settings.c_iflag &= ~(IXON | IXOFF | IXANY);
  settings.c_cc[VMIN] = 0;
  settings.c_cc[VTIME] = 0;
  if (cfsetispeed(&settings, speed) != 0 || cfsetospeed(&settings, speed) != 0 ||
      tcsetattr(fd, TCSANOW, &settings) != 0) {
    if (error) *error = systemError(QStringLiteral("设置串口失败"));
    ::close(fd);
    return false;
  }

  fd_ = fd;
  read_notifier_ = new QSocketNotifier(fd_, QSocketNotifier::Read, this);
  write_notifier_ = new QSocketNotifier(fd_, QSocketNotifier::Write, this);
  write_notifier_->setEnabled(false);
  connect(read_notifier_, &QSocketNotifier::activated, this, [this] { readAvailable(); });
  connect(write_notifier_, &QSocketNotifier::activated, this, [this] { flushWrites(); });
  return true;
}

void SerialPort::closePort() {
  if (read_notifier_) {
    read_notifier_->setEnabled(false);
    read_notifier_->deleteLater();
    read_notifier_ = nullptr;
  }
  if (write_notifier_) {
    write_notifier_->setEnabled(false);
    write_notifier_->deleteLater();
    write_notifier_ = nullptr;
  }
  if (fd_ >= 0) {
    ::close(fd_);
    fd_ = -1;
  }
  pending_write_.clear();
}

void SerialPort::fail(const QString& message) {
  closePort();
  emit errorOccurred(message);
}

void SerialPort::readAvailable() {
  char buffer[4096];
  while (fd_ >= 0) {
    const ssize_t count = ::read(fd_, buffer, sizeof(buffer));
    if (count > 0) {
      emit bytesReceived(QByteArray(buffer, static_cast<int>(count)));
      continue;
    }
    if (count == 0 || errno == EAGAIN || errno == EWOULDBLOCK) return;
    if (errno == EINTR) continue;
    fail(systemError(QStringLiteral("串口读取失败")));
    return;
  }
}

void SerialPort::send(const QByteArray& bytes) {
  if (fd_ < 0 || bytes.isEmpty()) return;
  pending_write_.append(bytes);
  flushWrites();
}

void SerialPort::flushWrites() {
  while (fd_ >= 0 && !pending_write_.isEmpty()) {
    const ssize_t count = ::write(fd_, pending_write_.constData(), pending_write_.size());
    if (count > 0) {
      pending_write_.remove(0, static_cast<int>(count));
      continue;
    }
    if (count == 0 || errno == EAGAIN || errno == EWOULDBLOCK) break;
    if (errno == EINTR) continue;
    fail(systemError(QStringLiteral("串口发送失败")));
    return;
  }
  if (write_notifier_) write_notifier_->setEnabled(!pending_write_.isEmpty());
}

}  // namespace ball_lora_dashboard
