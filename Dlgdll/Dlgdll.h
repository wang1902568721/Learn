// Dlgdll.h : Dlgdll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDlgdllApp
// �йش���ʵ�ֵ���Ϣ������� Dlgdll.cpp
//

class CDlgdllApp : public CWinApp
{
public:
	CDlgdllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
