// DlgInDll.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dlgdll.h"
#include "DlgInDll.h"
#include "afxdialogex.h"


// CDlgInDll �Ի���

IMPLEMENT_DYNAMIC(CDlgInDll, CDialog)

CDlgInDll::CDlgInDll(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

CDlgInDll::~CDlgInDll()
{
}

void CDlgInDll::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgInDll, CDialog)
END_MESSAGE_MAP()


// CDlgInDll ��Ϣ�������
