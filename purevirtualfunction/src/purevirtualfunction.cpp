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
 * ��ָ����麯��ָ����һ���麯����ʵ��ϸ�ڡ������麯�������е�ÿһ��������һ����ָ��ָ�������麯����
 */

/**
 *�麯������ڵ�ַ����ͨ������ʲô��ͬ��
 *ÿ���麯������vtable��ռ��һ������ ��������һ����ת��������ڵ�ַ��ָ��(ʵ���Ͼ��Ǳ�����������ڵ�ַ������һ�������麯���Ķ���ע�⣬���Ƕ����ָ�룩��������ʱ������
 *ͷ������һ��ָ�룬ָ��vtable����Ӧ��λ�á������麯����ʱ�򣬲���������ʲôָ����õģ����ȸ���vtable�ҵ���ڵ�ַ��ִ�У��Ӷ�ʵ���ˡ���̬���ࡱ����������ͨ���������򵥵���ת��һ���̶���ַ��
 */

/*
 *RTTI Runtime Type Information
 * ִ��ʱ�ڵ�������Ϣ����Ҫ�����Ƕ�̬�б�ִ��ʱ�ڵ����͡�
 * dynamic_cast��typid
 * dynamic_cast���������νṹ�����Σ���ָ������ý������ɵ����ϡ����»򽻲�ת����
 * typeid�����ڻ�ȡһ����������õ�ȷ�����͡�
 * һ�������������麯�����������Ͳ�Ҫ��dynamic_cast
 * �ܹ���dynamic_cast����ľͲ�Ҫ��typeid��
 *
 *
 *
 */

class Shape{
public:
	Shape(){}
	~Shape(){}

	/*
	 * ���麯�����ܳ�ʼ��һ������
	 * ..\src\purevirtualfunction.cpp:36: error: cannot declare variable 's1' to be of abstract type 'Shape'
..\src\purevirtualfunction.cpp:12: note:   because the following virtual functions are pure within 'Shape':
	 */
//	virtual void Draw() = 0;



	/*
	 * �麯������ʵ������
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
