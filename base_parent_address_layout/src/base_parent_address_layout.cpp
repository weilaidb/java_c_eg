//============================================================================
// Name        : base_parent_address_layout.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A
{
	int m_nA;
};

class B
{
	int m_nB;
};

class C: public A, public B
{
	int m_nC;
};





int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	C *pC = new C;
	B* pB = dynamic_cast<B*>(pC);
	A* pA = dynamic_cast<A*>(pC);

	cout << "**********************compare pC and pB" << endl;
	cout << pC << endl;
	cout << pB << endl;
	cout << (C*)pB << endl;
	cout << pC << endl;

	//�˴��Ƚ�ʱ�൱������ת�� pC == (C*)pB
	/*
	 * pBʵ����ָ��ĵ�ַ�Ƕ���C�е�����B���֣��ӵ�ַ�ϸ�pC��һ����ֱ�ӱȽϵ�ַ��ֵ��ʱ����ȡ�
	 *��pC == pB�Ƚ�ʱ��ʵ�����ǱȽ�pCָ��Ķ����(C*)��ʽת��pB��pBָ��Ķ���(pCָ��Ķ���)�Ĳ��֡�
	 */
	if(pC == pB)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}

//	cout << pC << endl;
//	cout << pB << endl;
//	cout << int(pC) << endl;
//	cout << int(pB) << endl;

	if(int(pC) == int(pB))
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}


	cout << "**********************compare pC and pA" << endl;
	cout << pC << endl;
	cout << pA << endl;
	cout << (C*)pA << endl;
	cout << pC << endl;

	if(pC == pA)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}



	if(int(pC) == int(pA))
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}





	delete pC;


	return 0;
}
