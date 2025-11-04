#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size;
    int res = 0;
    cout << "Введите размер массива: ";
    cin >> size;

    int array[size];
    for (int i = 0; i < size; ++i) {
        cout << "Введите значение: ";
        cin >> array[i];
    }

    cout << "Массив наоборот" << endl;
    for (int i : array) {
        res += i;
    }
    cout << "Сумма чисел: " << res;
    return 0;
}