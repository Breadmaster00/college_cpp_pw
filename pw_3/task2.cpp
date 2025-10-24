#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    char choice;
    
    do {
        int days;
        cout << "Введите количество дней: ";
        cin >> days;
        
        int* visits = new int[days];
        
        cout << "Введите количество посетителей за каждый день:" << endl;
        for (int i = 0; i < days; i
        ++) {
            cout << "День " << (i + 1) << ": ";
            cin >> visits[i];
        }
        
        int totalVisits = 0;
        for (int i = 0; i < days; i++) {
            totalVisits += visits[i];
        }
        
        double averageVisits = totalVisits / days;
        
        int maxVisits = visits[0], minVisits = visits[0];
        int maxDay = 1, minDay = 1;
        
        for (int i = 1; i < days; i++) {
            if (visits[i] > maxVisits) {
                maxVisits = visits[i];
                maxDay = i + 1;
            }
            if (visits[i] < minVisits) {
                minVisits = visits[i];
                minDay = i + 1;
            }
        }
        
        int lowDays = 0;
        for (int i = 0; i < days; i++) {
            if (visits[i] < averageVisits) {
                lowDays++;
            }
        }
        double lowPercentage = ((double)lowDays / days) * 100;
        
        cout << "\n=== Результаты анализа ===" << endl;
        cout << "1. Общее количество посещений: " << totalVisits << endl;
        cout << "2. Среднее количество посещений в день: " << averageVisits << endl;
        cout << "3. Максимальное число посещений: " << maxVisits << " (день " << maxDay << ")" << endl;
        cout << "   Минимальное число посещений: " << minVisits << " (день " << minDay << ")" << endl;
        cout << "4. Процент дней с низкой посещаемостью: " << lowPercentage << "%" << endl;
        
        delete[] visits;
        
        cout << "\nХотите выполнить еще один анализ? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Пока-пока :)" << endl;
    return 0;
}