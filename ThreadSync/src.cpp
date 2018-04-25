#include <Windows.h>
#include <iostream>
using namespace std;

HANDLE hEvent = INVALID_HANDLE_VALUE;
HANDLE hMutex = INVALID_HANDLE_VALUE;
HANDLE hTimer = INVALID_HANDLE_VALUE;

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

VOID CALLBACK TimerAPCProc(LPVOID lpArgToCompletionRoutine, DWORD dwTimerLowValue,DWORD dwTimerHighValue)
{
	static int iIndex = 0;
	while (iIndex < 10)
	{
		cout << "TimerAPCProc was running" << endl;
		iIndex++;
		SleepEx(INFINITE, TRUE);
	}
	CancelWaitableTimer(hTimer);
	cout << "TimerAPCProc exit" << endl;
	
}

DWORD WINAPI TimerProc(LPVOID lpParam)
{
	static int iCount = 0;
	do
	{
		DWORD dwWaitResult = WaitForSingleObject(hTimer, INFINITE);
		if (WAIT_OBJECT_0 == dwWaitResult)
		{
			cout << "TimerProc got the signal..." << endl;
			iCount++;
		}
	}while(iCount < 10);
	
	CancelWaitableTimer(hTimer);
	cout << "Thread exit..." << endl;

	return 0;
}
int TestWaitableTimer()
{
	LARGE_INTEGER lDueTime;
	lDueTime.QuadPart = -100000000LL;

	HANDLE hThread = CreateThread(NULL, 0, TimerProc, NULL, CREATE_SUSPENDED, NULL);
	hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	//设置十秒后触发
	SetWaitableTimer(hTimer, &lDueTime, 1*1000, TimerAPCProc, NULL, FALSE);
	ResumeThread(hThread);

	//Sleep(20 * 1000);
	SleepEx(INFINITE,TRUE);
	system("pause");
	CloseHandle(hThread);
	CloseHandle(hTimer);

	return 0;
}
int main()
{
	TestWaitableTimer();
	system("pause");
	return 0;
}