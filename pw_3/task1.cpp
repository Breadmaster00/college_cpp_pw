#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    int option,
    capacity = 4,
    taskCount = 0,
    Id;
    char choice;
    int *tasksList = new int[capacity];

    do {
        cout << "Выберите опцию:" << endl
        << "1. Добавить новую задачу;" << endl
        << "2. Удалить задачу;" << endl 
        << "3. Просмотреть все задачи;" << endl
        << "4. Выйти." << endl << "> "; 
        cin >> option;
        
        switch (option) {
            case 1:
                if(taskCount == capacity) {
                    capacity *= 2;
                    int* newTasks = new int[capacity];
                    for (int i = 0; i < taskCount; i++) {
                        newTasks[i] = tasksList[i];
                    }
                    delete[] tasksList;
                    tasksList = newTasks;
                }

                cout << "Введите id задачи: ";
                cin >> Id;

                tasksList[taskCount] = Id;
                taskCount++;
                cout << "Задача номер " << Id << " успешно добавлена" << endl;
                break;
            case 2:
                if (taskCount == 0) {
                    cout << "Список задач пуст" << endl;
                    continue;
                } else {
                    cout << "Текущие задачи: ";
                    for (int i = 0; i < taskCount; i++) {
                        cout << tasksList[i] << ", ";
                    }
                    cout << endl;
                    int deleteId;
                    cout << "Введите номер задачи, которую нужно удалить: ";
                    cin >> deleteId;

                    bool found = false;
                    for (int i = 0; i < taskCount; i++) {
                        if (tasksList[i] == deleteId) {
                            found = true;
                            for (int j = i; j < taskCount - 1; j++) {
                                tasksList[j] = tasksList[j + 1];
                            }
                            taskCount--;
                            cout << "Задача номер " << deleteId << " удалена" << endl;
                            break; 
                        }
                    }

                    if (!found) {
                        cout << "Задача с номером " << deleteId << " не найдена" << endl;
                    }
                }
                break;
            case 3:
                if (taskCount == 0) {
                    cout << "Список задач пуст" << endl;
                } else {
                    cout << "Текущие задачи: ";
                    for (int i = 0; i < taskCount; i++) {
                        cout << tasksList[i] << " ";
                    }
                    cout << endl;
                }
                break;
            case 4:
                delete[] tasksList;
                return 0;
            default:
                cout << "Неверная опция. Попробуйте снова." << endl;
                break;
        }

        cout << endl << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "Пока-пока!";
}
