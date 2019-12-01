//============================================================================
// Name        : invalidinherit.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class bird
{
public:
	void eat();
	void sleep();
	void fly();
};


class ostrich
{
public:
	bird eat(){cout   << "ostrich eat"<<endl;};
	bird sleep(){cout << "ostrich sleep"<<endl;};
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	ostrich xiaoq;
	xiaoq.eat();
	xiaoq.sleep();
	return 0;
}
