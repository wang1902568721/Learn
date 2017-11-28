#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	cout << "Size of LONG " << sizeof(LONG) << endl;
	cout << "Size of WORD " << sizeof(WORD)<<endl;
	cout << "Size of DWORDLONG " << sizeof(DWORDLONG)<<endl;
	cout << "Size of IMAGE_DOS_HEADER "<<sizeof(IMAGE_DOS_HEADER) << endl;
	cout << "Size of IMAGE_NT_HEADERS " << sizeof(IMAGE_NT_HEADERS) << endl;
	cout << "Size of e_lfanew "<<sizeof(IMAGE_DOS_HEADER::e_lfanew)<< endl;
	long a = 0x12345678;
	system("pause");
	return 0;
}