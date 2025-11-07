#include <iostream>
#include <windows.h>
#include "weather.h"

using namespace std;

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    do {
        const int OCTOBER_DAYS = 31;
        int october2024[OCTOBER_DAYS] = {
            10, 8, 6, 4, 2, 0, -2, 1, 3, 5,
            7, 9, 11, 13, 15, 12, 10, 8, 6, 4,
            2, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9
        };
    
        int october_days_2025 = 0;
        do {
            cout << "Введите количество анализируемых дней текущего месяца\n> ";
            cin >> october_days_2025;
            if (october_days_2025 <= 0 || october_days_2025 > OCTOBER_DAYS) {
                cout << "!! Введено недопустимое значение, попробуйте снова !!\n> ";
            }
        } while (october_days_2025 <= 0 || october_days_2025 > OCTOBER_DAYS);
        int* october2025 = new int[october_days_2025];

        for (int i = 0; i < october_days_2025; ++i) {
            cout << "Введите температуру в " << i + 1 << " анализируемый день\n> ";
            cin >> october2025[i];
        }
        
        float average_temp_october2024 = getAverageValue(october2024, OCTOBER_DAYS);
        float average_temp_october2025 = getAverageValue(october2025, october_days_2025);

        if (average_temp_october2024 > average_temp_october2025) {
            cout << "В прошлом году было теплее - в среднем " << average_temp_october2024 << "°C" << endl;
        } else {
            cout << "В этом году теплее - в среднем " << average_temp_october2025 << "°C" << endl;
        }

        int difference_average_temp = average_temp_october2024 - average_temp_october2025;
        difference_average_temp = difference_average_temp < 0 ? difference_average_temp : -difference_average_temp;

        if (difference_average_temp > 5) {
            cout << "!!! ВНИМАНИЕ НАБЛЮДАЕТСЯ ВЫСОКИЙ ПЕРЕПАД ТЕМПЕРАТУР !!!" << endl;
        }

        int min_temp2024 = getMinValue(october2024, OCTOBER_DAYS); 
        int min_temp2025 = getMinValue(october2025, october_days_2025);
        if (min_temp2024 < min_temp2025) {
            cout << "Минимальная температура в прошлом году была ниже - " << min_temp2024 << "°C" << endl;
        } else if (min_temp2025 < min_temp2024) {
            cout << "Минимальная температура в этом году ниже - " << min_temp2025 << "°C" << endl;
        } else {
            cout << "Минимальная температура в этом году такая же, как и в прошлом - " << min_temp2025 << "°C" << endl;
        }


        int max_temp2024 = getMaxValue(october2024, OCTOBER_DAYS); 
        int max_temp2025 = getMaxValue(october2025, october_days_2025);
        if (max_temp2024 > max_temp2025) {
            cout << "Максимальная температура в прошлом году была выше - " << max_temp2024 << "°C" << endl;
        } else if (max_temp2025 > max_temp2024) {
            cout << "Максимальная температура в этом году выше - " << max_temp2025 << "°C" << endl;
        } else {
            cout << "Максимальная температура в этом году такая же, как и в прошлом - " << max_temp2025 << "°C" << endl;
        }
        

        int less_than_zero2024 = 0;
        int less_than_zero2025 = 0;

        for (int i = 0; i < OCTOBER_DAYS; ++i) {
            if (october2024[i] < 0) {
                ++less_than_zero2024;
            }
        }
        for (int i = 0; i < october_days_2025; ++i) {
            if (october2025[i] < 0) {
                ++less_than_zero2025;
            } 
        }

        cout << "В прошлом году температура ниже 0 была " << less_than_zero2024 << " дней" << endl;
        cout << "В этом году температура ниже 0 была " << less_than_zero2025 << " дней" << endl;

        delete[] october2025;
        cout << "Потемпературим ещё? ;) (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y') ;
    cout << "Пока-пока :)";
}