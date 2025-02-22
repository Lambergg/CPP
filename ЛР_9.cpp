//������� 6

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
    cout << "������� ���������� ��������� �������: ";
    cin >> N;

    if (N <= 0) {
        cout << "���������� ��������� ������ ���� �������������." << endl;
        return 1;
    }

    vector<int> X(N);
    cout << "������� �������� �������: ";
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    // ��������� ������� ��������������
    double average = calculateAverage(X);
    cout << "������� ��������������: " << average << endl;

    // ������� ������ Y
    vector<int> Y = createYArray(X, average);
    cout << "��������, ����������� ������� ��������������: ";
    for (int num : Y) {
        cout << num << " ";
    }
    cout << endl;

    // ������� �� ������� ����� �� ������� X � Y
    X = removeNonPrime(X);
    Y = removeNonPrime(Y);

    // ������� ���������� ��������
    cout << "���������� �������� � X (�������): ";
    for (int num : X) {
        cout << num << " ";
    }
    cout << endl;

    cout << "���������� �������� � Y (�������): ";
    for (int num : Y) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
