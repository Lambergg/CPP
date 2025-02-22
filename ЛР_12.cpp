//������� 4

#include <iostream>
#include <vector>

using namespace std;

struct Time {
    int hours;   // ����
    int minutes; // ������

    // ����������� ��� �������� �������� �������� Time
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    // ������� ��� �������� ���� �������� �������
    Time operator+(const Time& t) const {
        int totalMinutes = (hours * 60 + minutes) + (t.hours * 60 + t.minutes);
        return Time(totalMinutes / 60, totalMinutes % 60);
    }

    // ������� ��� ���������� ������� ����� ����� ��������� �������
    Time operator-(const Time& t) const {
        int totalMinutes1 = hours * 60 + minutes;
        int totalMinutes2 = t.hours * 60 + t.minutes;
        int difference = totalMinutes1 - totalMinutes2;
        if (difference < 0) difference = 0; // ������������� ������������� �����
        return Time(difference / 60, difference % 60);
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    // ����� ������ ������� �� ������ (7 ����)
    vector<pair<Time, Time>> workHours = {
        { Time(9, 0), Time(17, 30) }, // ��
        { Time(9, 0), Time(17, 30) }, // ��
        { Time(9, 0), Time(17, 30) }, // ��
        { Time(9, 0), Time(17, 30) }, // ��
        { Time(9, 0), Time(17, 30) }, // ��
        { Time(10, 0), Time(15, 0) }, // ��
        { Time(0, 0), Time(0, 0) }    // �� (��������)
    };

    Time totalWorkTime;

    // ��������� ����� ����� ������
    for (const auto& hours : workHours) {
        totalWorkTime = totalWorkTime + (hours.second - hours.first);
    }

    // ����� ������ ������� ������
    cout << "����� ����� ������ ������� �� ������: "
        << totalWorkTime.hours << " ����� "
        << totalWorkTime.minutes << " �����." << endl;

    return 0;
}
