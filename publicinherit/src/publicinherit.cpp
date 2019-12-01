//============================================================================
// Name        : publicinherit.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Base{
public:
	int val;
	Base(){val = 3;};
};

class Derive: public Base{
public:
	int val;
	Derive(int i){
		val = Base::val + i;
	};
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Derive d(10);
	cout << d.Base::val << endl;
	cout << d.val << endl;
	return 0;
}
