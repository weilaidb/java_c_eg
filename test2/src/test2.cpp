//============================================================================
// Name        : test2.cpp
// Author      : aaaa
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T>
class Test;

template<class T>
ostream & operator<<(ostream& out, const Test<T> &obj);

template<class T>
class Test {
private:
	int num;

public:
	Test(int n = 0) {
		num = n;
	}
	Test(const Test<T>& copy) {
		num = copy.num;
	}
	friend ostream & operator<<<>(ostream& out, const Test<T> &obj);

};

template<class T>
ostream& operator<<(ostream& out, const Test<T> &obj) {
	out << obj.num;
	return out;
}

int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Test<int> t(2323);
	cout << t;

	return 0;
}

