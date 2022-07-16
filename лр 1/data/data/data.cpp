#include <iostream>
#include <cstdlib> 
#include <string>
using namespace std;
int GetNumber(int day, int mounth, int year, int tip);
int GetBitrhdayNumber(int day, int mounth, int year, int tip);
int proverka(int day, int mounth, int year, int tip, int data, int Months[12]);
int nameMounth(int mounth, int Months[12]);
int prazdnik(int day, int mounth, int year, int tip, int data, int Months[12]);

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int day, mounth, year, data, tip, a;
    
    int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    cout << "Введите дату формата ДДММГГГГ" << endl;
    cin >> data;
    year = data % 10000;
    mounth = (data % 1000000 - year) / 10000;
    day = data / 1000000;
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        tip = 1;
    }
    else {
        tip = 0;
    }
    proverka(day, mounth, year, tip, data, Months);
    if (tip == 1) cout << "Високосный" << endl;
    else cout << "Не вискосный" << endl;
    nameMounth( mounth, Months);
    prazdnik(day, mounth, year, tip, data, Months);
    cout << "Порядковый номер введенного дня в году:" << GetNumber(day, mounth, year, tip) << endl;
    cout << "Количество дней до моего дня рождения: " << GetBitrhdayNumber(day, mounth, year, tip) << endl;

}
int proverka(int day, int mounth, int year, int tip, int data, int Months[12]) {
    int count = 0;
    if (mounth > 12) {
        cout << "Неверное формат месяца";
        exit(0);
    }
    while (data > 0) {
        data /= 10;
        count++;
    }

    if (count != 8) {
        cout << "Неверное количество данных или в дату введенна цифра";
        exit(0);
    }
    if ((tip == 0) && (day > Months[mounth - 1]) || (day < 1)) {
        cout << "Неверный формат дня";
        exit(0);
    }
    if ((tip == 1)) {
        Months[1] = 29;
        if ((day > Months[mounth - 1]) || (day < 1)) {
            cout << "Неверный формат дня";
            exit(0);
        }
    }
    
}
int nameMounth(int mounth, int Months[12]) {

    string namemounth1[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
    cout << "Название месяца: " << namemounth1[mounth - 1] << endl;
    return 0;
}
int prazdnik(int day, int mounth, int year, int tip, int data, int Months[12]) {
    int daypr = 256;
    int mounthpr = 1;
    for (int i = 0; daypr > Months[i]; i++) {
        daypr = daypr - Months[i];
        mounthpr++;
    }
    if(mounthpr<10)
    cout << "День программиста:"<< daypr<<"0" << mounthpr << year << endl;
    else
        cout << "День программиста:" << daypr << mounthpr << year << endl;
    return 0;
}
int GetNumber(int day, int mounth, int year, int tip)
{
    int N = day;
    int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (tip == 1)
        Months[1] = 29;

    for (int i = 0; i < mounth - 1; i++)
    {
        N += Months[i];
    }

    return N;

}
int GetBitrhdayNumber(int day, int mounth, int year, int tip)
{
    int N = day;
    int days, Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int i = mounth;
    int bithday, bithmonth, bithyear, databith, bithtip;
    int raznica = 0;
    cout << "Введите дату дня рождения ДДММГГГГ" << endl;
    cin>> databith;
    bithyear = databith % 10000;
    bithmonth = (databith % 1000000 - year) / 10000;
    bithday = databith / 1000000;
    if ((bithyear % 4 == 0) && (bithyear % 100 != 0) || (bithyear % 400 == 0))
    {
        bithtip = 1;
    }
    else {
        bithtip = 0;
    }
    if (tip == 1)
    {
        days = 366;
        Months[1] = 29;
    }
    else days = 365;
    proverka(bithday, bithmonth, bithyear, bithtip, databith, Months);
    if ((mounth >= bithmonth) && (day > bithday)) {
        N = GetNumber(bithday, bithmonth, year, tip) + days - GetNumber(day, mounth, year, tip);
    }
    else { N = GetNumber(bithday, bithmonth, year, tip) - GetNumber(day, mounth, year, tip); }

    return N;
}

