#include<Windows.h>
#include <iostream>
using namespace std;

enum{__ALIGN=10};

int RoundUp(int iInput)
{
	//return ((iInput + __ALIGN - 1) & ~(__ALIGN - 1));
	return (iInput%__ALIGN)==0?(iInput):((iInput/__ALIGN + 1)*__ALIGN);
}

int Index(int bytes)
{
	return ((bytes + __ALIGN - 1) / __ALIGN - 1);
}

void main()
{
	cout<<RoundUp(19)<<endl;
	cout << RoundUp(9) << endl;

	cout << Index(8) << endl;
	cout << Index(15) << endl;
	system("pause");
	return;
}