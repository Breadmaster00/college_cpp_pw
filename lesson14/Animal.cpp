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

Animal::~Animal() {
    cout << name << " уничтожен!";
}
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
