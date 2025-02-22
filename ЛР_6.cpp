//������� 8

#include <iostream>

using namespace std;

bool isStrictlyDecreasing(int number) {
    // ����������� ����� � �������������, ���� ��� �������������
    if (number < 0) {
        number = -number;
    }

    int previousDigit = 10; // �������� � 10, ����� ������ ����� ����� � �����
    while (number > 0) {
        int currentDigit = number % 10; // �������� ��������� �����
        if (currentDigit >= previousDigit) {
            return false; // ���� ������� ����� �� ������ ����������, ���������� false
        }
        previousDigit = currentDigit; // ��������� ���������� �����
        number /= 10; // ������� ��������� �����
    }
    return true; // ��� ����� � �������
}

int main() {

    setlocale(LC_ALL, "Russian");

    int number;
    cout << "������� ������������������ ����� ����� (0 ��� �����):" << endl;

    while (true) {
        cin >> number; // ��������� �����

        if (number == 0) {
            break; // ����� ������������������
        }

        // ���������, �������� �� ����� ������ ���������
        if (isStrictlyDecreasing(number)) {
            cout << "1 - ��" << endl; // ��
        }
        else {
            cout << "0 - ���" << endl; // ���
        }
    }

    return 0;
}
