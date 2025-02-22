// ЛР_1.cpp Программирование линейных вычеслительных процессов.

#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    
    /*
    //Вариант 1
    const double p = 3.14;
    double a, y, z;

    cout << "Введите число а: ";
    cin >> a;

    y = sin((p/2) + (3*a)) / (1 - sin((3 * a) - p));

    z = 1 / (tan((((5/4)*p)) + ((3/2)*a)));

    cout << "Ответ: "<< y << " " << z;
    */

    /*
    //Вариант 2
    const double p = 3.14;
    double a, y, z;

    cout << "Введите число а: ";
    cin >> a;

    y = cos(a) + sin(a) + cos(3 * a) + sin(3 * a);

    z = 2 * sqrt(2) * cos(a) * sin((p/4) + (2*a));

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 3
    const double p = 3.14;
    double a, y, z, s;

    cout << "Введите число а: ";
    cin >> a;

    s = sin(2 * a);

    y = (sin(2*a) + sin(5*a) - sin(3*a)) / (cos(a) + 1 - 2 * pow(s,2));

    z = 2 * sin(a);

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 4
    const double p = 3.14;
    double a, y, z;

    cout << "Введите число а: ";
    cin >> a;

    y = (sin(2*a) + sin(5*a) - sin(3*a)) / (cos(a) - cos(3*a) + cos(5*a));

    z = tan(3*a);

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 5
    const double p = 3.14;
    double a, y, z, s, c;

    cout << "Введите число а: ";
    cin >> a;

    s = sin(2 * a);
    c = cos(a);

    y = 1 - ((1/4) * pow(s,2)) + cos(2*a);

    z = pow(c,2) + pow(c,4);

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 6
    const double p = 3.14;
    double a, y, z, c1, c2, c3;

    cout << "Введите число а: ";
    cin >> a;

    c1 = cos(a / 2);
    c2 = cos((5 / 2) * a);
    c3 = cos(4 * a);

    y = cos(a) + cos(2*a) + cos(6*a) + cos(7*a);
    z = 4 * c1 * c2 * c3;

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 7
    const double p = 3.14;
    double a, y, z, c1, c2;

    cout << "Введите число а: ";
    cin >> a;

    c1 = cos(((3 / 8) * p) - (a / 4));
    c2 = cos(((11 / 8) * p) + (a / 4));

    y = pow(c1,2) - pow(c2,2);

    z = (sqrt(2) / 2) * sin(a/2);

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 8
    const double p = 3.14;
    double a, y, z, s1, c1;

    cout << "Введите число а: ";
    cin >> a;

    s1 = sin(((3*p) - (2*a)));
    c1 = cos(((5*p) + (2*a)));

    y = 2 * pow(s1,2) * pow(c1,2);

    z = (1/4) - (1/4) * sin((((5/2) * p) - (8*a)));

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 9
    const double p = 3.14;
    double a, b, y, z, s1, s2, c1, c2;

    cout << "Введите число а: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;

    s1 = sin(a) - sin(b);
    s2 = sin(((a - b) / 2));
    c1 = cos(a) - cos(b);
    c2 = cos(a + b);

    y = pow(c1,2) - pow(s1,2);

    z = (-4) * pow(s2,2) * c2;

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 10
    const double p = 3.14;
    double a, b, y, z, s1, s2, c1;

    cout << "Введите число а: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;

    s1 = sin(b);
    s2 = sin(((2*a) - 1));
    c1 = cos(a);

    y = pow(c1,4) + pow(s1,2) + (1/4) * pow(s2,2);

    z = sin(b+a) * sin(b-a);

    cout << "Ответ: " << y << " " << z;
    */

    /*
    //Вариант 11
    const double p = 3.14;
    double a, y, z, s1;

    cout << "Введите число а: ";
    cin >> a;

    s1 = sin(a);

    y = (1 - (2 * pow(s1,2))) / (1 + sin(3*a));

    z = (1 - tan(a)) / (1 + tan(a));

    cout << "Ответ: " << y << " " << z;
    */
    
    /*
    //Вариант 12
    const double p = 3.14;
    double a, y, z, ctg;

    cout << "Введите число а: ";
    cin >> a;

    ctg = 1 / tan((((3/2) * p) - a));

    y = (sin(4*a) / (1 + cos(4*a))) * (cos(2*a) / (1 + cos(2*a)));

    z = ctg;

    cout << "Ответ: " << y << " " << z;
    */
    
    /*
    //Вариант 13
    const double p = 3.14;
    double a, b, y, z;

    cout << "Введите число а: ";
    cin >> a;
    cout << "Введите число b: ";
    cin >> b;

    y = (sin(a) + cos(((2*b) - a))) / (cos(a) - sin(((2*b) - a)));

    z = (1 + sin(2*b)) / cos(2*b);

    cout << "Ответ: " << y << " " << z;
    */
}