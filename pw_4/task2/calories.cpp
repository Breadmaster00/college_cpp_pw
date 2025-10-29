#include <iostream>

using namespace std;


int countAllCalories(int meals[], int size) {
    int amount = 0;
    for (int i = 0; i < size; i++) {
        amount += meals[i];
    }
    return amount;
}

const float NORMAL_COOF = 1.5;
bool matchThePlan(int actualCalories, int targetCalories) {
    if (actualCalories >= targetCalories * NORMAL_COOF) {
        cout << "Слишком много каллорий!!!" << endl;
        cout << "Отличается от нормы на " << actualCalories - targetCalories << endl;
    } else if (actualCalories <= targetCalories / NORMAL_COOF) {
        cout << "Слишком мало калорий!!!" << endl;
        cout << "Отличается от нормы на " << targetCalories - actualCalories << endl;
    } else {
        return true;
    }
    return false;
}

