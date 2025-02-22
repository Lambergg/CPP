//Вариант 11

/*
#include <iostream>
#include <cmath> // Для функций sin и cos

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    double xn = - 3.14; // Начальное значение
    double xk = - 3.14; // Конечное значение
    double dx = 3.14 / 10; // Шаг изменения x

    double sum = 0.0; // Сумма для z > x
    double product = 1.0; // Произведение для z <= x
    bool firstProduct = true; // Для проверки первого значения произведения

    // Цикл от xn до xk с шагом dx
    for (double x = xn; x <= xk; x += dx) {
        double z = sin(cos(x)); // Вычисляем z

        // Проверяем условия для суммы и произведения
        if (z > x) {
            sum += z; // Суммируем значения z > x
        }
        else {
            if (firstProduct) {
                product = z; // Запоминаем первое значение для произведения
                firstProduct = false;
            }
            else {
                product *= z; // Умножаем на z <= x
            }
        }

        // Выводим каждую третью пару x и z
        static int count = 0; // Счётчик для вывода
        count++;
        if (count % 3 == 0) {
            cout << "x: " << x << ", z: " << z << endl;
        }
    }

    // Выводим результаты
    cout << "Сумма значений z > x: " << sum << endl;
    if (firstProduct) {
        cout << "Произведение значений z <= x: нет значений" << endl;
    }
    else {
        cout << "Произведение значений z <= x: " << product << endl;
    }

    return 0;
}
*/

/*
#include <iostream>
#include <cmath> // Для функций sin и cos

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    double xn = - 3.14; // Начальное значение
    double xk = - 3.14;  // Конечное значение (корректируем на M_PI)
    double dx = 3.14 / 10; // Шаг изменения x

    double sum = 0.0; // Сумма для z > x
    double product = 1.0; // Произведение для z <= x
    bool firstProduct = true; // Для проверки первого значения произведения

    double x = xn; // Начальное значение x
    int count = 0; // Счётчик для вывода

    // Цикл, пока x меньше или равно xk
    while (x <= xk) {
        double z = sin(cos(x)); // Вычисляем z

        // Проверяем условия для суммы и произведения
        if (z > x) {
            sum += z; // Суммируем значения z > x
        }
        else {
            if (firstProduct) {
                product = z; // Запоминаем первое значение для произведения
                firstProduct = false;
            }
            else {
                product *= z; // Умножаем на z <= x
            }
        }

        // Выводим каждую третью пару x и z
        count++;
        if (count % 3 == 0) {
            cout << "x: " << x << ", z: " << z << endl;
        }

        x += dx; // Увеличиваем x на dx
    }

    // Выводим результаты
    cout << "Сумма значений z > x: " << sum << endl;
    if (firstProduct) {
        cout << "Произведение значений z <= x: нет значений" << endl;
    }
    else {
        cout << "Произведение значений z <= x: " << product << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <cmath>   // Для функций sin и cos

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    double xn = - 3.14; // Начальное значение
    double xk = - 3.14;  // Конечное значение (изменено на M_PI для корректного диапазона)
    double dx = 3.14 / 10; // Шаг изменения x

    double sum = 0.0; // Сумма для z > x
    double product = 1.0; // Произведение для z <= x
    bool firstProduct = true; // Для проверки первого значения произведения

    double x = xn; // Начальное значение x
    int count = 0; // Счётчик для вывода

    // Начинаем цикл do while
    do {
        double z = sin(cos(x)); // Вычисляем z

        // Проверяем условия для суммы и произведения
        if (z > x) {
            sum += z; // Суммируем значения z > x
        }
        else {
            if (firstProduct) {
                product = z; // Запоминаем первое значение для произведения
                firstProduct = false;
            }
            else {
                product *= z; // Умножаем на z <= x
            }
        }

        // Выводим каждую третью пару x и z
        count++;
        if (count % 3 == 0) {
            cout << "x: " << x << ", z: " << z << endl;
        }

        x += dx; // Увеличиваем x на dx
    } while (x <= xk); // Условие выхода из цикла

    // Выводим результаты
    cout << "Сумма значений z > x: " << sum << endl;
    if (firstProduct) {
        cout << "Произведение значений z <= x: нет значений" << endl;
    }
    else {
        cout << "Произведение значений z <= x: " << product << endl;
    }

    return 0;
}
