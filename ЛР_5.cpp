//������� 17

#include <iostream>
using namespace std;

int main() {
    // ���������� �����
    int rows = 6;

    // ������� ���� ��� �����
    for (int i = rows; i > 0; i--) {
        // ���������� ���� ��� ���������
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl; // ������� �� ����� ������
    }

    return 0;
}
