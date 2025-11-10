#include "Animal.h"
#include <iostream>
#include <string>
#include "Validate.h"

using namespace std;
using namespace validate;

Animal::Animal(string name, string species, string color, int age, float weight) {
    if (isCorrectAlpha(name)) this->name = name;
    else this->name = "Безымянный";

    if (isCorrectAlpha(species)) this->species = species;
    else this->species = "обыкновенный";

    if (isCorrectAlpha(color)) this->color = color;
    else this->color = "серенький";
    
    if (isCorrectCount(age)) this->age = age;
    else this->age = 0;

    if (isCorrectCount(weight)) this->weight = weight;
    else this->weight = 0;
    
}
Animal::Animal(string name, string color, int age, float weight) 
    : Animal::Animal(name, "обыкновенный", color, age, weight) {}

Animal::~Animal() {
    cout << name << " уничтожен!" << endl;
}

// геттеры
const string Animal::getName() { return name; }
const string Animal::getSpecies() { return species; }
const string Animal::getColor() { return color; }
const int Animal::getAge() { return age; }
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
    if (isCorrectCount(age)) {
        this->age = age;
    } else {
        cout << "Нельзя указать возраст меньше 0" << endl;
    }
}

void Animal::setWeight(const float weight) {
    if (isCorrectCount(weight)) {
        this->weight = weight;
    } else {
        cout << "Нельзя указать вес меньше 0 кг" << endl;
    }
}

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

const void Animal::printInfo() {
    cout << name << " вида " << species << " цвета " << color << " возрастом " << age << " весом " << weight << "кг" << endl; 
}

// перегрузка операторов
Animal& Animal::operator++() {
    weight += 5;
    return *this;
}
Animal Animal::operator++(int) {
    Animal obj(*this);
    ++*this;
    return obj;
}

Animal& Animal::operator--() {
    weight -= 5;
    return *this;
}
Animal Animal::operator--(int) {
    Animal obj(*this);
    --*this;
    return obj;
}

bool Animal::operator<(Animal other) {
    return weight < other.weight;
}
bool Animal::operator>(Animal other) {
    return weight > other.weight;
}
bool Animal::operator==(Animal other) {
    return weight == other.weight;
}