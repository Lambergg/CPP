//Вариант 8

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void writeBinaryFile(const string& filename, const vector<int>& numbers) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(numbers.data()), numbers.size() * sizeof(int));
    outFile.close();
}

vector<int> readBinaryFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    vector<int> numbers;

    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return numbers;
    }

    int number;
    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        numbers.push_back(number);
    }
    inFile.close();
    return numbers;
}

vector<int> getNumbersBeforeMinAfterMax(const vector<int>& numbers) {
    if (numbers.empty()) {
        return {};
    }

    int minIndex = 0;
    int maxIndex = 0;

    // Находим индексы минимального и максимального элементов
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }
        if (numbers[i] > numbers[maxIndex]) {
            maxIndex = i;
        }
    }

    vector<int> result;

    // Добавляем числа до минимального
    for (size_t i = 0; i < minIndex; ++i) {
        result.push_back(numbers[i]);
    }
    // Добавляем числа после максимального
    for (size_t i = maxIndex + 1; i < numbers.size(); ++i) {
        result.push_back(numbers[i]);
    }

    return result;
}

int main() {

    setlocale(LC_ALL, "Russian");

    const string filename = "numbers.bin";
    int n;

    cout << "Введите количество целых чисел (n): ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Записываем данные в двоичный файл
    writeBinaryFile(filename, numbers);

    // Читаем данные из двоичного файла
    vector<int> readNumbers = readBinaryFile(filename);

    // Получаем массив без минимального и максимального
    vector<int> result = getNumbersBeforeMinAfterMax(readNumbers);

    // Вывод результата
    cout << "Числа до минимального и после максимального:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}