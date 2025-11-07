#include <iostream>
#include <windows.h>
#include "finance.h"

using namespace std;

char choice;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int necessay_amount = 7;
    int necessary_expenses[necessary_amount] = {5800, 6200, 4700, 10500, 5000, 3600, 23700};
    do {
        
        cout << "Потемпературим ещё? ;) (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y') ;
    cout << "Пока-пока :)";
}