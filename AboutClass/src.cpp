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

class Construct
{
public:
	Construct();
	Construct(Construct &src);
};

Construct::Construct()
{
	cout << "Construct" << endl;
}
Construct::Construct(Construct &src)
{
	cout << "copy Construct" << endl;
}

class Base
{
private:
	int k;
};
class InitList : public Base
{
public:
	int i;
	int j;
public:
	InitList(InitList&& x) : Base{x.i},j(x.j){}
};
int main()
{
	Construct c1;
	Construct C2 = c1;
	system("pause");
	return 0;
}