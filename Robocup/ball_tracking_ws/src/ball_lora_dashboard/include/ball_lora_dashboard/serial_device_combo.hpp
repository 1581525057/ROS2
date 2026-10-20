#pragma once

#include <QComboBox>
#include <QStringList>

namespace ball_lora_dashboard {

QStringList discoverSerialDevices(const QString& deviceRoot = QStringLiteral("/dev"));

class SerialDeviceComboBox : public QComboBox {
 public:
  explicit SerialDeviceComboBox(QWidget* parent = nullptr,
                                const QString& deviceRoot = QStringLiteral("/dev"));

  void refreshDevices();

 protected:
  void showPopup() override;

 private:
  QString device_root_;
};

}  // namespace ball_lora_dashboard
