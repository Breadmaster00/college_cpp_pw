#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int drink_num, dobavka_num;
    float price = 0;
    char size, choice;
    string drink_name;
    vector<string> drinks_names = {"Эспрессо", "Капучино", "Латте", "Чай", "Горячий шокалад"};
    vector<string> dobavka_names = {"без добавок", "с молоком", "с сиропом", "со сливками"};


    do {
        do {
            cout << "Введите номер желаемого напитка"
            "\n1. Эспрессо - 70 рублей"
            "\n2. Капучино - 120 рублей"
            "\n3. Латте - 140 рублей"
            "\n4. Чай - 50 рублей"
            "\n5. Горячий шоколад - 100 рублей"
            "\n> ";
            cin >> drink_num;
        } while (!(1 <= drink_num && drink_num <= 5));

        do {
            cout << "Введие желаемый размер"
            "\nS (маленький) — базовая цена"
            "\nM (средний) — +30% к цене"
            "\nL (большой) — +50% к цене"
            "\n> ";
            cin >> size;
        } while (!(size == 'S' || size == 'M' || size == 'L'));

        do {
            cout << "Введите желаемую добавку"
            "\n1. без добавок"
            "\n2. молоко (+10 рублей)"
            "\n3. сироп (+15 рублей)"
            "\n4. сливки (+20 рублей)"
            "> ";
            cin >> dobavka_num;
        } while (!(1 <= dobavka_num && dobavka_num <= 4));

        switch (drink_num) {
            case 1:
                price += 70;
                break;
            case 2:
                price += 120;
                break;
            case 3:
                price += 140;
                break;
            case 4:
                price += 50;
                break;
            case 5:
                price += 100;
                break;
            
        }

        switch (size) {
            case 'S':
                break;
            case 'M':
                price += (price / 100) * 30;
                break;
            case 'L':
                price += (price / 100) * 50;
                break;
        }

        switch (dobavka_num) {
            case 1:
                break;
            case 2:
                price += 10;
                break;
            case 3:
                price += 15;
                break;
            case 4:
                price += 20;
                break;
        }

        cout << drinks_names[drink_num - 1] << " " << dobavka_names[dobavka_num - 1]
        << " - размер " << size
        << " - цена " << price << " рублей" << endl;

        cout << "Ещё посчитаем? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока!";
}