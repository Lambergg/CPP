//Вариант 5

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {

    setlocale(LC_ALL, "Russian");

    const int k = 4; // Размер матрицы
    int F[k][k] = {
        {5, 2, 3, 4},
        {6, 7, 8, 9},
        {10, 11, 12, 13},
        {14, 15, 16, 17}
    };

    // Находим минимальный элемент в матрице
    int minElement = numeric_limits<int>::max();
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (F[i][j] < minElement) {
                minElement = F[i][j];
            }
        }
    }

    // Заменяем простые числа на главной диагонали минимальным элементом
    for (int i = 0; i < k; ++i) {
        if (isPrime(F[i][i])) {
            F[i][i] = minElement;
        }
    }

    // Выводим измененную матрицу на экран
    cout << "Измененная матрица:" << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
