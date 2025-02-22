//Вариант 17

#include <iostream>
using namespace std;

int main() {
    // Количество строк
    int rows = 6;

    // Внешний цикл для строк
    for (int i = rows; i > 0; i--) {
        // Внутренний цикл для звездочек
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl; // Переход на новую строку
    }

    return 0;
}
