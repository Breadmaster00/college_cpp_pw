#include <iostream>
#include <windows.h>
#include "math.h"

using namespace std;

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "Добро пожалосвать в ВЕСЁЛЫЙ калькулятор!" << endl;
    cout << "Для помощи введите 'h'\n";
    do {
        double a, b, result;
        string action;

        cout << "Введите выражение:\n> ";
        while (!(cin >> a)) {
            cin.clear();
            char help;
            cin >> help;
            if (help == 'h') {
                cout << pomosch;
            } else {
                cout << "Ошибка введите выражение или 'h' для помощи\n> ";
            }
        }
        cin >> action;
        if (action[0] != '!' && action[0] != '~' && action != "NE") cin >> b;

        if (action == "AND") action[0] = 1;
        if (action == "OR") action[0] = 2;
        if (action == "NE") action[0] = 3;
        if (action == "XOR") action[0] = 4;
        if (action == "<<") action[0] = 5;
        if (action == ">>") action[0] = 6;

        
        switch (action[0]) {
            case '+':
                result = sum(a, b);
                break;
            case '-':
                result = diff(a, b);
                break;
            case '*':
                result = mul(a, b);
                break;
            case '/':
                if (b == 0) {
                    cout << "На ноль делить нельзя!!!";
                    break;
                }
                result = mydiv(a, b);
                break;
            case '^':
                result = mypow(a, b);
                break;
            case '!':
                result = fact(a);
                break;
            case 1:
                result = AND(a, b);
                break;
            case 2:
                result = OR(a, b);
                break;
            case 3:
                result = NE(a);
                break;
            case 4:
                result = XOR(a, b);
                break;
            case 5:
                result = left_sdvig(a, b);
                break;
            case 6:
                result = right_sdvig(a, b);
                break;
            default:
                cout << "Такого действия нет, поробуйте снова\n";
                break;
            }
        cin.clear();
        cout << " = " << result << endl;
        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока :)";
}