#pragma once
#include <windows.h>
#include <string.h>

typedef struct _st_INFO
{
	string strVar;
	int iNum;
}stInfo;

class Info
{
public:
	Info();
	~Info();
	void Show();
	void Construct();
private:
	stInfo *pStInfo;
};