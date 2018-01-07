#include <Windows.h>
#include <atlstr.h>
#include <iostream>
using namespace std;

typedef struct _St_Test
{
	int iNum;
	CString str;
}ST_TEST;

int main()
{
	ST_TEST stTest[3];

	for (int iIndex=0;iIndex<10;iIndex++)
	{
		stTest[0].iNum = iIndex;
		stTest[0].str = "中国江苏扬州";

		stTest[1].iNum = iIndex+1;
		stTest[1].str = "中国江苏扬州--China.JiangSu.Yangzhou";

		stTest[2].iNum = iIndex + 2;
		stTest[2].str = "中国江苏扬州--China.JiangSu.Yangzhou--225231";

		cout << stTest[0].iNum << "\t" << stTest[0].str<< endl;
		cout << stTest[1].iNum << "\t" << stTest[1].str << endl;
		cout << stTest[2].iNum << "\t" << stTest[2].str << endl;
	}
	system("pause");

	return 0;
}