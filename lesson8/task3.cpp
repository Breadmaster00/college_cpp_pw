#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int size;
    int res = 0;
    cout << "Введите общее количество посетителей: ";
    cin >> size;

    int *visitors_array = new int[size];
    for (int i = 0; i < size; ++i) {
        cout << "Введите номер посетителя: ";
        cin >> visitors_array[i];
    }

    int uniqueVisitors = 0;
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (visitors_array[i] == visitors_array[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) uniqueVisitors += isUnique;
    }
    
    cout << "Количество уникальных посетителей: " << uniqueVisitors << endl;
    
    delete[] visitors_array;
    return 0;
}