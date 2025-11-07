#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

void Car::initCar(string mark, string color, string typeOfkuzov, double engineCapicity, int probeg) {
    this->mark = mark;
    this->color = color;
    this->typeOfkuzov = typeOfkuzov;
    this->engineCapacity = engineCapacity;
    this->probeg = probeg;
}

double Car::countAvergeFuelConsumption(double distance) {
    return engineCapacity / distance * 100;
}

void Car::scrutit_probeg(int scrutka) {
    probeg -= scrutka;
    cout << "Пробег скручен, теперь он " << probeg << "км" << endl;
}

void Car::printInfo() {
    cout << "Марка: " << mark << ", цвет: " << color << ", тип кузова: "
    << typeOfkuzov << ", объём двигателя: " << engineCapacity << ", пробег: " << probeg << "км" << endl;
}

