#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int age, category;
    char choice;

    do {
        while (true) {
            cout << "Введите возраст посетителя" << endl;
            cout << "> ";
            cin >> age;
            if (age > 0) {
                break;
            } else {
                cout << "Ошибка! Введён некорректный возраст, повторите попытку\n";
            }
        }

        while (true) {
            cout << "Отлично! Теперь введите категорию билета"
            "\n 1 - обычный;"
            "\n 2 - детский;"
            "\n 3 - пенсионер;"
            "\n 4 - VIP.\n"
            "> ";
            cin >> category;
            
            if (1 <= category && category <= 4) {
                break;
            } else {
                cout << "Такой категории не существует, поробуйте ещё раз!\n";
            }
        }

        if (age < 5) {
            cout << "Вход запрещён: слишком маленький возраст";
        }
        else if (5 <= age && age <= 12) {
            if (category == 2) {
                cout << "Вход разрешён! - Категория билета - детский";
            } else {
                cout << "Вход запрещён! - требуется детский билет!";
            }
        }
        else if (13 <= age && age <= 49) {
            if (category == 1) {
                cout << "Вход разрешён - Категория билета - обычный";
            } else if (category == 4) {
                cout << "Вход разрешён - Категория билета - VIP";
            } else {
                cout << "Вход запрещён! - требуется обычный или VIP билет";
            }
        } 
        else if (50 <= age and age <= 64) {
            if (category == 1) {
                cout << "Вход разрешён - Категория билета - обычный";
            } else if (category == 3) {
                cout << "Вход разрешён - Категория билета - пенсионерский";
            } else if (category == 4) {
                cout << "Вход разрешён - Категория билета - VIP";
            } else {
                cout << "Вход запрещён! - требуется любой билет кроме детского";
            }
        }
        else if (age >= 65) {
            if (category == 3) {
                cout << "Вход разрешён - Категория билета - пенсионерский";
            } else if (category == 4) {
                cout << "Вход разрешён - Категория билета - VIP";
            } else {
                cout << "Вход запрещён! - требуется пенсионерский или VIP билет";
            }
        }

        cout << "\nЖелаете принять следующего посетителя? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока!";
}