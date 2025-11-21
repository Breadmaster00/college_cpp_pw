#include <windows.h>
#include "Pet.h"
#include <iostream>

Pet::Pet(string name, string species, string color, int age, float weight, string owner)
        : Animal(name, species, color, age, weight), owner(owner) {}

Pet::Pet(string name, string color, int age, float weight, string owner)
        : Animal(name, color, age, weight), owner(owner) {}

Pet::Pet(const Pet& other): Animal(other) {
    this->owner = other.owner;
}

const string Pet::getOwner() { return owner; }
void Pet::setOwner(const string owner) { this->owner = owner; }

void Pet::pat(const int seconds) {
    std::cout << "Вы гладите " << getName();
    for (int i = 0; i < seconds; ++i) {
        std::cout << ". ";
        Sleep(1000);
    }
    std::cout << endl << "Вы гладили " << getName() << " целых " << seconds << " секунд" << endl;
}