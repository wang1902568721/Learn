#include <Windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI ThreadFunc(LPVOID lpParameter)
{
	cout << "Thread func 1" << endl;
	Sleep(500);
	cout << "Thread func 2" << endl;
	return 0;
}

int main()
{
	int i = 10;
	DWORD dwThreadID;
	HANDLE hThread;
	hThread = CreateThread(NULL, 0, ThreadFunc,&i , 0, &dwThreadID);
	cout << "Main Thread" << endl;
	TerminateThread(hThread, 0);
	Sleep(100);
	hThread = CreateThread(NULL, 0, ThreadFunc, &i, 0, &dwThreadID);
	system("pause");
	return 0;
}