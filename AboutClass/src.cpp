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
	CTest *pTest = new CTest;
	//cout << CTest::iStaticNum<< endl;
	cin.get();
	return 0;
}