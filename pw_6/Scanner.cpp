#include "Scanner.h"
#include <iostream>

Scanner::Scanner(const string& name, double price, const string& brand, int res, bool feed)
    : OfficeDevice(name, price, brand), resolution(res), autoFeed(feed) {}

Scanner::~Scanner() = default;

const int Scanner::getResolution() { return resolution; }
const bool Scanner::getAutoFeed() { return autoFeed; }

void Scanner::calibrate() {
    std::cout << "Сканер откалиброван.\n";
}

const void Scanner::showDetails() {
    cout << "Название: " << name << "\n" 
            << "Бренд: " << brand << "\n"
            << "Цена: " << price << " руб.\n"
            << "Разрешение: " << resolution << " DPI\n"
            << "Автоподача: " << (autoFeed ? "Да" : "Нет") << "\n";
}
