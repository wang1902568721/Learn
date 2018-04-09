#include <Windows.h>
#include <malloc.h>

void StartRestrictProcess()
{
	//Create a job kernel object
	HANDLE hjob = CreateJobObject(NULL, NULL);

	//set some basic restrictions
	JOBOBJECT_BASIC_LIMIT_INFORMATION jobli = { 0 };
	jobli.PriorityClass = IDLE_PRIORITY_CLASS;
	jobli.PerJobUserTimeLimit.QuadPart = 1000000;
	jobli.LimitFlags = JOB_OBJECT_LIMIT_PRIORITY_CLASS | JOB_OBJECT_LIMIT_JOB_TIME;

	SetInformationJobObject(hjob, JobObjectBasicLimitInformation, &jobli, sizeof(jobli));

	//set some UI restrictions 
	JOBOBJECT_BASIC_UI_RESTRICTIONS jobuir;
	jobuir.UIRestrictionsClass = JOB_OBJECT_UILIMIT_NONE;

	jobuir.UIRestrictionsClass |= JOB_OBJECT_UILIMIT_EXITWINDOWS;

	jobuir.UIRestrictionsClass |= JOB_OBJECT_UILIMIT_HANDLES;

	SetInformationJobObject(hjob, JobObjectBasicUIRestrictions, &jobuir, sizeof(jobuir));

	//spawn the process that to be in the job
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	//"CMD"如果用TEXT可能会造成程序崩溃
	CreateProcess(NULL,"CMD", NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);

	//place the process in the job
	AssignProcessToJobObject(hjob, pi.hProcess);

	ResumeThread(pi.hThread);
	CloseHandle(pi.hThread);

	HANDLE h[2];
	h[0] = pi.hProcess;
	h[1] = hjob;

	DWORD dw = WaitForMultipleObjects(2, h, FALSE, INFINITE);
	switch (dw - WAIT_OBJECT_0)
	{
	case 0:
		//The process has terminated ...
		break;
	case 1:
		//All of the job's allotted CPU time was used ...
		break;
	}
}

void EnumProcessIdsInJob(HANDLE hjob)
{
	const int MAX_PROCESS_IDS = 10;
	DWORD cb = sizeof(JOBOBJECT_BASIC_PROCESS_ID_LIST) + (MAX_PROCESS_IDS - 1) * sizeof(DWORD);
	PJOBOBJECT_BASIC_PROCESS_ID_LIST pjobpil = static_cast<PJOBOBJECT_BASIC_PROCESS_ID_LIST>(_alloca(cb));

	pjobpil->NumberOfAssignedProcesses = MAX_PROCESS_IDS;

	QueryInformationJobObject(hjob, JobObjectBasicProcessIdList, pjobpil, cb, &cb);

	for (int x = 0; x < pjobpil->NumberOfProcessIdsInList; x++)
	{

	}
}

int main(int argc, char *argv[])
{
	StartRestrictProcess();
	return 0;
}