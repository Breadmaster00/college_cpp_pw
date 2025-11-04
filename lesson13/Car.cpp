#include <iostream>
#include <string>

using namespace std;

struct Car {
    string mark;
    string color;
    string typeOfkuzov;
    double engineCapacity;
    int probeg;
    
    double countAvergeFuelConsumption(double distance) {
        return engineCapacity / distance * 100;
    }
    
    void scrutit_probeg(int scrutka) {
        probeg -= scrutka;
        cout << "Пробег скручен, теперь он " << probeg << "км" << endl;
    }
    
    void printInfo() {
        cout << "Марка: " << mark << ", цвет: " << color << ", тип кузова: "
        << typeOfkuzov << ", объём двигателя: " << engineCapacity << ", пробег: " << probeg << "км" << endl;
    }
};

int main() {
    Car vasyanCar{"Мерседес", "Чёрный", "классный", 150, 100500};
    Car* kiraCar = new Car{"BMW", "Жёлтый", "ослепительный", 200, 2000500};
    
    
    cout << vasyanCar.countAvergeFuelConsumption(250) << " литров на 100км\n";
    vasyanCar.scrutit_probeg(100000);
    vasyanCar.printInfo();
    
    cout << "- - - - - - - -\n";
    
    cout << kiraCar->countAvergeFuelConsumption(100) << " литров на 100км\n";
    kiraCar->scrutit_probeg(500);
    kiraCar->printInfo();
}
