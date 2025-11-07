#include <iostream>
#include <windows.h>
#include "employees.h"

using namespace std;

const int HOURS_OF_WORK = 160;
const int RATE_EMPLOYEE_COUNT = 15;
int EMPLOYEES_WITH_A_RATE_SALARIES[RATE_EMPLOYEE_COUNT] = {22500, 12500, 34700, 30000, 24000, 57000, 37000, 77000, 42000, 42000, 27600, 38800, 75200, 66400, 32500};

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    do {
        int hourlyEmployeesAmount;
        cout << "Введите число сотрудников с почасовой оплатой" << endl;
        cin >> hourlyEmployeesAmount;
        int* hourlyEmployeesSalaries = new int[hourlyEmployeesAmount]; 

        cout << "Введите оплату за час для каждого сотрудника" << endl;
        for (int emp = 0; emp < hourlyEmployeesAmount; emp++) {
            int salary;
            cout << "Оплата за час сотрудника " << emp + 1 << endl;
            cin >> salary;
            hourlyEmployeesSalaries[emp] = salary;
        }

        int rate_fund = calculateSum(EMPLOYEES_WITH_A_RATE_SALARIES, RATE_EMPLOYEE_COUNT);
        int hourly_fund = calculateSum(hourlyEmployeesSalaries, hourlyEmployeesAmount) * HOURS_OF_WORK;
        int general_fund = rate_fund + hourly_fund;
        cout << "Общий фонд заработной платы на месяц составляет " << general_fund << " рублей" << endl;

        if (rate_fund > hourly_fund) {
            cout << "Больший буджет потребовали работники со ставкой (" << rate_fund << " рублей)" << endl;
        } else if (hourly_fund > rate_fund) {
            cout << "Больший бюджет потребовали работники с почасовой оплатой (" << hourly_fund << " рублей)" << endl;
        } else {
            cout << "Все работники потребовали одинаковый бюджет (" << rate_fund << " рублей)" << endl;
        }


        int averageSalary = general_fund / (RATE_EMPLOYEE_COUNT + hourlyEmployeesAmount);

        int mega_employees_amount = 0;

        for (int i = 0; i < RATE_EMPLOYEE_COUNT; ++i) {
            if (EMPLOYEES_WITH_A_RATE_SALARIES[i] > averageSalary) {
                ++mega_employees_amount;
            }
        }
        for (int i = 0; i < hourlyEmployeesAmount; ++i) {
            if (hourlyEmployeesSalaries[i] > averageSalary) {
                ++mega_employees_amount;
            }
        }
        cout << "Количество сотрудников с зарплатой выше среднего - " << mega_employees_amount << " штук" << endl;


        int minSalary = getMinValue(EMPLOYEES_WITH_A_RATE_SALARIES, RATE_EMPLOYEE_COUNT);
        int lessThanMinSalaryAmount = 0;
        for (int i = 0; i < hourlyEmployeesAmount; ++i) {
            if (hourlyEmployeesSalaries[i] * HOURS_OF_WORK < minSalary) {
                ++lessThanMinSalaryAmount;
            }
        }
        cout << "У " << lessThanMinSalaryAmount << " сотрудников зарплата ниже минимальной фиксированной ставки в компании." << endl;


        delete[] hourlyEmployeesSalaries;
        cout << "Хотите посчитать зарплаты за следующий месяц день? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y') ;
    cout << "Пока-пока :)";
}