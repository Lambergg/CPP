//Вариант 4

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double alpha, beta;

    // Ввод углов
    cout << "Введите угол a (в градусах): ";
    cin >> alpha;
    cout << "Введите угол b (в градусах): ";
    cin >> beta;

    // Определяем тип трапеции
    if (alpha == 90.0 || beta == 90.0) {
        if (alpha == 90.0 && beta == 90.0) {
            cout << "Это прямоугольник." << std::endl;
        }
        else {
            cout << "Это прямоугольная трапеция." << std::endl;
        }
    }
    else if (alpha == beta) {
        cout << "Это равнобедренная трапеция." << std::endl;
    }
    else {
        cout << "Это обычная трапеция." << std::endl;
    }

    return 0;
}
