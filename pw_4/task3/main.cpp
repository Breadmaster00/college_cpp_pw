#include <iostream>
#include <windows.h>
#include "calories.h"

using namespace std;


const int FIX_EMPLOYEE_COUNT = 15;
const int EMPLOYEES_WITH_A_RATE_SALARIES[FIX_EMPLOYEE_COUNT] = {22500, 12500, 34700, 30000, 24000, 57000, 37000, 77000, 42000, 42000, 27600, 38800, 75200, 66400, 32500};
const int HOURS_OF_WORK = 160;

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    do {

        int hourlyEmployees;
        cout << "Введите число сотрудников с почасовой оплатой" << endl;
        cin >> hourlyEmployees;
        int* hourlyEmployeesSalaries = new int[hourlyEmployees];
        cout << "Введите оплату за час для каждого сотрудника" << endl;
        for (int emp = 0; emp < hourlyEmployees; emp++) {
            int salary;
            cout << "Оплата за час сотрудника " << emp << endl;
            cin >> salary;
            hourlyEmployeesSalaries[emp] = salaary;
        }

        

        cout << "Хотите посчитать колории за новый день? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока :)";
}