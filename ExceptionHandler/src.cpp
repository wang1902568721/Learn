#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include "ExceptionHandler.h"

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