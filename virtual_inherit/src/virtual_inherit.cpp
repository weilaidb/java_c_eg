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
 * ����̳У����˼̳�k[3]�⣬����vptr_A���̳й����ˡ�
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
	virtual void aa(){}; //�麯�����ַ
	virtual void aaa(){};
	virtual void aaaa(){};
	virtual void aaaaa(){};
	virtual void aaaaaa(){};
	virtual void aaaaaaa(){};
	virtual void aaaaaaaa(){};
	virtual void aaaaaaaaa(){};
};
/**
**�˴�������̳е�Ч���ǣ�����������������
**���飬�麯����û�м̳й���
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
