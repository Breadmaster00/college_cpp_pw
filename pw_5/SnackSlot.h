#pragma once
#include <string>
#include "Snack.h"

class SnackSlot {
    private:
        int capacity;
        int currentSnacksAmount;
        Snack snacks[];
    
    public:
        SnackSlot(int capacity): capacity(capacity), currentSnacksAmount(0) {
            snacks[capacity];
        }

        void addSnack(Snack snack) {
            snacks
        } 
};