#include <stdio.h>
#include <Windows.h>

#define ErrCode 102

int main()
{
	BYTE bVar = ErrCode;
	int iVar = bVar;
	printf("%d\n", iVar);
	system("pause");
	return 0;
}