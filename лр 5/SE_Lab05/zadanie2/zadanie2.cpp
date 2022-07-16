
#include <iostream>
using namespace std;
typedef unsigned short nomer;
typedef string tip;
typedef unsigned short balans;
typedef unsigned short data_ot;
typedef string vladelec;
typedef unsigned char podklychenie_sms;
typedef unsigned char podklychenie_bankinga;

struct Klient {
	nomer n;
	tip t;
	balans b;
	data_ot d;
	vladelec v;
	podklychenie_sms sms;
	podklychenie_bankinga ban;
};
bool operator ==(Klient s1, Klient s2) {
	bool rezult;
	if (s1.d == s2.d) { rezult = true; }
	else { rezult = false; }
	return rezult;
}
bool operator >(Klient s1, Klient s2) {
	bool rezult;
	if (s1.b > s2.b) { rezult = true; }
	else { rezult = false; }
	return rezult;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Klient s1 = { 1, "depozit", 550, 2020,"Ivanov",1,1};
	Klient s2 = { 2, "nakopitelniy", 700, 2021,"Peskov",1,0 };
	if (s1 == s2) { cout << "Клиенты открыли банковский счет в одином году\n"; }
	else { cout << "Клиенты открыли банковский счет в разные годы\n"; }
	if (s1 > s2) { cout << "у клиента1 баланс больше, чем у клиент2\n"; }
	else { cout << "у клиента2 баланс больше, чем у клиент1\n"; }
	return 0;
}