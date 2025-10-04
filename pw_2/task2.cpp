#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int score, additional_tasks;
    bool bonus_score;
    char choice;

    do {
        cout << "Введите балл за основной тест: ";
        cin >> score;

        cout << "Введите количество выполненных доп. заданий: ";
        cin >> additional_tasks;

        cout << "Имеется бонусный балл? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            bonus_score = true;
        } else {
            bonus_score = false;
        }

        score += additional_tasks * 3;
        if (bonus_score) {
            score += 15;
        }
        
        if (score > 100) {
            score = 100;
        }

        if (90 <= score && score <= 100)  {
            cout << "Ваш балл " << score << " - Отлично";
        } else if (75 <= score && score <= 89) {
            cout << "Ваш балл " << score << " - Хорошо";
        } else if (60 <= score && score <= 74) {
            cout << "Ваш балл " << score << " - Удовлетворительно";
        } else {
            cout << "Ваш балл " << score << " - Неудовлетворительно Бе";
        }

        cout << endl << "Ещё посчитаем? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока!";
}