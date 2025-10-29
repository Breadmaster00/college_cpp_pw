#include <iostream>
#include <windows.h>
#include "calories.h"

using namespace std;


const int DISHES_AMOUNT = 5;
int actualDishesAmount;
int targetCalories;
int allCalories;

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "Введите вашу норму калорий" << endl;
    cin >> targetCalories;
    

    do {
        cout << "Сколько блюд вы сегодня съели? - ";
        cin >> actualDishesAmount;

        int* callories = new int[actualDishesAmount];
        for (int i = 0; i < actualDishesAmount; ++i) {
            int callorie;
            cout << "Введите количество каллорий за " << i + 1 << " блюдо - ";
            cin >> callorie;
            callories[i] = callorie;
        }

        allCalories = countAllCalories(callories, actualDishesAmount);
        if (matchThePlan(allCalories, targetCalories)) {
            cout << "Всё идёт по плану, так держать!!!" << endl;
        }
        if (actualDishesAmount <= 2) {
            cout << "Слишком мало приёмов пищи!!!" << endl;
            cout << "Кушайте чаще!!!" << endl;
        }

        cout << "Хотите посчитать колории за новый день? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока :)";
}