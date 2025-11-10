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
        Car(string mark, string color, string typeOfkuzov, double engineCapacity, int probeg);
        Car(string mark, string color, string typeOfkuzov, double engineCapacity);
        ~Car();

        // геттеры
        const string getMark();
        const string getColor();
        const string getTypeOfkuzov();
        const double getEngineCapacity();
        const int getProbeg();

        // сеттеры
        void setMark(const string mark);
        void setColor(const string color);
        void setTypeOfkuzov(const string typeOfkuzov);
        void setEngineCapacity(const double engineCapacity);
        void setProbeg(const int probeg);

        // другие методы
        double countAvergeFuelConsumption(double distance);
        void scrutit_probeg(int scrutka);
        const void printInfo();

        // перегрузка операторов
        Car& operator++();
        Car operator++(int);
        Car& operator--();
        Car operator--(int);

        bool operator<(Car other);
        bool operator>(Car other);
        bool operator==(Car other);
};