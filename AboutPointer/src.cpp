#include <iostream>
using namespace std;
#include <Windows.h>
#include<stdio.h>

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

union obj
{
	union obj *list;
	int iNum;
	//char c[5];
};

void Test4()
{
	obj* freeList[5];
	
	freeList[0] = (obj*)malloc(sizeof(union obj));
	freeList[1] = (obj*)malloc(sizeof(union obj));
	freeList[2] = (obj*)malloc(sizeof(union obj));
	freeList[3] = (obj*)malloc(sizeof(union obj));
	freeList[4] = (obj*)malloc(sizeof(union obj));

	freeList[0]->iNum = 0;
	freeList[1]->iNum = 0;
	freeList[2]->iNum = 0;
	freeList[3]->iNum = 0;
	freeList[4]->iNum = 0;

	obj** mylist = freeList;
	obj *v = *mylist;
	
	cout <<v->iNum<< endl;
	printf("%p %p %p\n",freeList,mylist,*mylist);

}

union unTest
{
	//int i;
	//union unTest * v;
	char *c;
};
int main()
{
	//Test4();
	cout << sizeof(union unTest) << endl;
	cout << sizeof(union obj) << endl;
	system("pause");
	return 0;
}