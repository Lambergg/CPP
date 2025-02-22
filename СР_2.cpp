/* СР_2.cpp Чему будет равно значение выражений:
int z = x / y++; если int x = 1, y = 2; Ответ: 0
int w = x % ++y, если int x = 1, y = 2; Ответ: 1
int a = ++m + n++ * sizeof(int); если int m = 1, n = 2; Ответ: 10
float a = 4 * m / 0.3 * n; если float m = 1.5; int n = 5; Ответ: 100
int ok = int(0.5 * y) < short(x)++; если int x = 10, y = 3; Ответ: 1
*/


#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	/*
	int x, y, z;
	x = 1;
	y = 2;
	z = x / y++;

	cout << "Ответ: "<< z;
	*/

	/*
	int w, x, y;
	x = 1;
	y = 2;
	w = x % (++y);

	cout << "Ответ: " << w;
	*/

	/*
	int m, n, a;
	m = 1;
	n = 2;
	a = ++m + n++ * sizeof(int);

	cout << "Ответ: " << a;
	*/

	/*
	float a, m;
	int n;
	m = 1.5;
	n = 5;
	a = 4 * m / 0.3 * n;

	cout << "Ответ: " << a;
	*/

	/*
	int x, y, ok;
	x = 10;
	y = 3;
	ok = int(0.5 * y) < short(x++);

	cout << "Ответ: " << ok;
	*/
}