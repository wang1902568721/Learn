#include <Windows.h>
#include <iostream>
using namespace std;

HANDLE hEvent = INVALID_HANDLE_VALUE;
HANDLE hMutex = INVALID_HANDLE_VALUE;

DWORD WINAPI EventFunc1(LPVOID lpParam)
{
	DWORD dwWaitResult = WaitForSingleObject(hEvent, INFINITE);
	if (WAIT_OBJECT_0 == dwWaitResult)
	{
		ResetEvent(hEvent);
		cout << "ThreadFunc1 got the signal" << endl;
	}
	SetEvent(hEvent);
	return 0;
}

DWORD WINAPI EventFunc2(LPVOID lpParam)
{
	DWORD dwWaitResult = WaitForSingleObject(hEvent, INFINITE);
	if (WAIT_OBJECT_0 == dwWaitResult)
	{
		ResetEvent(hEvent);
		cout << "ThreadFunc2 got the signal" << endl;
	}
	SetEvent(hEvent);
	return 0;
}

DWORD WINAPI MutexFunc1(LPVOID lpParam)
{
	DWORD dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	if (WAIT_OBJECT_0 == dwWaitResult)
	{
		cout << "Mutex func 1 got signal" << endl;
	}
	return 0;
}

DWORD WINAPI MutexFunc2(LPVOID lpParam)
{
	DWORD dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	if (WAIT_OBJECT_0 == dwWaitResult)
	{
		cout << "Mutex func 2 got signal" << endl;
	}
	return 0;
}

int TestEvent()
{
	//hMutex = CreateMutex(NULL, FALSE, NULL);
	hEvent = CreateEvent(NULL, TRUE, TRUE, NULL);
	HANDLE hThread1 = CreateThread(NULL, 0, EventFunc1, NULL, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, EventFunc2, NULL, 0, NULL);

	SetEvent(hEvent);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	return 0;
}

int TestMutex()
{
	hMutex = CreateMutex(NULL, FALSE, NULL);
	HANDLE hThread1 = CreateThread(NULL, 0, MutexFunc1, NULL, 0, NULL);
	HANDLE hThread2 = CreateThread(NULL, 0, MutexFunc2, NULL, 0, NULL);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	return 0;
}

int main()
{
	TestMutex();
	system("pause");
	return 0;
}