#include <iostream>
using namespace std;
#include <Windows.h>

typedef struct _stTest
{
	int *pInt;
}stTest;
int main()
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

	system("pause");
	return 0;
}