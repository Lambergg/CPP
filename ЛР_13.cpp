//������� 8

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void writeBinaryFile(const string& filename, const vector<int>& numbers) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(numbers.data()), numbers.size() * sizeof(int));
    outFile.close();
}

vector<int> readBinaryFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    vector<int> numbers;

    if (!inFile) {
        cerr << "������ �������� ����� ��� ������!" << endl;
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

    // ������� ������� ������������ � ������������� ���������
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] < numbers[minIndex]) {
            minIndex = i;
        }
        if (numbers[i] > numbers[maxIndex]) {
            maxIndex = i;
        }
    }

    vector<int> result;

    // ��������� ����� �� ������������
    for (size_t i = 0; i < minIndex; ++i) {
        result.push_back(numbers[i]);
    }
    // ��������� ����� ����� �������������
    for (size_t i = maxIndex + 1; i < numbers.size(); ++i) {
        result.push_back(numbers[i]);
    }

    return result;
}

int main() {

    setlocale(LC_ALL, "Russian");

    const string filename = "numbers.bin";
    int n;

    cout << "������� ���������� ����� ����� (n): ";
    cin >> n;

    vector<int> numbers(n);
    cout << "������� " << n << " ����� �����:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // ���������� ������ � �������� ����
    writeBinaryFile(filename, numbers);

    // ������ ������ �� ��������� �����
    vector<int> readNumbers = readBinaryFile(filename);

    // �������� ������ ��� ������������ � �������������
    vector<int> result = getNumbersBeforeMinAfterMax(readNumbers);

    // ����� ����������
    cout << "����� �� ������������ � ����� �������������:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}