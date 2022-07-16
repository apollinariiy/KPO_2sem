#include <iostream>
#include <cstdlib> 
using namespace std;
int GetNumber(int day, int mounth, int year, int tip);
int GetBitrhdayNumber(int day, int mounth, int year, int tip);
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int day, mounth, year, data, tip, a;
    int count = 0;
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
    
    if (mounth > 12) {
        cout << "Неверное формат месяца";
        exit(0);
    }
    while(data>0) {
        data /= 10;
        count++;
    }
   
    if (count != 8) {
        cout << "Неверное количество данных или в дату введенна цифра";
        exit(0);
    }
    if ((tip==0)&&(day > Months[mounth - 1])||(day<1)) {
            cout << "Неверный формат дня";
            exit(0);
    }
    if ((tip == 1)) {
        Months[1] = 29;
        if ((day > Months[mounth - 1])||(day < 1)) {
            cout << "Неверный формат дня";
            exit(0);
        }
    }
    if (tip == 1) cout << "Високосный" << endl;
    else cout << "Не вискосный" << endl;

    cout << "Порядковый номер введенного дня в году:" << GetNumber(day, mounth, year, tip) << endl;
    cout << "Количество дней до моего дня рождения: " << GetBitrhdayNumber(day, mounth, year, tip) << endl;
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
    int bithday = 11;
    int bithmonth = 3;
    if (tip == 1)
    {
        days = 366;
        Months[1] = 29;
    }
    else days = 365;

    if ((mounth >= 3) || (day > 11)) {
        N = GetNumber(bithday, bithmonth, year, tip) + days - GetNumber(day, mounth, year, tip);
    }
    else { N = GetNumber(bithday, bithmonth, year, tip) - GetNumber(day, mounth, year, tip); }
   
    return N;
}

