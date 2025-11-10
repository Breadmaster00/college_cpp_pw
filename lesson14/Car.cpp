#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

Car::Car(string mark, string color, string typeOfkuzov, double engineCapacity, int probeg) {
    this->mark = mark;
    this->color = color;
    this->typeOfkuzov = typeOfkuzov;
    this->engineCapacity = engineCapacity;
    this->probeg = probeg;
}

Car::Car(string mark, string color, string typeOfkuzov, double engineCapacity) 
    : Car::Car(mark, color, typeOfkuzov, engineCapacity, 0) {}

Car::~Car() {
    cout << color << " " << mark << " взорвался!!" << endl;
}

// геттеры
const string Car::getMark() { return mark; }
const string Car::getColor() { return color; }
const string Car::getTypeOfkuzov() { return typeOfkuzov; }
const double Car::getEngineCapacity() { return engineCapacity; }
const int Car::getProbeg() { return probeg; }

// сеттеры
void Car::setMark(const string mark) {
    this->mark = mark;
}

void Car::setColor(const string color) {
    this->color = color;
}

void Car::setTypeOfkuzov(const string typeOfkuzov) {
    this->typeOfkuzov = typeOfkuzov;
}

void Car::setEngineCapacity(const double engineCapacity) {
    if (engineCapacity >= 0) {
        this->engineCapacity = engineCapacity;
    } else {
        cout << "Объём двигателя не может быть меньше нуля" << endl;
    }
}

void Car::setProbeg(const int probeg) {
    if (probeg >= 0) {
        this->probeg = probeg;
    } else {
        cout << "Пробег не может быть меньше нуля" << endl;
    }
}
        
// остальные мотоды
double Car::countAvergeFuelConsumption(double distance) {
    return engineCapacity / distance * 100;
}

void Car::scrutit_probeg(int scrutka) {
    probeg -= scrutka;
    cout << "Пробег скручен, теперь он " << probeg << "км" << endl;
}

const void Car::printInfo() {
    cout << "Марка: " << mark << ", цвет: " << color << ", тип кузова: "
    << typeOfkuzov << ", объём двигателя: " << engineCapacity << ", пробег: " << probeg << "км" << endl;
}

