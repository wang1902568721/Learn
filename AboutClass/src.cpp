#include <iostream>
using namespace std;

class CTest
{
public:
	CTest();
private:
	~CTest();
private:
	int iNum;
};

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

	cin.get();
	return 0;
}