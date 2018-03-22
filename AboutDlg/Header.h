#pragma once
#ifndef LOGLIB
#define LOGLIB_OPER __declspec( dllimport )
#else
#define LOGLIB_OPER __declspec( dllexport )
#endif
extern "C"
{
	int LOGLIB_OPER Max(int input1,int input2);
}