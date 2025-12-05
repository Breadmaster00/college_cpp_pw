#pragma once

#include <string>

using namespace std;

class OfficeDevice {
protected:
    string name;
    double price;
    string brand;

public:
    OfficeDevice(const string& name, double price, const string& brand);
    virtual ~OfficeDevice();

    // геттеры
    const string getName();
    const double getPrice();
    const string getBrand();

    const virtual void showDetails() = 0;
};