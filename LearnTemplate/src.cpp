#include <iostream>
#include <Windows.h>
using namespace std;
#include <stdio.h>

template<typename T> T func(T i)
{
	T *inum = 0;;
	cout << inum << endl;
	cout << "In func "<<i << endl;
	return 0;
}

//测试for循环前置和后置++的效率
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

template<int inst> int func2()
{
	cout << inst << endl;
	return 0;
}

//奇怪的模板写法
template<int inst>class TestStaticMember
{
public:
	static void Call();
	//{
	//	cout << inst << endl;
	//}
};

template<int inst> void TestStaticMember<inst>::Call()
{
	cout << inst << endl;
}

union obj
{
	union obj* list;
	char s[1];
};
void testunion()
{
	obj * volatile * my_list;
	//printf("%p\n",&my_list);
}

template<typename T=int>void TestDefaultValue()
{
	//T num = 0;
	cout <<typeid(T).name()<< endl;
	//cout << typeid(T2).name() << endl;
}

template<typename T> T func3()
{
	return T();
}
int main()
{
	//TestDefaultValue<double>();
	cout << func3<int>() << endl;
	cout << int(3) << "\t" << double() << endl;
	system("pause");
	return 0;
}