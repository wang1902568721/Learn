/*
add by wangwei 20180402
该项目为《Windows核心编程》进程学习测试用项目
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