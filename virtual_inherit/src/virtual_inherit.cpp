//============================================================================
// Name        : virtual_inherit.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory.h>
//#include <arrsert.h>
using namespace std;


class A{
	char k[3];
public:
	virtual void aa(){};
};
/**
 * 虚拟继承，除了继承k[3]外，还将vptr_A给继承过来了。
 *
 */
class B:public virtual A
{
	char j[3];
public:
	virtual void bb(){};
};

class C:public virtual B
{
	char i[3];
public:
	virtual void cc() {}

};



class D{
//private:
	char k[32];//4
public:
	virtual void aa(){}; //虚函数表地址
	virtual void aaa(){};
	virtual void aaaa(){};
	virtual void aaaaa(){};
	virtual void aaaaaa(){};
	virtual void aaaaaaa(){};
	virtual void aaaaaaaa(){};
	virtual void aaaaaaaaa(){};
};
/**
**此处非虚拟继承的效果是，继续过来的数据是
**数组，虚函数表没有继承过来
**/
class E:public D
{
	char j[3];
public:
	virtual void bb(){};
	virtual void bbb(){};
	virtual void bbbb(){};
	virtual void bbbbb(){};
	virtual void bbbbbb(){};
};

class F:public E
{
	char i[3];
public:
	virtual void cc() {}

};






int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << "sizeof(A):"<< sizeof(A) << endl;
	cout << "sizeof(A):"<< sizeof(B) << endl;
	cout << "sizeof(A):"<< sizeof(C) << endl;

	cout << "sizeof(D):"<< sizeof(D) << endl;
	cout << "sizeof(E):"<< sizeof(E) << endl;
	cout << "sizeof(F):"<< sizeof(F) << endl;


	return 0;
}
