#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int del_count;
    int *products = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int TOTAL_PRODUCTS = 10;

    cout << "Сколько товаров нужно удалить?: ";
    cin >> del_count;
    
    int* toRemove = new int[del_count];
    
    cout << "Введите идентификаторы товаров для удаления: ";
    for (int i = 0; i < del_count; i++) {
        cin >> toRemove[i];
    }
    
    bool* removed = new bool[TOTAL_PRODUCTS]();
    
    for (int i = 0; i < del_count; i++) {
        for (int j = 0; j < TOTAL_PRODUCTS; j++) {
            if (products[j] == toRemove[i]) {
                removed[j] = true;
                break;
            }
        }
    }
    
    int remainingCount = 0;
    for (int i = 0; i < TOTAL_PRODUCTS; i++) {
        if (!removed[i]) {
            remainingCount++;
        }
    }
    
    int* remainingProducts = new int[remainingCount];
    int index = 0;
    
    for (int i = 0; i < TOTAL_PRODUCTS; i++) {
        if (!removed[i]) {
            remainingProducts[index++] = products[i];
        }
    }
    
    cout << "Оставшиеся товары: ";
    for (int i = 0; i < remainingCount; i++) {
        cout << remainingProducts[i] << " ";
    }
    cout << endl;
    delete[] products;
    delete[] toRemove;
    delete[] removed;
    delete[] remainingProducts;
    
    

}