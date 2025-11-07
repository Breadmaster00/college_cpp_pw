#include <iostream>
#include <windows.h>
#include "Animal.h"
#include "Car.h"

using namespace std;

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);    

    do {
        Car vasyanCar;
        vasyanCar.initCar("Мерседес", "Чёрный", "классный", 150, 100500);
        vasyanCar.countAvergeFuelConsumption(1000);
        vasyanCar.scrutit_probeg(2000);
        vasyanCar.printInfo();

        Animal* labubu = new Animal;
        labubu->initAnimal("Лабубу", "дикий", "огуречный", 5, 2);
        labubu->changeName("Иполит");
        labubu->increaseWheight(50);
        labubu->printInfo();

        delete labubu;
        cout << "Продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока :)";
}