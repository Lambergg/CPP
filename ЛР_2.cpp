//������� 4

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double alpha, beta;

    // ���� �����
    cout << "������� ���� a (� ��������): ";
    cin >> alpha;
    cout << "������� ���� b (� ��������): ";
    cin >> beta;

    // ���������� ��� ��������
    if (alpha == 90.0 || beta == 90.0) {
        if (alpha == 90.0 && beta == 90.0) {
            cout << "��� �������������." << std::endl;
        }
        else {
            cout << "��� ������������� ��������." << std::endl;
        }
    }
    else if (alpha == beta) {
        cout << "��� �������������� ��������." << std::endl;
    }
    else {
        cout << "��� ������� ��������." << std::endl;
    }

    return 0;
}
