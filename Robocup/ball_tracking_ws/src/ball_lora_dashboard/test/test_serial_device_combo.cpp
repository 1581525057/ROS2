#include "ball_lora_dashboard/serial_device_combo.hpp"

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QTemporaryDir>

#include <iostream>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QTemporaryDir temp;
  if (!temp.isValid()) return 1;
  const QDir root(temp.path());
  if (!root.mkpath(QStringLiteral("serial/by-id"))) return 1;
  const QString usb = root.filePath(QStringLiteral("ttyUSB0"));
  const QString acm = root.filePath(QStringLiteral("ttyACM1"));
  const QString stable = root.filePath(QStringLiteral("serial/by-id/lora-radio"));
  QFile usb_file(usb);
  QFile acm_file(acm);
  if (!usb_file.open(QIODevice::WriteOnly) || !acm_file.open(QIODevice::WriteOnly)) return 1;
  usb_file.close();
  acm_file.close();
  if (!QFile::link(usb, stable)) return 1;

  ball_lora_dashboard::SerialDeviceComboBox combo(nullptr, temp.path());
  if (combo.count() != 3 || combo.itemText(0) != stable ||
      combo.findText(usb) < 0 || combo.findText(acm) < 0) {
    std::cerr << "Serial devices were not listed correctly\n";
    return 1;
  }

  const QString custom = QStringLiteral("/dev/serial/by-id/my-custom-device");
  combo.setEditText(custom);
  if (!QFile::remove(acm)) return 1;
  combo.refreshDevices();
  if (combo.currentText() != custom || combo.findText(acm) >= 0 || combo.count() != 2) {
    std::cerr << "Refresh changed the entered path or kept a removed device\n";
    return 1;
  }

  if (!QFile::remove(stable) || !QFile::remove(usb)) return 1;
  combo.refreshDevices();
  if (combo.currentText() != custom || combo.count() != 1 ||
      combo.model()->index(0, 0).flags().testFlag(Qt::ItemIsEnabled)) {
    std::cerr << "Empty device list is not shown correctly\n";
    return 1;
  }
  return 0;
}
