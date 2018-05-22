#include <iostream>
using namespace std;

class CTest
{
public:
	CTest();
private:
	~CTest();
protected:
	int iNum;
	static int iStaticNum;
};

class C1Function
{
public:
	void Func1();
};

void C1Function::Func1()
{
}

int CTest::iStaticNum = 10;

CTest::CTest()
{
	cout << "construct" << endl;
}

CTest::~CTest()
{
	cout << "deconstruct" << endl;
}

int main()
{
	//CTest *pTest = new CTest;
	//cout << CTest::iStaticNum<< endl;

	C1Function cobj;
	cout << sizeof(cobj) << endl;
	cin.get();
	return 0;
}