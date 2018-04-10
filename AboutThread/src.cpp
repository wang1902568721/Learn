#include <Windows.h>
#include <iostream>
using namespace std;

__int64 FileTimeToQuadWord(PFILETIME pft)
{
	return (Int64ShllMod32(pft->dwHighDateTime,32)|pft->dwLowDateTime);
}

void PerformLongOperation()
{
	FILETIME ftKernelTimeStart, ftKernelTimeEnd;
	FILETIME ftUserTimeStart, ftUserTimeEnd;
	FILETIME ftDummy;

	__int64 qwKernelTimeElapsed, qwUserTimeElapsed, qwTotalTimeElapsed;

	GetThreadTimes(GetCurrentThread(), &ftDummy, &ftDummy, &ftKernelTimeStart, &ftUserTimeStart);

	//perform complex algorithm here

	//Get ending times
	GetThreadTimes(GetCurrentThread(), &ftDummy, &ftDummy, &ftKernelTimeEnd, &ftUserTimeEnd);

	qwKernelTimeElapsed = FileTimeToQuadWord(&ftKernelTimeEnd) - FileTimeToQuadWord(&ftKernelTimeStart);

	qwUserTimeElapsed = FileTimeToQuadWord(&ftUserTimeEnd) - FileTimeToQuadWord(&ftUserTimeStart);

	qwTotalTimeElapsed = qwKernelTimeElapsed + qwUserTimeElapsed;

}

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