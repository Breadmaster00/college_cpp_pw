#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    char choice;
    
    do {
        string line;
        char encryptedLine[1000] = {0};
        int step;

        cout << "Введите строку для шифрование\n> ";
        getline(cin, line);

        cout << "Введите шаг сдвига\n> ";
        cin >> step;

        int line_length = line.length();

        for (int i = 0; i < line_length; i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                encryptedLine[i] = line[i] + step;
                if (encryptedLine[i] > 'z') {
                    encryptedLine[i] -= 26;
                } else if (encryptedLine[i] < 'a') {
                    encryptedLine[i] += 26;
                }
            } else if (line[i] >= 'A' && line[i] <= 'Z') {
                encryptedLine[i] = line[i] + step;
                if (encryptedLine[i] > 'Z') {
                    encryptedLine[i] -= 26;
                } else if (encryptedLine[i] < 'A') {
                    encryptedLine[i] += 26;
                }
            } else {
                encryptedLine[i] = line[i];
            }

        }
        encryptedLine[line_length] = '\0';
        cout << "Ваше зашифрованное сообщение: ";
        cout << encryptedLine;

        
        cout << "\nХотите ещё? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Пока-пока :)" << endl;
    return 0;
}