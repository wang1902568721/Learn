// CallDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <windows.h>
#include <iostream>
using namespace std;

#include "Header.h"
#include "logfunction.h"

int main()
{
	cout << Max(13, 14) << endl;
	ErrorLog(ERROR, "Test ErrorLog");
	ErrorLog(ERROR, "测试中文");
	ErrorLog(TRACE,"Test TraceLog");
	system("pause");
    return 0;
}

