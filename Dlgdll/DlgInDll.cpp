// DlgInDll.cpp : 实现文件
//

#include "stdafx.h"
#include "Dlgdll.h"
#include "DlgInDll.h"
#include "afxdialogex.h"


// CDlgInDll 对话框

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


// CDlgInDll 消息处理程序
