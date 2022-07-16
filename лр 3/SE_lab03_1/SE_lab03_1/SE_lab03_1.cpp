// task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int func(int a)
{
	return 0;
}
int main()
{
	int n = 1;
	//Задание 2
	int x = n + 9;
	int y = 10 + n;
	int z = 11 + n;
	float s = 1.0 + n;
	//Задание 4
	bool a = true;
	bool b = false;
	//Задание 5
	char ch1 = 'l';
	//Задание 6
	char ch2 = 'л';
	//Задание 7
	wchar_t wch1 = L'g';
	//Задание 8
	wchar_t wch2 = L'г';
	//Задание 9

	short sh = x;   //А

	short msh = -x;  //FFFF FFFF FFFF FFEB 0xfff6

	//8
	short s_b = 0x7fff;
	short s_sm = 0x8000;

	//9
	unsigned short uns_b = 0xffff;
	unsigned short uns_sm = 0x0000;

	//10
	int y_f = y; //16
	int y_s = -y; //FFFF FFFF FFFF FFEA

	//11
	int i_b = 0x7FFFFFFF; //2147483647
	int i_sm = 0x80000000; //-2147483648

	//12
	unsigned int ui_big = 0xffffffff;
	unsigned int ui_small = 0x00000000;

	//13
	long z_f = z; //17
	long z_s = -z; //FFFF FFFF FFFF FFE9

	//14
	long l_b = 0x7FFFFFFF; // -2147483647
	long l_sm = 0x80000000; // -2147483648

	//15
	unsigned long ul_b = 0xffffffff;
	unsigned long ul_sm = 0x00000000;

	//16
	float f_f = s; /*D*/
	float f_s = -s; /*FFFF FFF3*/

	//17
	float big = 1.0, little = -1.0, nan;
	big /= 0;// 1.#INF
	little /= 0;// -1.#INF
	nan = sqrt(-1);// -1.#IND

	//18
	double d = 2.0;

	char* ch_p = &ch1;
	wchar_t* wch_p = &wch1;
	short* sh_p = &sh;
	int* y_f_p = &y_f;
	float* f_f_p = &f_f;
	double* d_p = &d;

	cout << ch_p << " " << wch_p << " " << sh_p << " " << y_f_p << " " << f_f_p << " " << d_p << endl;
	ch_p += 3; wch_p += 3; sh_p += 3; y_f_p += 3; f_f_p += 3; d_p += 3;
	cout << ch_p << " " << wch_p << " " << sh_p << " " << y_f_p << " " << f_f_p << " " << d_p << endl;

	//19
	int (*f_p)(int) = func;

	//20
	char& ch_r = ch1; //z
	wchar_t& wch_r = wch1; //ffff
	short& sh_r = sh;//15
	int& y_f_r = y_f;//16
	float& f_f_r = f_f;//13
	double& d_r = d;//2
}