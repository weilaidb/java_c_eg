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


/**
 *  运行时类型识别RTTI使用时要注意以下几点:
 *  用typeid()返回一个typeinfo对象，也可以用于内部类型，当用于非多态类型时，没有虚函数
 *  用typeid返回的将时基类地址
 *  动态映射dynamic_cast<类型>(变量)可以映射到中间级，将派生类映射到任何一个基类，也
 *  可以在基类之间相互映射。
 *  不能对void指针进行映射。
 *  如果p是指针，typeid(*p)返回 p所指向的派生类类型，typeid(p)返回基类类型;
 *  如果r是引用，typeid(r)返回派生类类型，typeid(&r)返回基类类型。
 *  典型的RTTI是通过在VTABLE中放一个额外的指针实现的。每个新类只产生一个typeinfo
 *  实例，额外指针指向typeinfo，typeid返回对它的一个引用。
 *  动态映射dynamic_cast<目标*><源指针>，先恢复源指针的RTTI信息，再取目标的RTTI信息，比较两者是否相同，或者是目标类型的基类；
 *  由于它需要检查一长串基类列表，故动态映射的开销比typeid大。
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

	/**
	 * 返回基类类型
	 *cp是一个指针，typeid(cp)返回基类型， typeid(*cp)返回派生类型
	 */
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
