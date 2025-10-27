#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    char choice;
    
    do {
        const int HOURS = 24;
        double speeds[HOURS];
        double speedLimit;
        
        cout << "Введите порог разрешенной скорости: ";
        cin >> speedLimit;
        
        cout << "Введите скорость водителя каждый час:" << endl;
        for (int i = 0; i < HOURS; i++) {
            cout << "Час " << (i + 1) << ": ";
            cin >> speeds[i];
        }
        
        double totalSpeed = 0;
        for (int i = 0; i < HOURS; i++) {
            totalSpeed += speeds[i];
        }
        double averageSpeed = totalSpeed / HOURS;
        
        int maxNormalInterval = 0;
        int currentNormal = 0;
        
        int maxExceedInterval = 0;
        int currentExceed = 0;
        

        int movingHours = 0;
        
        for (int i = 0; i < HOURS; i++) {
            if (speeds[i] > 0) {
                movingHours++;
            }
            
            if (speeds[i] <= speedLimit) {
                currentNormal++;
                if (currentNormal > maxNormalInterval) {
                    maxNormalInterval = currentNormal;
                }
                currentExceed = 0;
            } else {
                currentExceed++;
                if (currentExceed > maxExceedInterval) {
                    maxExceedInterval = currentExceed;
                }
                currentNormal = 0;
            }
        }
        
        cout << "\n=== Результаты анализа ===" << endl;
        cout << "1. Средняя скорость за сутки: " << averageSpeed << " км/ч" << endl;
        cout << "2. Максимальный интервал без превышения: " << maxNormalInterval << " часов" << endl;
        cout << "3. Максимальный интервал превышения: " << maxExceedInterval << " часов" << endl;
        cout << "4. Общее количество часов движения: " << movingHours << " часов" << endl;
        
        cout << "\nХотите выполнить еще один анализ? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Пока-пока! :)" << endl;
    return 0;
}