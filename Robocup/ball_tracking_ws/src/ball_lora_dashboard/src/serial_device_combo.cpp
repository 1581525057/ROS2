#include "ball_lora_dashboard/serial_device_combo.hpp"

#include <QDir>
#include <QFileInfo>
#include <QLineEdit>
#include <QSignalBlocker>
#include <QStandardItemModel>

namespace ball_lora_dashboard {

QStringList discoverSerialDevices(const QString& deviceRoot) {
  QStringList devices;
  const QDir root(deviceRoot);
  const QDir by_id(root.filePath(QStringLiteral("serial/by-id")));
  for (const QString& name : by_id.entryList(QDir::AllEntries | QDir::System |
                                                  QDir::NoDotAndDotDot, QDir::Name)) {
    const QString path = by_id.filePath(name);
    if (QFileInfo(path).exists()) devices.append(path);
  }

  for (const QString& name : root.entryList({QStringLiteral("ttyUSB*"),
                                              QStringLiteral("ttyACM*")},
                                             QDir::AllEntries | QDir::System |
                                                 QDir::NoDotAndDotDot, QDir::Name)) {
    const QString path = root.filePath(name);
    if (QFileInfo(path).exists() && !devices.contains(path)) devices.append(path);
  }
  return devices;
}

SerialDeviceComboBox::SerialDeviceComboBox(QWidget* parent, const QString& deviceRoot)
    : QComboBox(parent), device_root_(deviceRoot) {
  setEditable(true);
  setInsertPolicy(QComboBox::NoInsert);
  lineEdit()->setPlaceholderText(QStringLiteral("选择串口或输入设备路径"));
  refreshDevices();
}

void SerialDeviceComboBox::refreshDevices() {
  const QString entered_path = currentText();
  const QSignalBlocker blocker(this);
  clear();
  const QStringList devices = discoverSerialDevices(device_root_);
  if (devices.isEmpty()) {
    addItem(QStringLiteral("未发现串口，可手动输入路径"));
    if (auto* item = qobject_cast<QStandardItemModel*>(model())->item(0)) {
      item->setEnabled(false);
    }
  } else {
    for (const QString& path : devices) addItem(path);
  }
  setCurrentIndex(-1);
  lineEdit()->setText(entered_path);
}

void SerialDeviceComboBox::showPopup() {
  refreshDevices();
  QComboBox::showPopup();
}

}  // namespace ball_lora_dashboard
