#include <iostream>
using namespace std;
#include <Windows.h>

typedef struct _stTest
{
	int *pInt;
}stTest;

void Test()
{
	stTest *pStruct = NULL;
	if (NULL != pStruct && NULL != pStruct->pInt)
	{
		cout << "Not Null" << endl;
	}
	else
	{
		cout << "Pointer is NULL " << endl;
	}
}

void Test2()
{
	int * pInt = new int(12);
	cout << *pInt << endl;

	free(pInt);
}

void Test3(unsigned char *pInput)
{
	unsigned char *pStr = NULL;
	pStr = pInput;
	unsigned char uVar;
	uVar = *pStr;
	cout << *pStr << endl;
}
int main()
{
	unsigned char uArr[10] = "ÄãºÃ";
	Test3(uArr);

	system("pause");
	return 0;
}