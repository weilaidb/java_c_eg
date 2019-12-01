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
 * 执行时期的类型信息，重要作用是动态判别执行时期的类型。
 * dynamic_cast和typid
 * dynamic_cast用于在类层次结构中漫游，对指针或引用进行自由的向上、向下或交叉转化。
 * typeid则用于获取一个对象或引用的确切类型。
 * 一般来讲，能用虚函数解决的问题就不要用dynamic_cast
 * 能够用dynamic_cast解决的就不要用typeid。
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
	 * 直接异常了.
	 */
//	funcC(dp);
	funcD(dp);

	return 0;
}
