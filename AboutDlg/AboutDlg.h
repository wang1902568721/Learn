
// AboutDlg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAboutDlgApp: 
// �йش����ʵ�֣������ AboutDlg.cpp
//

class CAboutDlgApp : public CWinApp
{
public:
	CAboutDlgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAboutDlgApp theApp;