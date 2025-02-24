//������� 5

#include <iostream>
#include <algorithm> // ��� sort
#include <vector>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    const int N = 10; // ������ �������
    int X[N] = { 3, -1, 0, 2, -5, 0, 7, -3, 1, 4 }; // ������ �������

    // ������������� ������ �� ��������
    sort(X, X + N, greater<int>()); // ���������� greater ��� ���������� �� ��������

    // �������� ������������� ������
    cout << "������������� ������ �� ��������: ";
    for (int i = 0; i < N; ++i) {
        cout << X[i] << " ";
    }
    cout << endl;

    // ������������� ���������
    int k1 = 0; // ���������� �������������
    int k2 = 0; // ���������� �������������
    int k3 = 0; // ���������� �������

    // ������������ ���������� �������������, ������������� � ������� ���������
    for (int i = 0; i < N; ++i) {
        if (X[i] > 0) {
            ++k1; // �������������
        }
        else if (X[i] < 0) {
            ++k2; // �������������
        }
        else {
            ++k3; // �������
        }
    }

    // ����� �����������
    cout << "���������� ������������� ���������: " << k1 << endl;
    cout << "���������� ������������� ���������: " << k2 << endl;
    cout << "���������� ������� ���������: " << k3 << endl;

    return 0;
}
