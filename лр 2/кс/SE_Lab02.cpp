
#include "stdafx.h"
int sum(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int main()
{
	int x, y;
	cout << "x:";
	cin >> x;
	cout << "y:";
	cin >> y;

	cout <<"sum:" << sum(x, y) << endl;
	cout << "sub:" << sub(x, y) << endl;
	cout << "mul:" << mul(x, y) << endl;
	system("pause");
}