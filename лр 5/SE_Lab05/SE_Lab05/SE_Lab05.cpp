// task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char mounth;
typedef unsigned short year;

struct Date {
	day dd;
	mounth mm;
	year yyyy;
};

bool operator > (Date a, Date b) {
	if (a.yyyy > b.yyyy)
		return true;
	else {
		if (b.yyyy > a.yyyy)
			return false;
		else {
			if (a.mm > b.mm)
				return true;
			else {
				if (b.mm > a.mm)
					return false;
				else {
					if (a.dd > b.dd)
						return true;
					else
						return false;
				}
			}
		}
	}
}

bool operator < (Date a, Date b) {
	if (a.yyyy < b.yyyy)
		return true;
	else {
		if (b.yyyy < a.yyyy)
			return false;
		else {
			if (a.mm < b.mm)
				return true;
			else {
				if (b.mm < a.mm)
					return false;
				else {
					if (a.dd < b.dd)
						return true;
					else
						return false;
				}
			}
		}
	}
}

bool operator ==(Date a, Date b) {
	if (a.dd == b.dd && a.mm == b.mm && a.yyyy == a.yyyy)
		return true;
	else
		return false;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1993 };
	Date date3 = { 7,1,1980 };

	if (date1 < date2)
		cout << "истина\n";
	else
		cout << "ложь\n";

	if (date1 > date2)
		cout << "истина\n";
	else
		cout << "ложь\n";

	if (date1 == date2)
		cout << "истина\n";
	else
		cout << "ложь\n";

	if (date1 == date3)
		cout << "истина\n";
	else
		cout << "ложь\n";
}