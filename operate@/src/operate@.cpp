//============================================================================
// Name        : operate@.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*
 * 定义一个重载运算符就像定义一个函数，只是该函数名字是operater@,这里@代表运算符。函数参数表中参数的个数取决于两个因素:
 * 运算符是一元的（一个参数）还是二元的（两个参数）。
 * 运算符被定义成全局函数（对于一元运算符是一个参数，对于二元运算符是两个参数），如果运算符是成员函数（对于一元运算符没有参数，对于二元
 * 运算符是一个参数）。
 *
 */

class A {
private:
	int a;
public:
	A() {
		a = 0;
	};

	void operator++()
	{
		a += 1;
	};

	void operator++(int)
	{
		a += 2;
	};

	friend void print(A &c);
};

void print(A &c)
{
	cout << c.a << endl;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	A classa;
	print(classa);
	++classa;

	print(classa);
	classa++;
	print(classa);

	return 0;
}
