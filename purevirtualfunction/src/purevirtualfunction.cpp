//============================================================================
// Name        : purevirtualfunction.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Shape{
public:
	Shape(){}
	~Shape(){}

	/*
	 * 纯虚函数不能初始化一个对象
	 * ..\src\purevirtualfunction.cpp:36: error: cannot declare variable 's1' to be of abstract type 'Shape'
..\src\purevirtualfunction.cpp:12: note:   because the following virtual functions are pure within 'Shape':
	 */
//	virtual void Draw() = 0;



	/*
	 * 虚函数必须实现内容
	 * E:\tarbao\java_c_eg\purevirtualfunction\Debug/../src/purevirtualfunction.cpp:14: undefined reference to `vtable for Shape'
src\purevirtualfunction.o: In function `~Shape':
E:\tarbao\java_c_eg\purevirtualfunction\Debug/../src/purevirtualfunction.cpp:15: undefined reference to `vtable for Shape'
	 */
//	virtual void Draw();
	virtual void Draw(){};
};




int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Shape s1;
	return 0;
}
