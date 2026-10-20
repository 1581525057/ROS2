#pragma once

#include <QObject>
#include <QByteArray>
#include <QString>

class QSocketNotifier;

namespace ball_lora_dashboard {

class SerialPort : public QObject {
  Q_OBJECT

 public:
  explicit SerialPort(QObject* parent = nullptr);
  ~SerialPort() override;

  bool openPort(const QString& path, int baud_rate, QString* error);
  void closePort();
  bool isOpen() const { return fd_ >= 0; }
  void send(const QByteArray& bytes);

 signals:
  void bytesReceived(const QByteArray& bytes);
  void errorOccurred(const QString& message);

 private:
  void readAvailable();
  void flushWrites();
  void fail(const QString& message);

  int fd_ = -1;
  QSocketNotifier* read_notifier_ = nullptr;
  QSocketNotifier* write_notifier_ = nullptr;
  QByteArray pending_write_;
};

}  // namespace ball_lora_dashboard
