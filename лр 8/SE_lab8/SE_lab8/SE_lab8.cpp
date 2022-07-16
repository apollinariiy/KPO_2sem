#include <iostream>
#include "Call.h"
using namespace std;

namespace call {
	int _cdecl cdevl(int a, int b, int c) { return a + b + c; }
	int _stdcall cstd(int& a_ref, int b, int c) { return a_ref * b * c; }
	int _fastcall cfst(int a, int b, int c, int d) { return a + b + c + d; }
}
void main() {
	int a = 10;
	int call_1 = call::cdevl(1, 2, 3);
	int call_2 = call::cstd(a, 2, 3);
	int call_3 = call::cfst(1, 2, 3, 4);
}
