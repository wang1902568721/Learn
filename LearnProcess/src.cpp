/*
add by wangwei 20180402
该项目为《Windows核心编程》进程学习测试用项目
*/

#include <Windows.h>
#include <iostream>
using namespace std;
#include <stdio.h>

void OutDir()
{
	TCHAR szCurDir[MAX_PATH];
	GetFullPathName(TEXT("c:"), MAX_PATH, szCurDir, NULL);

	printf("%ls\n", szCurDir);
}

void NewProcess()
{
	STARTUPINFO si = { sizeof(si) };
	SECURITY_ATTRIBUTES saProcess, saThread;
	PROCESS_INFORMATION piProcessB, piProcessC;
	TCHAR szPath[MAX_PATH];

	saProcess.nLength = sizeof(saProcess);
	saProcess.lpSecurityDescriptor = NULL;
	saProcess.bInheritHandle = TRUE;

	saThread.nLength = sizeof(saThread);
	saThread.lpSecurityDescriptor = NULL;
	saThread.bInheritHandle = FALSE;

	lstrcpy(szPath, TEXT("ProcessB"));

	CreateProcess(NULL, szPath, &saProcess, &saThread, FALSE, 0, NULL, NULL, &si, &piProcessB);

	lstrcpy(szPath, TEXT("ProcessC"));
	CreateProcess(NULL, szPath, NULL, NULL, TRUE, 0, NULL, NULL, &si, &piProcessC);

	return;
}

int WaitProcess()
{
	TCHAR szPath[MAX_PATH];
	PROCESS_INFORMATION piProcessB;
	STARTUPINFO si = { sizeof(si) };
	DWORD dwExitCode;

	lstrcpy(szPath, TEXT("NOTEPAD"));
	BOOL bSuccess = CreateProcess(NULL, szPath, NULL, NULL, TRUE, 0, NULL, NULL, &si, &piProcessB);
	if (bSuccess)
	{
		CloseHandle(piProcessB.hThread);
		//等待进程结束
		DWORD dwWaitResult = WaitForSingleObject(piProcessB.hProcess, INFINITE);
		switch (dwWaitResult)
		{
		case WAIT_OBJECT_0:
			cout << "wait object" << endl;
			break;
		case WAIT_ABANDONED:
			cout << "wait abandoned" << endl;
			break;
		case WAIT_TIMEOUT:
			cout << "wait timeout" << endl;
			break;
		}
		GetExitCodeProcess(piProcessB.hProcess, &dwExitCode);
		cout <<"子进程退出码是："<< dwExitCode << endl;
		CloseHandle(piProcessB.hProcess);
	}
	return 0;
}
int main(int argc,char *argv)
{
	WaitProcess();
	system("pause");
	return 0;
}