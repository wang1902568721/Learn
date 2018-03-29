#include <Windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI ThreadFunc(LPVOID lpParameter)
{
	HANDLE hParent = (HANDLE)lpParameter;
	HANDLE hMine = GetCurrentThread();

	if (hParent == hMine)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal"<< endl;
	}
	return 0;
}

int main()
{
	DWORD dwThreadID;
	HANDLE hThread;
	HANDLE hThreadParent;

	DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &hThreadParent, 0, FALSE, DUPLICATE_SAME_ACCESS);
	hThread = CreateThread(NULL, 0, ThreadFunc,(PVOID)hThreadParent , 0, &dwThreadID);

	system("pause");
	return 0;
}