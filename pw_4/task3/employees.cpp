#include <iostream>

int calculateTheSalaryFund(int hourlyEmployees[], int size_hourly, const int rateEmployees[], int size_rate) {
    int fund = 0;
    for (int emp = 0; size_hourly; emp++) {
        fund += hourlyEmployees[emp];
    }
    for (int emp = 0; size_rate; emp++) {
        fund += rateEmployees[emp];
    }
    return fund;
}