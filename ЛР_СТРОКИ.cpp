//������� 6
// ������� 1
/*
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    string input;
    cout << "������� ������: ";
    getline(cin, input);

    istringstream stream(input);
    string token;
    int sum = 0;
    bool found = false; // ��� ������������, ������� �� �����

    // ��������� ����� �� ������
    while (stream >> token) {
        try {
            // ������� ������������� ����� � ����� �����
            int number = stoi(token);
            sum += number;
            found = true; // ���� ����� �������, ��������� ����
        }
        catch (const invalid_argument& e) {
            // ���� ����� ������ ������������� � �����, ����������
        }
        catch (const out_of_range& e) {
            // ���� ����� ������� �� ������� int, ����������
        }
    }

    if (found) {
        cout << "����� ��������� �����: " << sum << endl;
    }
    else {
        cout << "����� �� ������� � ������." << endl;
    }

    return 0;
}
*/

//������� 2

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void capitalizeFirstLetter(string& str) {
    bool newWord = true; // ���� ��� ����������� ������ ������ �����

    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '.') {
            break; // ���������, ���� ��������� �����
        }
        if (isspace(str[i])) {
            newWord = true; // ������ �������� ����� �����
        }
        else if (newWord) {
            str[i] = toupper(str[i]); // �������� ������ ����� ����� �� ���������
            newWord = false; // ���������� ����
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    string input;
    cout << "������� ������ (�� �����): ";
    getline(cin, input);

    capitalizeFirstLetter(input);

    cout << "���������� ������: " << input << endl;

    return 0;
}
