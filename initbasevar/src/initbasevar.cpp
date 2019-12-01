//============================================================================
// Name        : initbasevar.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Base{
protected:
	int i;
public:
	Base(int x){ i = x;}
};


class Derive:public Base
{
private:
	int i ;
public:
	Derive(int x, int y):Base(x)
	{
		i = y;
	}

	void printTotal()
	{
		int total = i + Base::i;
		cout << "total:" << total;
	}

};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Derive d(10,20);
	d.printTotal();
	return 0;
}
