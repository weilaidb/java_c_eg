//============================================================================
// Name        : fushu_sign_overload.cpp
// Author      : Weilaidb
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;

class classFushu
{
private:
	double shibu, xubu;
public:
	classFushu(){shibu = xubu = 0;}
	classFushu(double r, double i)
	{
		shibu = r, xubu = i;
	}

	classFushu operator + (const classFushu &c);
	classFushu operator - (const classFushu &c);
	classFushu operator * (const classFushu &c);
	classFushu operator / (const classFushu &c);

	friend void print(const classFushu &c);


};

inline classFushu classFushu::operator + (const classFushu &c)
{
	return classFushu(shibu + c.shibu, xubu + c.xubu);
}

inline classFushu classFushu::operator - (const classFushu &c)
{
	return classFushu(shibu - c.shibu, xubu - c.xubu);
}

inline classFushu classFushu::operator * (const classFushu &c)
{
	return classFushu(shibu * c.shibu - xubu * c.xubu, shibu * c.xubu + xubu *  c.shibu);
}

inline classFushu classFushu::operator / (const classFushu &c)
{
	return classFushu((shibu * c.shibu + xubu + c.xubu)/(c.shibu * c.shibu + c.xubu * c.xubu),
			(xubu * c.shibu - shibu * c.xubu)/(c.shibu * c.shibu + c.xubu * c.xubu));
}

void print(const classFushu &c)
{
	if(c.xubu < 0)
	{
		cout << c.shibu << c.xubu << 'i';
	}
	else
	{
		cout << c.shibu << '+' << c.xubu << 'i';
	}
}




int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	classFushu c1(1.0,2.0), c2(3.0, 4.0), c3;
	c3 = c1 + c2;
	cout << "\nc1+c2=";
	print(c3);
	c3 = c1 - c2;
	cout <<"\nc1 - c2=";
	print(c3);

	c3 = c1 * c2;
	cout <<"\nc1 * c2=";
	print(c3);

	c3 = c1 / c2;
	cout <<"\nc1 / c2=";
	print(c3);

	c3 = (c1 + c2) *(c1 - c2) * c2/c1;
	cout <<"\n (c1 + c2) *(c1 - c2) * c2/c1=";
	print(c3);


	return 0;
}
