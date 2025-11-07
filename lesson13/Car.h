#pragma once
#include <string>

using namespace std;

struct Car {
    private:
        string mark;
        string color;
        string typeOfkuzov;
        double engineCapacity;
        int probeg;
    public:
        void initCar(string mark, string color, string typeOfkuzov, double engineCapicity, int probeg);
        double countAvergeFuelConsumption(double distance);
        void scrutit_probeg(int scrutka);
        void printInfo();
};