#include <iostream>
#include <string.h>
#include "Car.h"
#include "Validate.h"

using namespace std;
using namespace validate;

Car::Car(string mark, string color, string typeOfkuzov, double engineCapacity, int probeg) {
    if (isCorrectAlpha(mark)) this->mark = mark;
    else this->mark = "непонятная";

    if (isCorrectAlpha(color)) this->color = color;
    else this->color = "серая";

    if (isCorrectAlpha(typeOfkuzov)) this->typeOfkuzov = typeOfkuzov;
    else this->typeOfkuzov = "классический";

    if (isCorrectCount(engineCapacity)) this->engineCapacity = engineCapacity;
    else this->engineCapacity = 0;

    if (isCorrectCount(probeg)) this->probeg = probeg;
    else this->probeg = 0;
}

Car::Car(string mark, string color, string typeOfkuzov, double engineCapacity) 
    : Car(mark, color, typeOfkuzov, engineCapacity, 0) {}

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
    if (isCorrectAlpha(mark)) this->mark = mark;
    else cout << "Введите коректное название марки" << endl;
}

void Car::setColor(const string color) {
    if (isCorrectAlpha(color)) this->color = color;
    else cout << "Введите коректное название цвета" << endl;
}

void Car::setTypeOfkuzov(const string typeOfkuzov) {
    if (isCorrectAlpha(typeOfkuzov)) this->typeOfkuzov = typeOfkuzov;
    else cout << "Введите коректное название кузова" << endl;
}

void Car::setEngineCapacity(const double engineCapacity) {
    if (isCorrectCount(engineCapacity)) {
        this->engineCapacity = engineCapacity;
    } else {
        this->engineCapacity = 0;
    }
}

void Car::setProbeg(const int probeg) {
    if (isCorrectCount(probeg)) {
        this->probeg = probeg;
    } else {
        this->probeg = 0;
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

// перегрузка операторов
Car& Car::operator++() {
    probeg += 10000;
    return *this;
}
Car Car::operator++(int) {
    Car obj(*this);
    ++*this;
    return obj;
}

Car& Car::operator--() {
    probeg -= 10000;
    return *this;
}
Car Car::operator--(int) {
    Car obj(*this);
    --*this;
    return obj;
}

bool Car::operator<(Car other) {
    return engineCapacity < other.engineCapacity;
}
bool Car::operator>(Car other) {
    return engineCapacity > other.engineCapacity;
}
bool Car::operator==(Car other) {
    return engineCapacity == other.engineCapacity;
}

