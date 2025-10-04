#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(time(0));
    int num, random_num = rand() % 21, attempts = 0;
    int errors = 0;
    
    cout << "Привет! Это игра в угадайку." << endl
    << "Угадай число от 1 до 20" << endl;
    do {
        cout << "Число: ";
        cin >> num;
        if (num <= 0 || num > 20) {
            cout << "Воу-воу полегче!! Я не понятно объяснил? ЧИСЛО ОТ 1 ДО 20" << endl;
            ++errors;
            if (errors == 5) {
                cout << "Ты совсем идиот? Прекрати ломать компьютер и займись чем-нибудь полезным. ПОКА!!";
                break;
            }
        } else if (num > random_num) {
            cout << "Чё-то много, давай по новой" << endl;
            ++attempts;
        } else if (num < random_num) {
            cout << "Чё-то мало, давай по новой" << endl;
            ++attempts;
        } 
    } while (num != random_num);
    if (num ==  random_num) {
        cout << "Ура!!! Ты угадал, да, это действительно " << random_num << endl;
        cout << "Это заняло у тебя всего лишь " << attempts << " попыток"; 
    }
}