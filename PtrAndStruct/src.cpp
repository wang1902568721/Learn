
#include <iostream>
using namespace std;
#include "haed.h"

Info::Info()
{
	pStInfo = new stInfo[10];
}

Info::~Info()
{
	delete[]pStInfo;
}

void Info::Show()
{
	for (int i = 0; i < 10; i++)
	{
		if (NULL != pStInfo)
		{
			cout << pStInfo[i].strVar.c_str() << "\t" << pStInfo[i].iNum << endl;
		}
	}
}

void Info::Construct()
{
	for (int i = 0; i < 10; i++)
	{
		if (NULL != pStInfo)
		{
			pStInfo[i].strVar = "²âÊÔÓÃ";
			pStInfo[i].iNum = i;
		}
	}
}

int main()
{
	Info varInfo;
	varInfo.Construct();
	varInfo.Show();
	system("pause");
	return 0;
}