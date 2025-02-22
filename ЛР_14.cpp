//Вариант 15

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

struct Employee {
    string surnameInitials; // Фамилия и инициалы
    int birthYear;               // Год рождения
    string position;        // Должность
    int experience;              // Стаж
    double salary;               // Оклад

    // Оператор сравнения для сортировки
    bool operator<(const Employee& other) const {
        return surnameInitials < other.surnameInitials;
    }
};

void writeBinaryFile(const string& filename, const vector<Employee>& employees) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи!" << endl;
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
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return employees;
    }

    while (true) {
        Employee employee;
        size_t length;

        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));
        if (inFile.eof()) break; // Конец файла
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
    cout << "Введите количество сотрудников: ";
    cin >> n;

    // Ввод информации о сотрудниках
    for (int i = 0; i < n; ++i) {
        Employee emp;
        cout << "Введите фамилию и инициалы (например, Иванов И.И.): ";
        cin.ignore(); // Игнорирование символа новой строки
        getline(cin, emp.surnameInitials);
        cout << "Введите год рождения: ";
        cin >> emp.birthYear;
        cout << "Введите должность: ";
        cin.ignore(); // Игнорирование символа новой строки
        getline(cin, emp.position);
        cout << "Введите стаж: ";
        cin >> emp.experience;
        cout << "Введите оклад: ";
        cin >> emp.salary;

        employees.push_back(emp);
    }

    // Запись в двоичный файл
    writeBinaryFile(filename, employees);

    // Чтение из двоичного файла
    employees = readBinaryFile(filename);

    // Сортировка сотрудников по фамилии и инициалам
    sort(employees.begin(), employees.end());

    // Подсчет пенсионеров и молодых специалистов
    int retireesCount = 0;
    int youngSpecialistsCount = 0;

    int currentYear = 2024; // Можно использовать библиотеку chrono для получения текущего года
    for (const auto& employee : employees) {
        if (currentYear - employee.birthYear > 60) {
            retireesCount++;
        }
        if (currentYear - employee.birthYear < 25) {
            youngSpecialistsCount++;
        }
    }

    // Вывод количества пенсионеров и молодых специалистов
    cout << "Количество пенсионеров: " << retireesCount << endl;
    cout << "Количество молодых специалистов: " << youngSpecialistsCount << endl;

    return 0;
}