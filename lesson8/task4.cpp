#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size;
    int res = 0;
    cout << "Введите количество студнетов в группе: ";
    cin >> size;

    int *students = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Сколько пар посетил студент номер " << i + 1 << ": ";
        cin >> students[i];
    }

    int max_pare = 0;
    for (int i = 0; i < size; ++i) {
        if (students[i] > max_pare) {
            max_pare = students[i];
        }
    }
    
    int max_pare_students = 0;
    for (int i = 0; i < size; ++i) {
        if (students[i] == max_pare) {
            max_pare_students++;
        }
    }

    int half_pares = max_pare / 2;
    int less_half_pares = 0;
    for (int i = 0; i < size; ++i) {
        if (students[i] < half_pares) {
            less_half_pares++;
        }
    }

    cout << "У " << max_pare_students << " студентов максимальная посещаемость" << endl;
    cout << "У " << less_half_pares << " студентов посещаемость ниже среднего";

    delete[] students;
    return 0;
}