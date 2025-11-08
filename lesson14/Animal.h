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
        Animal(string name, string species, string color, int age, float weight);
        ~Animal();
        void increaseWheight(int days_of_kormezhka);
        void changeName(string new_name);
        void printInfo();

        
};
