#pragma once
#ifndef LOGLIB
#define LOGLIB_OPER __declspec( dllimport )
#else
#define LOGLIB_OPER __declspec( dllexport )
#endif
#ifdef _cplusplus
extern "C"
{
#endif
	int LOGLIB_OPER Max(int input1,int input2);
#ifdef _cplusplus
}
#endif // _cplusplus
