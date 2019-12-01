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


/**
 *  ����ʱ����ʶ��RTTIʹ��ʱҪע�����¼���:
 *  ��typeid()����һ��typeinfo����Ҳ���������ڲ����ͣ������ڷǶ�̬����ʱ��û���麯��
 *  ��typeid���صĽ�ʱ�����ַ
 *  ��̬ӳ��dynamic_cast<����>(����)����ӳ�䵽�м伶����������ӳ�䵽�κ�һ�����࣬Ҳ
 *  �����ڻ���֮���໥ӳ�䡣
 *  ���ܶ�voidָ�����ӳ�䡣
 *  ���p��ָ�룬typeid(*p)���� p��ָ������������ͣ�typeid(p)���ػ�������;
 *  ���r�����ã�typeid(r)�������������ͣ�typeid(&r)���ػ������͡�
 *  ���͵�RTTI��ͨ����VTABLE�з�һ�������ָ��ʵ�ֵġ�ÿ������ֻ����һ��typeinfo
 *  ʵ��������ָ��ָ��typeinfo��typeid���ض�����һ�����á�
 *  ��̬ӳ��dynamic_cast<Ŀ��*><Դָ��>���Ȼָ�Դָ���RTTI��Ϣ����ȡĿ���RTTI��Ϣ���Ƚ������Ƿ���ͬ��������Ŀ�����͵Ļ��ࣻ
 *  ��������Ҫ���һ���������б��ʶ�̬ӳ��Ŀ�����typeid��
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
	 * ���ػ�������
	 *cp��һ��ָ�룬typeid(cp)���ػ����ͣ� typeid(*cp)������������
	 */
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
