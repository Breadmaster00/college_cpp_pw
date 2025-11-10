#pragma once
#include <string>

using namespace std;

class Animal {
    private:
        string name;
        string species;
        string color;
        int age;
        float weight;
    
    public:
        Animal(string name, string species, string color, int age, float weight);
        Animal(string name, string color, int age, float weight);
        ~Animal();
        Animal(const Animal& other);

        // геттеры
        const string getName();
        const string getSpecies();
        const string getColor();
        const int getAge();
        const float getWeight();

        // сеттеры
        void setName(const string name);
        void setSpecies(const string species);
        void setColor(const string color);
        void setAge(const int age);
        void setWeight(const float weight);

        // остальные методы
        void increaseWheight(int days_of_kormezhka);
        void changeName(string new_name);
        const void printInfo();

         // перегрузка операторов
        Animal& operator++();
        Animal operator++(int);
        Animal& operator--();
        Animal operator--(int);

        bool operator<(const Animal& other);
        bool operator>(const Animal& other);
        bool operator==(const Animal& other);
        
};
