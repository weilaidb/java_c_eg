//============================================================================
// Name        : multiinherit.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory.h>
#include <assert.h>
using namespace std;
class A
{
public:
	void foo(){
		cout << " A foo" << endl;
	};
};


class B
{
public:
	void foo(){
		cout << " B foo" << endl;
	};
};

class C: public A, public B
{
public:
	void foo()
	{
		cout << " C foo" << endl;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	C c;
	c.A::foo();
	c.B::foo();
	c.C::foo();
	c.foo();
	return 0;
}
