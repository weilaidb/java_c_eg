//============================================================================
// Name        : purevirtualfunction.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
/**
 * 虚指针或虚函数指针是一个虚函数的实现细节。带有虚函数的类中的每一个对象都有一个虚指针指向该类的虚函数表。
 */

/**
 *虚函数的入口地址和普通函数有什么不同？
 *每个虚函数都在vtable中占了一个表项 ，保存着一条跳转到它的入口地址的指令(实际上就是保存了它的入口地址）。当一个包含虚函数的对象（注意，不是对象的指针）被创建的时候，它在
 *头部附加一个指针，指向vtable中相应的位置。调用虚函数的时候，不管你是用什么指针调用的，它先根据vtable找到入口地址再执行，从而实现了”动态联编”。而不像普通函数那样简单地跳转到一个固定地址。
 */

/*
 *RTTI Runtime Type Information
 * 执行时期的类型信息，重要作用是动态判别执行时期的类型。
 * dynamic_cast和typid
 * dynamic_cast用于在类层次结构中漫游，对指针或引用进行自由的向上、向下或交叉转化。
 * typeid则用于获取一个对象或引用的确切类型。
 * 一般来讲，能用虚函数解决的问题就不要用dynamic_cast
 * 能够用dynamic_cast解决的就不要用typeid。
 *
 *
 *
 */

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
