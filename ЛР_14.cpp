//������� 15

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

struct Employee {
    string surnameInitials; // ������� � ��������
    int birthYear;               // ��� ��������
    string position;        // ���������
    int experience;              // ����
    double salary;               // �����

    // �������� ��������� ��� ����������
    bool operator<(const Employee& other) const {
        return surnameInitials < other.surnameInitials;
    }
};

void writeBinaryFile(const string& filename, const vector<Employee>& employees) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return;
    }

    for (const auto& employee : employees) {
        size_t length = employee.surnameInitials.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(employee.surnameInitials.c_str(), length);
        outFile.write(reinterpret_cast<const char*>(&employee.birthYear), sizeof(employee.birthYear));
        length = employee.position.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(employee.position.c_str(), length);
        outFile.write(reinterpret_cast<const char*>(&employee.experience), sizeof(employee.experience));
        outFile.write(reinterpret_cast<const char*>(&employee.salary), sizeof(employee.salary));
    }

    outFile.close();
}

vector<Employee> readBinaryFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    vector<Employee> employees;

    if (!inFile) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return employees;
    }

    while (true) {
        Employee employee;
        size_t length;

        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        if (inFile.eof()) break; // ����� �����
        employee.surnameInitials.resize(length);
        inFile.read(&employee.surnameInitials[0], length);
        inFile.read(reinterpret_cast<char*>(&employee.birthYear), sizeof(employee.birthYear));

        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        employee.position.resize(length);
        inFile.read(&employee.position[0], length);

        inFile.read(reinterpret_cast<char*>(&employee.experience), sizeof(employee.experience));
        inFile.read(reinterpret_cast<char*>(&employee.salary), sizeof(employee.salary));

        employees.push_back(employee);
    }

    inFile.close();
    return employees;
}

int main() {

    setlocale(LC_ALL, "Russian");

    const string filename = "employees.bin";
    vector<Employee> employees;

    int n;
    cout << "������� ���������� �����������: ";
    cin >> n;

    // ���� ���������� � �����������
    for (int i = 0; i < n; ++i) {
        Employee emp;
        cout << "������� ������� � �������� (��������, ������ �.�.): ";
        cin.ignore(); // ������������� ������� ����� ������
        getline(cin, emp.surnameInitials);
        cout << "������� ��� ��������: ";
        cin >> emp.birthYear;
        cout << "������� ���������: ";
        cin.ignore(); // ������������� ������� ����� ������
        getline(cin, emp.position);
        cout << "������� ����: ";
        cin >> emp.experience;
        cout << "������� �����: ";
        cin >> emp.salary;

        employees.push_back(emp);
    }

    // ������ � �������� ����
    writeBinaryFile(filename, employees);

    // ������ �� ��������� �����
    employees = readBinaryFile(filename);

    // ���������� ����������� �� ������� � ���������
    sort(employees.begin(), employees.end());

    // ������� ����������� � ������� ������������
    int retireesCount = 0;
    int youngSpecialistsCount = 0;

    int currentYear = 2024; // ����� ������������ ���������� chrono ��� ��������� �������� ����
    for (const auto& employee : employees) {
        if (currentYear - employee.birthYear > 60) {
            retireesCount++;
        }
        if (currentYear - employee.birthYear < 25) {
            youngSpecialistsCount++;
        }
    }

    // ����� ���������� ����������� � ������� ������������
    cout << "���������� �����������: " << retireesCount << endl;
    cout << "���������� ������� ������������: " << youngSpecialistsCount << endl;

    return 0;
}