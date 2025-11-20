#include <windows.h>
#include <iostream>
#include "Car.h"
#include "Animal.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); 

    Car vasyanCar("Mercedes", "Black", "cool", 150, 100500);
    Car* kiryaCar = new Car{"BMW", "Жёлтый", "ослепительный", 200};
    Animal slon{"Наполеон", "зелёный", 45, 700};
    Animal* labubu = new Animal("Лабубу", "дикий", "огуречный", 5, 2);
    
    // машинки
    vasyanCar.printInfo();
    kiryaCar->printInfo();
    vasyanCar++;
    ++*kiryaCar;
    if (vasyanCar > *kiryaCar) cout << "У Васи двигатель больше" << endl;
    else if (vasyanCar < *kiryaCar) cout << "У Кири двигетль больше" << endl;
    else cout << "Одинаковые двигатели" << endl << endl;
    vasyanCar.setColor("Фиолетовый");
    vasyanCar.setColor("Фиолетовый2");
    vasyanCar.setEngineCapacity(-12);
    vasyanCar.setEngineCapacity(300);
    vasyanCar.printInfo();
    kiryaCar->printInfo();
    cout << '\n';

    // зверушки
    slon.printInfo();
    labubu->printInfo();
    slon++;
    ++*labubu;
    if(slon > *labubu) cout << "Слон весит больше" << endl;
    else if (slon < *labubu) cout << "Лабубу тяжелее" << endl;
    else cout << "одинаковые" << endl;
    
    slon.setSpecies("сигмабой228");
    slon.setSpecies("необыкновенный");
    slon.setAge(-12);

    slon.printInfo();
    labubu->printInfo();
    
    delete kiryaCar;
    delete labubu;
    return 0;
}