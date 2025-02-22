//Вариант 8

#include <iostream>

using namespace std;

bool isStrictlyDecreasing(int number) {
    // Преобразуем число в положительное, если оно отрицательное
    if (number < 0) {
        number = -number;
    }

    int previousDigit = 10; // Начинаем с 10, чтобы учесть любую цифру в числе
    while (number > 0) {
        int currentDigit = number % 10; // Получаем последнюю цифру
        if (currentDigit >= previousDigit) {
            return false; // Если текущая цифра не меньше предыдущей, возвращаем false
        }
        previousDigit = currentDigit; // Обновляем предыдущую цифру
        number /= 10; // Удаляем последнюю цифру
    }
    return true; // Все цифры в порядке
}

int main() {

    setlocale(LC_ALL, "Russian");

    int number;
    cout << "Введите последовательность целых чисел (0 для конца):" << endl;

    while (true) {
        cin >> number; // Считываем число

        if (number == 0) {
            break; // Конец последовательности
        }

        // Проверяем, является ли число строго убывающим
        if (isStrictlyDecreasing(number)) {
            cout << "1 - Да" << endl; // Да
        }
        else {
            cout << "0 - Нет" << endl; // Нет
        }
    }

    return 0;
}
