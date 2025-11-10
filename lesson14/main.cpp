#include <iostream>
#include "Car.h"
#include "Animal.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); 

    Car vasyanCar("Mercedes", "Black", "крутой", 150, 100500);
    Car* kiryaCar = new Car{"BMW", "Жёлтый", "ослепительный", 200};
    Animal slon{"Наполеон", "зелёный", 45, 700};
    Animal* labubu = new Animal("Лабубу", "дикий", "огуречный", 5, 2);

    vasyanCar.printInfo();
    kiryaCar->printInfo();
    slon.printInfo();
    labubu->printInfo();
    
    cout << "\n";

    vasyanCar.setProbeg(-299);
    kiryaCar->setEngineCapacity(-42);
    slon.setAge(-12);
    labubu->setWeight(-100000000);

    delete kiryaCar;
    delete labubu;
    return 0;
}