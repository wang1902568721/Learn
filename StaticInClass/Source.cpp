#include <stdio.h>
#include <Windows.h>

class CTest
{
public:
	static int iNum;
};
int CTest::iNum = 10;

int main()
{
	CTest *testObj = new CTest();
	printf("%p",&(CTest::iNum));
	delete testObj;
	testObj = NULL;
	//system("pause");
	return 0;
}