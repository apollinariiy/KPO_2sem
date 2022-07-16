#pragma once
namespace call {
	int _cdecl cdevl(int a, int b, int c); //параметры помещаются в стек справо налево
	int _stdcall cstd(int& a_ref, int b, int c);//параметры помещаются в стек справо налево
	int _fastcall cfst(int a, int b, int c, int d);//первые два в регистрах,, два последние  - в стек	
}