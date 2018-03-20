#include <windows.h>
#include <DbgHelp.h>
#include <stdlib.h>
#include <iostream>
#pragma comment(lib, "dbghelp.lib")

#ifndef _M_IX86
#error "The following code only works for x86!"
#endif

inline BOOL IsDataSectionNeeded(const WCHAR* pModuleName)
{
	if (pModuleName == 0)
	{
		return FALSE;
	}

	WCHAR szFileName[_MAX_FNAME] = L"";
	_wsplitpath(pModuleName, NULL, NULL, szFileName, NULL);

	if (wcsicmp(szFileName, L"ntdll") == 0)
		return TRUE;

	return FALSE;
}

inline BOOL CALLBACK MiniDumpCallback(PVOID                            pParam,
	const PMINIDUMP_CALLBACK_INPUT   pInput,
	PMINIDUMP_CALLBACK_OUTPUT        pOutput)
{
	if (pInput == 0 || pOutput == 0)
		return FALSE;

	switch (pInput->CallbackType)
	{
	case ModuleCallback:
		if (pOutput->ModuleWriteFlags & ModuleWriteDataSeg)
			if (!IsDataSectionNeeded(pInput->Module.FullPath))
				pOutput->ModuleWriteFlags &= (~ModuleWriteDataSeg);
	case IncludeModuleCallback:
	case IncludeThreadCallback:
	case ThreadCallback:
	case ThreadExCallback:
		return TRUE;
	default:;
	}

	return FALSE;
}

inline void CreateMiniDump(PEXCEPTION_POINTERS pep, LPCTSTR strFileName)
{
	HANDLE hFile = CreateFile(strFileName, GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if ((hFile != NULL) && (hFile != INVALID_HANDLE_VALUE))
	{
		MINIDUMP_EXCEPTION_INFORMATION mdei;
		mdei.ThreadId = GetCurrentThreadId();
		mdei.ExceptionPointers = pep;
		mdei.ClientPointers = NULL;

		MINIDUMP_CALLBACK_INFORMATION mci;
		mci.CallbackRoutine = (MINIDUMP_CALLBACK_ROUTINE)MiniDumpCallback;
		mci.CallbackParam = 0;

		::MiniDumpWriteDump(::GetCurrentProcess(), ::GetCurrentProcessId(), hFile, MiniDumpNormal, (pep != 0) ? &mdei : 0, NULL, &mci);

		CloseHandle(hFile);
	}
}

LONG __stdcall MyUnhandledExceptionFilter(PEXCEPTION_POINTERS pExceptionInfo)
{
	CreateMiniDump(pExceptionInfo, "core.dmp");
	MessageBox(NULL, "Core dump", "Core dump", MB_OK);
	return EXCEPTION_EXECUTE_HANDLER;
}

/* 
此函数一旦成功调用，之后对 SetUnhandledExceptionFilter 的调用将无效
不明白为什么
*/
void DisableSetUnhandledExceptionFilter()
{
	void* addr = (void*)GetProcAddress(LoadLibrary("kernel32.dll"),"SetUnhandledExceptionFilter");

	if (addr)
	{
		unsigned char code[16];
		int size = 0;

		code[size++] = 0x33;
		code[size++] = 0xC0;
		code[size++] = 0xC2;
		code[size++] = 0x04;
		code[size++] = 0x00;

		DWORD dwOldFlag, dwTempFlag;
		VirtualProtect(addr, size, PAGE_READWRITE, &dwOldFlag);
		WriteProcessMemory(GetCurrentProcess(), addr, code, size, NULL);
		VirtualProtect(addr, size, dwOldFlag, &dwTempFlag);
	}
}

void InitMinDump()
{
	//注册异常处理函数
	SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);

	//使SetUnhandledExceptionFilter
	//DisableSetUnhandledExceptionFilter();
}



void test()
{
	std::string s = "abcd";

	try {
		//_asm   int   3
		//int i = 10;
		//i = i / 0;
		int *p = NULL;
		*(p + 1) = 500;
	}
	catch (std::exception& e)
	{
		std::cout << "with exception:[" << e.what() << "]" << std::endl;
	}
	catch (...)
	{
		std::cout << "with unknown exception" << std::endl;
	}
}

void main()
{
	InitMinDump();

	test();

	system("pause");
}


//#include <windows.h>   
//#include <stdio.h>
//
//long   __stdcall   callback(_EXCEPTION_POINTERS*   excp)
//{
//	MessageBox(0, "Error", "error", MB_OK);
//	printf("Error   address   %p/n", excp->ExceptionRecord->ExceptionAddress);
//	printf("CPU   register:/n");
//	printf("eax   %x   ebx   %x   ecx   %x   edx   %x/n", excp->ContextRecord->Eax,
//		excp->ContextRecord->Ebx, excp->ContextRecord->Ecx,
//		excp->ContextRecord->Edx);
//	return   EXCEPTION_EXECUTE_HANDLER;
//}
//
//int   main(int   argc, char*   argv[])
//{
//	SetUnhandledExceptionFilter(callback);
//	_asm   int   3   //只是为了让程序崩溃
//	Sleep(10000);
//	system("pause");
//	return   0;
//}