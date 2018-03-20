#include "logfunction.h"
#include "Header.h"

//#pragma comment(lib, "LogLib.lib")
//int func()
//{
//	ErrorLog(ERROR, "In function Max[%d][%d]", 1, 2);
//	return 0;
//}
int Max(int input1, int input2)
{
	//func();w
	ErrorLog(ERROR, "In function Max[%d][%d]", 1, 2);
	return (input1 > input2 ? input1 : input2);
}