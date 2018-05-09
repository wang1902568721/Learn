#include <Windows.h>
#include <atlstr.h>
#include <iostream>
using namespace std;
#include <stdio.h>

typedef struct _St_Test
{
	int iNum;
	CString str;
}ST_TEST;

void test()
{
	ST_TEST stTest[3];

	for (int iIndex = 0; iIndex<10; iIndex++)
	{
		stTest[0].iNum = iIndex;
		stTest[0].str = "中国江苏扬州";

		stTest[1].iNum = iIndex + 1;
		stTest[1].str = "中国江苏扬州--China.JiangSu.Yangzhou";

		stTest[2].iNum = iIndex + 2;
		stTest[2].str = "中国江苏扬州--China.JiangSu.Yangzhou--225231";

		cout << stTest[0].iNum << "\t" << stTest[0].str << endl;
		cout << stTest[1].iNum << "\t" << stTest[1].str << endl;
		cout << stTest[2].iNum << "\t" << stTest[2].str << endl;
	}
}
void strAndarr()
{
	BYTE barr[4];
	string str;
	//printf("%s\n", str.c_str());
	//cout << str.c_str() << endl;

	barr[0] = 0x30;
	barr[1] = 0x30;
	barr[2] = 0x30;
	barr[3] = 0x31;

	//str = barr;
	//char a = barr[0] +'0';
	//str.append(&a);
	//a = barr[1] + '0';
	//str.append(&a);
	//a = barr[2] + '0';
	//str.append(&a);
	//a = barr[3] + '0';
	//str.append(&a);

	str.append("你好");
	str.assign(barr,barr+4);
	printf("%s\n", str.c_str());
	cout << str.c_str() << endl;
}

void testAnd()
{
	BYTE b = 0x2B;
	if (0x01 == (b&0x01))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
int main()
{
	testAnd();
	system("pause");

	return 0;
}