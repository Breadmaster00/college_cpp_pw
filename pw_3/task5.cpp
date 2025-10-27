#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    char choice;
    const int WORK_DAYS = 22;
    
    do {
        
        double currentMonth[WORK_DAYS];
        double nextMonth[WORK_DAYS];
        double lastYear[WORK_DAYS] = {
        120000, 115000, 125000, 118000, 130000,
        95000,  88000,  92000,  85000,  78000,
        72000,  68000,  75000,  82000,  95000,
        105000, 112000, 108000, 115000, 122000,
        5000,   8000
        };
        
        cout << "Введите продажи за текущий месяц (22 дня):" << endl;
        for (int i = 0; i < WORK_DAYS; i++) {
            cout << "День " << (i + 1) << ": ";
            cin >> currentMonth[i];
        }
        
        double totalSales = 0;
        for (int i = 0; i < WORK_DAYS; i++) {
            totalSales += currentMonth[i];
        }
        double averageSales = totalSales / WORK_DAYS;
        
        int highDaysCount = 0;
        int highDays[WORK_DAYS];
        
        int lowDaysCount = 0;
        int lowDays[WORK_DAYS];
        
        for (int i = 0; i < WORK_DAYS; i++) {
            if (currentMonth[i] > 100000) {
                highDays[highDaysCount] = i + 1;
                highDaysCount++;
            }
            if (currentMonth[i] < 10000) {
                lowDays[lowDaysCount] = i + 1;
                lowDaysCount++;
            }
        }
        
        int decreasePeriods = 0;
        int currentDecrease = 1;
        int periodLengths[WORK_DAYS];
        int periodCount = 0;
        
        for (int i = 1; i < WORK_DAYS; i++) {
            if (currentMonth[i] < currentMonth[i - 1]) {
                currentDecrease++;
            } else {
                if (currentDecrease > 3) {
                    periodLengths[periodCount] = currentDecrease;
                    periodCount++;
                    decreasePeriods++;
                }
                currentDecrease = 1;
            }
        }
        if (currentDecrease > 3) {
            periodLengths[periodCount] = currentDecrease;
            periodCount++;
            decreasePeriods++;
        }
        
        double currentTotal = 0, lastTotal = 0;
        for (int i = 0; i < WORK_DAYS; i++) {
            currentTotal += currentMonth[i];
            lastTotal += lastYear[i];
        }
        
        double plannedTotal;
        if (currentTotal >= lastTotal) {
            plannedTotal = currentTotal * 1.1;
        } else {
            plannedTotal = (currentTotal + lastTotal) / 2;
        }
        
        double plannedDaily = plannedTotal / WORK_DAYS;
        for (int i = 0; i < WORK_DAYS; i++) {
            nextMonth[i] = plannedDaily;
        }
        
        cout << "\n=== Анализ продаж ===" << endl;
        cout << "1. Средняя сумма продаж: " << averageSales << endl;
        cout << "2. Дни с максимальными продажами (>100000): " << highDaysCount << " дней - ";
        for (int i = 0; i < highDaysCount; i++) {
            cout << highDays[i] << " ";
        }
        cout << endl;
        cout << "3. Дни с минимальными продажами (<10000): " << lowDaysCount << " дней - ";
        for (int i = 0; i < lowDaysCount; i++) {
            cout << lowDays[i] << " ";
        }
        cout << endl;
        cout << "4. Количество периодов уменьшения продаж: " << decreasePeriods << endl;
        
        if (decreasePeriods > 0) {
            cout << "   Длительности периодов: ";
            for (int i = 0; i < periodCount; i++) {
                cout << periodLengths[i] << " дней ";
            }
            cout << endl;
        }
        
        cout << "\n=== План на следующий месяц ===" << endl;
        cout << "Общий план: " << plannedTotal << endl;
        cout << "Ежедневный план: " << plannedDaily << endl;
        
        cout << "\nХотите выполнить еще один анализ? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    cout << "До свидания!" << endl;
    return 0;
}