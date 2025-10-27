#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

int main() {
    cout << "ПРЕДУПРЕЖДЕНИЕ: Эта программа может вызвать сбой системы!" << endl;
    cout << "Нажмите Enter для продолжения...";
    cin.get();
    
    vector<char*> memoryBlocks;
    const size_t BLOCK_SIZE = 100 * 1024 * 1024; // 100 МБ на блок
    
    try {
        while (true) {
            char* block = new char[BLOCK_SIZE];
            // Заполняем блок данными чтобы память реально выделилась
            for (size_t i = 0; i < BLOCK_SIZE; i += 4096) {
                block[i] = i % 256; // Записываем данные
            }
            memoryBlocks.push_back(block);
            
            cout << "Выделено: " << (memoryBlocks.size() * BLOCK_SIZE / (1024 * 1024)) 
                 << " МБ оперативной памяти" << endl;
            
            // Небольшая задержка чтобы увидеть прогресс
            Sleep(100);
        }
    }
    catch (bad_alloc& e) {
        cout << "Память закончилась! Выделено: " 
             << (memoryBlocks.size() * BLOCK_SIZE / (1024 * 1024)) << " МБ" << endl;
    }
    
    // Очистка (никогда не выполнится если память действительно закончится)
    for (char* block : memoryBlocks) {
        delete[] block;
    }
    
    return 0;
}