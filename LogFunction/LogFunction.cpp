// LogFunction.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include "logfunction.h"
#include "errlog.h"

int main()
{
	ErrorLog(ERROR, "Test Errorlog");
	system("pause");
    return 0;
}

