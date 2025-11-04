#pragma once
#include <string>

using namespace std;

struct Animal {
    private:
        string name;
        string species;
        string color;
        int age;
        float weight;
    
    public:
        void initAnimal(string name, string species, string color, int age, float weight);
        void increaseWheight(int days_of_kormezhka);
        void changeName(string new_name);
        void printInfo();
        
};
