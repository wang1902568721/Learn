// CallDll.cpp : �������̨Ӧ�ó������ڵ㡣
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
	ErrorLog(ERROR, "��������");
	ErrorLog(TRACE,"Test TraceLog");
	system("pause");
    return 0;
}

