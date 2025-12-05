#include "Printer.h"
#include <iostream>

Printer::Printer(const string& name, double price, const string& brand, int speed, bool color)
    : OfficeDevice(name, price, brand), printSpeed(speed), colorPrint(color) {}

Printer::~Printer() = default;

const int Printer::getPrintSpeed() { return printSpeed; }
const bool Printer::getColorPrint() { return printSpeed; };

void Printer::replaceCartridge() {
    cout << "Картридж заменён.\n";
}

const void Printer::showDetails() {
    cout << "Название: " << name << "\n"
              << "Бренд: " << brand << "\n"
              << "Цена: " << price << " руб.\n"
              << "Скорость печати: " << printSpeed << " стр/мин\n"
              << "Цветная печать: " << (colorPrint ? "Да" : "Нет") << "\n";
}
