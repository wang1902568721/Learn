/*
add by wangwei 20180402
����ĿΪ��Windows���ı�̡�����ѧϰ��������Ŀ
*/

#include <Windows.h>
#include <iostream>
using namespace std;
#include <stdio.h>

void OutDir()
{
	TCHAR szCurDir[MAX_PATH];
	GetFullPathName(TEXT("c:"), MAX_PATH, szCurDir, NULL);

	printf("%ls\n", szCurDir);
}

int main(int argc,char *argv)
{
	OutDir();
	system("pause");
	return 0;
}