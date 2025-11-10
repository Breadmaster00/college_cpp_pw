#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

Animal::Animal(string name, string species, string color, int age, float weight) {
    this->name = name;
    this->species = species;
    this->color = color;
    this->age = age;
    this->weight = weight;
}
Animal::Animal(string name, string color, int age, float weight) {
    this->name = name;
    this->species = "обыкновенный";
    this->color = color;
    this->age = age;
    this->weight = weight;
}

Animal::~Animal() {
    cout << name << " уничтожен!";
}

// геттеры
const string Animal::getName() { return name; }
const string Animal::getSpecies() { return species; }
const string Animal::getColor() { return color; }
const int Animal::getAge() { return age }
const float Animal::getWeight() { return weight; }

// сеттеры
void Animal::setName(const string name) {
    this->name = name;
}

void Animal::setSpecies(const string species) {
    this->species = species;
}

void Animal::setColor(const string color) {
    this->color = color;
}

void Animal::setAge(const int age) {
    this->age = age;
}

void Animal::setWeight(const float weight) {
    this->weight = weight;
}
void setSpecies(const string species);
void setColor(const string color);
void setAge(const int age);
void setWeight(const float weight);

// остальные методы
void Animal::increaseWheight(int days_of_kormezhka) {
    float additional_weight = weight * 0.01 * days_of_kormezhka;
    weight += additional_weight;
    cout << "Вес " << name << " увеличен на " << additional_weight << "кг" << endl;
}

void Animal::changeName(string new_name) {
    cout << "Имя " << name << " измененено на " << new_name << endl;
    name = new_name;
}

void Animal::printInfo() {
    cout << name << " вида " << species << " цвета " << color << " возрастом " << age << " весом " << weight << "кг" << endl; 
}
