//Вариант 6

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

double calculateAverage(const vector<int>& X) {
    if (X.empty()) return 0.0;

    int sum = 0;
    for (int num : X) {
        sum += num;
    }
    return static_cast<double>(sum) / X.size();
}

vector<int> createYArray(const vector<int>& X, double average) {
    vector<int> Y;
    for (int num : X) {
        if (num > average) {
            Y.push_back(num);
        }
    }
    return Y;
}

vector<int> removeNonPrime(vector<int>& arr) {
    vector<int> result;
    for (int num : arr) {
        if (isPrime(num)) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int N;
    cout << "Введите количество элементов массива: ";
    cin >> N;

    if (N <= 0) {
        cout << "Количество элементов должно быть положительным." << endl;
        return 1;
    }

    vector<int> X(N);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    // Вычисляем среднее арифметическое
    double average = calculateAverage(X);
    cout << "Среднее арифметическое: " << average << endl;

    // Создаем массив Y
    vector<int> Y = createYArray(X, average);
    cout << "Элементы, превышающие среднее арифметическое: ";
    for (int num : Y) {
        cout << num << " ";
    }
    cout << endl;

    // Удаляем не простые числа из массива X и Y
    X = removeNonPrime(X);
    Y = removeNonPrime(Y);

    // Выводим оставшиеся элементы
    cout << "Оставшиеся элементы в X (простые): ";
    for (int num : X) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Оставшиеся элементы в Y (простые): ";
    for (int num : Y) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
