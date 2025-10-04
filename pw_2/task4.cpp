#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int product_count;
    float price = 0, input, full_price, discount, payment;
    bool loayl_card;
    char choice;

    cout << "Сколько товар приобрели?: ";
    cin >> product_count;

    for (int i = 1; i <= product_count; ++i) {
        do {
            cout << "Введите стоимость " << i << "-го товара: ";
            cin >> input;
            price += input;
        } while (input < 0);
    }

    cout << "Есть карта лояльности? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        loayl_card = true;
    }

    full_price = price;
    if (price > 5000 && loayl_card) {
        discount = price * 0.15;
    } else if (price > 5000) {
        discount = price * 0.1;
    } else {
        discount = 0;
    }
    price -= discount;

    cout << "Сколько денег дал, клиент - ";
    cin >> payment;

    cout << "================" << endl;
    cout << "Итого: " << full_price << " рублей - без скидок" << endl;
    cout << "Скидка - " << discount << " рублей" << endl;
    cout << "Итого к оплате - " << price << " рублей" << endl;
    cout << "Сдача - " << payment - price << " рублей" << endl; 
    cout << "================" << endl;
}