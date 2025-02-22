//������� 11

/*
#include <iostream>
#include <cmath> // ��� ������� sin � cos

using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    double xn = - 3.14; // ��������� ��������
    double xk = - 3.14; // �������� ��������
    double dx = 3.14 / 10; // ��� ��������� x

    double sum = 0.0; // ����� ��� z > x
    double product = 1.0; // ������������ ��� z <= x
    bool firstProduct = true; // ��� �������� ������� �������� ������������

    // ���� �� xn �� xk � ����� dx
    for (double x = xn; x <= xk; x += dx) {
        double z = sin(cos(x)); // ��������� z

        // ��������� ������� ��� ����� � ������������
        if (z > x) {
            sum += z; // ��������� �������� z > x
        }
        else {
            if (firstProduct) {
                product = z; // ���������� ������ �������� ��� ������������
                firstProduct = false;
            }
            else {
                product *= z; // �������� �� z <= x
            }
        }

        // ������� ������ ������ ���� x � z
        static int count = 0; // ������� ��� ������
        count++;
        if (count % 3 == 0) {
            cout << "x: " << x << ", z: " << z << endl;
        }
    }

    // ������� ����������
    cout << "����� �������� z > x: " << sum << endl;
    if (firstProduct) {
        cout << "������������ �������� z <= x: ��� ��������" << endl;
    }
    else {
        cout << "������������ �������� z <= x: " << product << endl;
    }

    return 0;
}
*/

/*
#include <iostream>
#include <cmath> // ��� ������� sin � cos

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    double xn = - 3.14; // ��������� ��������
    double xk = - 3.14;  // �������� �������� (������������ �� M_PI)
    double dx = 3.14 / 10; // ��� ��������� x

    double sum = 0.0; // ����� ��� z > x
    double product = 1.0; // ������������ ��� z <= x
    bool firstProduct = true; // ��� �������� ������� �������� ������������

    double x = xn; // ��������� �������� x
    int count = 0; // ������� ��� ������

    // ����, ���� x ������ ��� ����� xk
    while (x <= xk) {
        double z = sin(cos(x)); // ��������� z

        // ��������� ������� ��� ����� � ������������
        if (z > x) {
            sum += z; // ��������� �������� z > x
        }
        else {
            if (firstProduct) {
                product = z; // ���������� ������ �������� ��� ������������
                firstProduct = false;
            }
            else {
                product *= z; // �������� �� z <= x
            }
        }

        // ������� ������ ������ ���� x � z
        count++;
        if (count % 3 == 0) {
            cout << "x: " << x << ", z: " << z << endl;
        }

        x += dx; // ����������� x �� dx
    }

    // ������� ����������
    cout << "����� �������� z > x: " << sum << endl;
    if (firstProduct) {
        cout << "������������ �������� z <= x: ��� ��������" << endl;
    }
    else {
        cout << "������������ �������� z <= x: " << product << endl;
    }

    return 0;
}
*/

#include <iostream>
#include <cmath>   // ��� ������� sin � cos

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    double xn = - 3.14; // ��������� ��������
    double xk = - 3.14;  // �������� �������� (�������� �� M_PI ��� ����������� ���������)
    double dx = 3.14 / 10; // ��� ��������� x

    double sum = 0.0; // ����� ��� z > x
    double product = 1.0; // ������������ ��� z <= x
    bool firstProduct = true; // ��� �������� ������� �������� ������������

    double x = xn; // ��������� �������� x
    int count = 0; // ������� ��� ������

    // �������� ���� do while
    do {
        double z = sin(cos(x)); // ��������� z

        // ��������� ������� ��� ����� � ������������
        if (z > x) {
            sum += z; // ��������� �������� z > x
        }
        else {
            if (firstProduct) {
                product = z; // ���������� ������ �������� ��� ������������
                firstProduct = false;
            }
            else {
                product *= z; // �������� �� z <= x
            }
        }

        // ������� ������ ������ ���� x � z
        count++;
        if (count % 3 == 0) {
            cout << "x: " << x << ", z: " << z << endl;
        }

        x += dx; // ����������� x �� dx
    } while (x <= xk); // ������� ������ �� �����

    // ������� ����������
    cout << "����� �������� z > x: " << sum << endl;
    if (firstProduct) {
        cout << "������������ �������� z <= x: ��� ��������" << endl;
    }
    else {
        cout << "������������ �������� z <= x: " << product << endl;
    }

    return 0;
}
