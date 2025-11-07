#include <iostream>
#include <windows.h>
#include "finance.h"

using namespace std;

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    const int necessary_amount = 7;
    int necessary_expenses[necessary_amount] = {5800, 6200, 4700, 10500, 5000, 3600, 23700};

    do {
        int income;
        cout << "Введите доходы семьи\n> ";
        cin >> income;

        int unplaned_expenses;
        cout << "Введите сумму незаплонированных трат: ";
        cin >> unplaned_expenses;

        int necessary_expenses_sum = calculateSum(necessary_expenses, necessary_amount);
        cout << "Общая сумма обязательных трат: " << necessary_expenses_sum << " рублей" << endl;
        cout << "Сумма незапланированных трат: " << unplaned_expenses << " рублей" << endl;

        int average_necessary_expenses = getAverageValue(necessary_expenses, necessary_amount);
        cout << "Средняя сумма обязательных трат: " << average_necessary_expenses << " рублей" << endl;

        if (unplaned_expenses > necessary_expenses_sum) {
            int percent = unplaned_expenses * 100 / average_necessary_expenses - 100;
            cout << "Незапланированные траты превысили на " << percent << "% среднюю сумму обязательных трат" << endl;
        } else {
            cout << "Незапланированные траты не привысили обязательные" << endl;
        }

        int remains = income - necessary_expenses_sum - unplaned_expenses;
        cout << "Остаток средств: " << remains << " рублей" << endl;

        int nado = (income - necessary_expenses_sum) - (income * 0.1);
        cout << "Незапланированные расходы должны быть меньше, чем " << nado << " рублей, чтобы осталось не менее 10% от дохода" << endl; 

        
        cout << "Посчитаем ещё? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y') ;
    cout << "Пока-пока :)";
}