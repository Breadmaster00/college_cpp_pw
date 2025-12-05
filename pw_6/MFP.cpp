#include "MFP.h"
#include <iostream>


MFP::MFP(const string& name, double price, const string& brand, int speed, bool color, int res, bool feed, bool wifi)
    : OfficeDevice(name, price, brand),
      Printer(name, price, brand, speed, color),
      Scanner(name, price, brand, res, feed),
      wifiSupported(wifi) {}

MFP::~MFP() = default;

 const bool MFP::isWifiSupported() { return wifiSupported; }

const void MFP::showDetails() {
    cout << "Название: " << name << "\n"
            << "Бренд: " << brand << "\n"
            << "Цена: " << price << " руб.\n\n"
            << "Скорость печати: " << printSpeed << " стр/мин\n"
            << "Цветная печать: " << (colorPrint ? "Да" : "Нет") << endl
            << "Разрешение: " << resolution << " DPI\n"
            << "Автоподача: " << (autoFeed ? "Да" : "Нет") << endl
            << "Поддержка Wi-Fi: " << (wifiSupported ? "Есть" : "Нет") << "\n";
}
