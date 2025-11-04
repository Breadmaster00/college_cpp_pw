#include "Animal.h"
#include <iostream>
#include <string>

using namespace std;

void Animal::initAnimal(string nname, string nspecies, string ncolor, int nage, float nweight) {
    name = nname;
    species = nspecies;
    color = ncolor;
    age = nage;
    weight = nweight;
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
