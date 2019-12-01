//============================================================================
// Name        : rtti2.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;




int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int vInt = 10;
	int arr[2] ={10,20};
	int *p = &vInt;
	int **p2p = &p;
	int *parr[2] = {&vInt, &vInt};
	int (*p2arr)[2] = &arr;

	cout << "Declaration [int vInt = 10]       type==" << typeid(vInt).name() << endl;
	cout << "Declaration int arr[2] ={10,20} type==" << typeid(arr).name() << endl;
	cout << "Declaration int *p = &vInt      type==" << typeid(p).name() << endl;
	cout << "Declaration int **p2p = &p                        type==" << typeid(p2p).name() << endl;
	cout << "Declaration int *parr[2] = {&vInt, &vInt}     type==" << typeid(parr).name() << endl;
	cout << "Declaration int (*p2arr)[2] = &arr               type==" << typeid(p2arr).name() << endl;



	return 0;
}
