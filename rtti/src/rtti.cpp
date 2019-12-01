//============================================================================
// Name        : rtti.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;
/*
 *RTTI Runtime Type Information
 * ִ��ʱ�ڵ�������Ϣ����Ҫ�����Ƕ�̬�б�ִ��ʱ�ڵ����͡�
 * dynamic_cast��typid
 * dynamic_cast���������νṹ�����Σ���ָ������ý������ɵ����ϡ����»򽻲�ת����
 * typeid�����ڻ�ȡһ����������õ�ȷ�����͡�
 * һ�������������麯�����������Ͳ�Ҫ��dynamic_cast
 * �ܹ���dynamic_cast����ľͲ�Ҫ��typeid��
 *
 *
 *
 */

class Base {
public:
	virtual void funcA() {
		cout << "Base" << endl;
	}
};

class Derive: public Base {
public:
	virtual void funcB() {
		cout << "Derived" << endl;
	}
};

void funcC(Base *p) {
	Derive *pd = dynamic_cast<Derive *>(p);
	if (NULL != pd) {
		pd->funcB();
	} else {
		pd->funcA();
	}
}

void funcD(Base *p)
{
	Derive *pd = NULL;
	if(typeid(*p) == typeid(Derive))
	{
		pd = static_cast<Derive *>(p);
		pd->funcB();
	}
	else
	{
		p->funcA();
	}
}




int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Base *cp = new Derive;

	cout << typeid(cp).name() << endl;
	cout << typeid(*cp).name() << endl;
	funcD(cp);
	funcC(cp);
	Base *dp = new Base;
	cout << typeid(dp ).name() << endl;
	cout << typeid(*dp ).name() << endl;

	/**
	 * ֱ���쳣��.
	 */
//	funcC(dp);
	funcD(dp);

	return 0;
}
