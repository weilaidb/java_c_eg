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
 * ����һ�����������������һ��������ֻ�Ǹú���������operater@,����@����������������������в����ĸ���ȡ������������:
 * �������һԪ�ģ�һ�����������Ƕ�Ԫ�ģ�������������
 * ������������ȫ�ֺ���������һԪ�������һ�����������ڶ�Ԫ����������������������������ǳ�Ա����������һԪ�����û�в��������ڶ�Ԫ
 * �������һ����������
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
