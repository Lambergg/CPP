//Вариант 4

#include <iostream>
#include <vector>

using namespace std;

struct Time {
    int hours;   // Часы
    int minutes; // Минуты

    // Конструктор для удобного создания объектов Time
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // Функция для сложения двух объектов времени
    Time operator+(const Time& t) const {
        int totalMinutes = (hours * 60 + minutes) + (t.hours * 60 + t.minutes);
        return Time(totalMinutes / 60, totalMinutes % 60);
    }

    // Функция для вычисления разницы между двумя объектами времени
    Time operator-(const Time& t) const {
        int totalMinutes1 = hours * 60 + minutes;
        int totalMinutes2 = t.hours * 60 + t.minutes;
        int difference = totalMinutes1 - totalMinutes2;
        if (difference < 0) difference = 0; // Предотвращаем отрицательное время
        return Time(difference / 60, difference % 60);
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    // Время работы прибора за неделю (7 дней)
    vector<pair<Time, Time>> workHours = {
        { Time(9, 0), Time(17, 30) }, // Пн
        { Time(9, 0), Time(17, 30) }, // Вт
        { Time(9, 0), Time(17, 30) }, // Ср
        { Time(9, 0), Time(17, 30) }, // Чт
        { Time(9, 0), Time(17, 30) }, // Пт
        { Time(10, 0), Time(15, 0) }, // Сб
        { Time(0, 0), Time(0, 0) }    // Вс (выходной)
    };

    Time totalWorkTime;

    // Вычисляем общее время работы
    for (const auto& hours : workHours) {
        totalWorkTime = totalWorkTime + (hours.second - hours.first);
    }

    // Вывод общего времени работы
    cout << "Общее время работы прибора за неделю: "
        << totalWorkTime.hours << " часов "
        << totalWorkTime.minutes << " минут." << endl;

    return 0;
}
