// LogFunction.cpp : 定义控制台应用程序的入口点。
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

