//Вариант 6
// Задание 1
/*
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    istringstream stream(input);
    string token;
    int sum = 0;
    bool found = false; // Для отслеживания, найдены ли числа

    // Извлекаем слова из строки
    while (stream >> token) {
        try {
            // Пробуем преобразовать токен в целое число
            int number = stoi(token);
            sum += number;
            found = true; // Если число найдено, обновляем флаг
        }
        catch (const invalid_argument& e) {
            // Если токен нельзя преобразовать в число, продолжаем
        }
        catch (const out_of_range& e) {
            // Если число выходит за пределы int, игнорируем
        }
    }

    if (found) {
        cout << "Сумма найденных чисел: " << sum << endl;
    }
    else {
        cout << "Числа не найдены в строке." << endl;
    }

    return 0;
}
*/

//Задание 2

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void capitalizeFirstLetter(string& str) {
    bool newWord = true; // Флаг для определения начала нового слова

    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '.') {
            break; // Прерываем, если встречаем точку
        }
        if (isspace(str[i])) {
            newWord = true; // Пробел означает конец слова
        }
        else if (newWord) {
            str[i] = toupper(str[i]); // Заменяем первую букву слова на заглавную
            newWord = false; // Сбрасываем флаг
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    string input;
    cout << "Введите строку (до точки): ";
    getline(cin, input);

    capitalizeFirstLetter(input);

    cout << "Измененная строка: " << input << endl;

    return 0;
}
