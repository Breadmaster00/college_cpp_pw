#include "OfficeDevice.h"

OfficeDevice::OfficeDevice(const string& name, double price, const string& brand)
    : name(name), price(price), brand(brand) {}

OfficeDevice::~OfficeDevice() = default;

const string OfficeDevice::getName() { return name; }
const double OfficeDevice::getPrice() { return price; }
const string OfficeDevice::getBrand() { return brand; }
