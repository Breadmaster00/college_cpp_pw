#include <iostream>
#include <vector>
#include <windows.h>
#include "Printer.h"
#include "Scanner.h"
#include "MFP.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); 
    
    vector<OfficeDevice*> products;
    products.push_back(new Printer("HP LaserJet 1020", 12000.0, "HP", 20, false));
    products.push_back(new Scanner("Canon Lide 300", 8000.0, "Canon", 2400, false));
    products.push_back(new MFP("Epson L3150", 19000.0, "Epson", 15, true, 1200, true, false));

    vector<OfficeDevice*> cart;
    int choice;

    do {
        cout << "\n=== Магазин офисной техники ===\n";
        cout << "1. Показать товары\n";
        cout << "2. Показать характеристики товара\n";
        cout << "3. Добавить товар в корзину\n";
        cout << "4. Показать корзину\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                cout << "\n--- Список товаров ---\n";
                for (size_t i = 0; i < products.size(); ++i) {
                    cout << i << ") " << products[i]->getName() << " — " << products[i]->getPrice() << " руб.\n";
                }
                break;
            }

            case 2: {
                cout << "Введите номер товара: ";
                int id;
                cin >> id;
                if (id >= 0 && id < static_cast<int>(products.size())) {
                    products[id]->showDetails();
                } else cout << "Неверный номер.\n";
                break;
            } 

            case 3: {
                cout << "Введите номер товара: ";
                int id;
                cin >> id;
                if (id >= 0 && id < static_cast<int>(products.size())) {
                    cart.push_back(products[id]);
                    cout << "Товар добавлен в корзину.\n";
                } else {
                    cout << "Неверный номер.\n";
                }
                break;
            }

            case 4: {
                double total = 0.0;
                cout << "\n--- Корзина ---\n";
                if (cart.empty()) { 
                    cout << "(пусто)\n";
                } else {
                    for (auto product : cart) {
                        cout << product->getName() << " — " << product->getPrice() << " руб.\n";
                        total += product->getPrice();
                    }
                }
                cout << "Итого: " << total << " руб.\n";
                break;
            }
                
            case 5:
                cout << "Пока-пока :)";
                break;
            default:
                cout << "Неизвестный выбор.\n";
        }
    } while (choice != 5);

    for (auto product : products) delete product;

    return 0;
}
