#pragma once
#include "Animal.h"
#include <string>

class Pet : public Animal {
    private:
        string owner;
    public:
        Pet(string name, string species, string color, int age, float weight, string owner);
        Pet(string name, string color, int age, float weight, string owner);
        Pet(const Pet& other);

        const string getOwner();
        void setOwner(const string owner);
        void pat(const int seconds);
};


