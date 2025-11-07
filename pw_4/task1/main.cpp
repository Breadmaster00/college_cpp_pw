#include <iostream>
#include <windows.h>
#include "math.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "Добро пожалосвать в ВЕСЁЛЫЙ калькулятор!" << endl;
    cout << "Для помощи введите 'h', чтобы выйти нажмите 'q'\n";
    cout << "Введите выражение:\n ";
    bool quit = 0;
    do {
        double a, b, result = 0;
        string action;

        cout << "> ";
        while (!(cin >> a)) {
            cin.clear();
            char command;
            cin >> command;
            if (command == 'h') {
                cout << pomosch;
            } else if (command == 'q') {
                quit = true;
                break;
            } else {
                cout << "Ошибка введите выражение или 'h' для помощи, чтобы выйти нажмите q\n> ";
            }
        }
        if (quit) {continue;}
        
        cin >> action;
        if (action[0] != '!' && action[0] != '~' && action != "NE") cin >> b;

        if (action == "AND") action[0] = 1;
        else if (action == "OR") action[0] = 2;
        else if (action == "NE") action[0] = 3;
        else if (action == "XOR") action[0] = 4;
        else if (action == "<<") action[0] = 5;
        else if (action == ">>") action[0] = 6;
        
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
        if (result) {
            cout << "> " << result << endl;
        }
    } while (!quit);
    cout << "Пока-пока :)";
}