#include <iostream>
#include <Windows.h>
using namespace std;

template<typename T> T func(T i)
{
	T *inum = 0;;
	cout << inum << endl;
	cout << "In func "<<i << endl;
	return 0;
}

void func1()
{
	int iLoop = 0;
	long lStartTime = GetTickCount();
	for (long iIndex = 0; iIndex < 10000000; iIndex++)
	{
		iLoop = iIndex % 100;
	}
	long lEndTime = GetTickCount();
	cout << "back"<<lEndTime - lStartTime << endl;

	lStartTime = GetTickCount();
	for (long iIndex = 0; iIndex < 10000000; ++iIndex)
	{
		iLoop = iIndex % 100;
	}
	lEndTime = GetTickCount();
	cout << "front" << lEndTime - lStartTime << endl;
}
int main()
{
	int i = 5;
	int *p = &i;
	func1();
	system("pause");
	return 0;
}