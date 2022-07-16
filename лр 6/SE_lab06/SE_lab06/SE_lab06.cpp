#include "Dictionary.h"
#include "stdafx.h"
using namespace std;
using namespace Dictionary;

#if defined(TEST1)+defined(TEST2)+defined(TEST3)+defined(TEST4)+defined(TEST5)+defined(TEST6)+defined(TEST7)+defined(TEST8)+defined(TEST9)>1
#error "Определено более одного макроса теста"
#endif

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
#ifdef TEST1 //#ifndef – осуществляет условную компиляцию при неопределённости символической константы; 
		Instance test = Create((char*)"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ", 5);
#endif // TEST_CREATE_1
//#endif – конец ветки условной компиляции
#ifdef TEST2
		Instance test = Create((char*)"TEST", 5000000);
#endif // TEST_CREATE_2

#ifdef TEST3
		Instance test = Create((char*)"TEST", 0);
		Entry test_e = { 1,"aaaaa" };
		AddEntry(test, test_e);
#endif // TEST_ADDENTRY_1

#ifdef TEST4
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaa" };
		AddEntry(test, test_e);
		AddEntry(test, test_e);
#endif // TEST_ADDENTRY_2

#ifdef TEST5
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaaaaaa" };
		AddEntry(test, test_e);
		GetEntry(test, 2);
#endif // TEST_GETENTRY_1

#ifdef TEST6
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaaaaaaa" };
		AddEntry(test, test_e);
		DelEntry(test, 2);
#endif // TEST_DELENTRY_1

#ifdef TEST7
		Instance test7 = Create((char*)"TEST", 5);
		Entry test_e7 = { 1,"aaaaaaaaa" }, test_upd_e7 = { 2,"zzzzzzzz" };
		AddEntry(test7, test_e7);
		UpdEntry(test7, 3, test_upd_e7);
#endif // TEST_UPDENTRY_1

#ifdef TEST8
		Instance test = Create((char*)"TEST", 5);
		Entry test_e = { 1,"aaaaaaaaa" }, test_upd_e = { 1,"zzzzzzzz" };
		AddEntry(test, test_e);
		UpdEntry(test, 1, test_upd_e);
#endif // TEST_UPDENTRY_1

#ifdef TEST9
		Instance d1 = Create((char*)"Преподаватели", 5);
		Entry	e1 = { 1,"Гладкий" }, e2 = { 2,"Веялкин" }, e3 = { 3,"Смелов" },
			e4 = { 4, "Убранович" }, e5 = { 5, "Пацей" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		Entry getE = GetEntry(d1, 4);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "Гурин" };
		UpdEntry(d1, 3, newentry1);
		Print(d1);
		Instance d2 = Create((char*)"Студенты", 5);
		Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 4,"Сидоров" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 3, "Николаев" };
		UpdEntry(d2, 4, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
#endif // TEST_DICTIONARY
	}
	catch (char* e) {
		cout << e << endl;
	}
	return 0;
}