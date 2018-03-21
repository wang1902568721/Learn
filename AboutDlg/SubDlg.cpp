// SubDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AboutDlg.h"
#include "SubDlg.h"
#include "afxdialogex.h"


// CSubDlg 对话框

IMPLEMENT_DYNAMIC(CSubDlg, CDialogEx)

CSubDlg::CSubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SUBDLG, pParent)
{

}

CSubDlg::~CSubDlg()
{
}

void CSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSubDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_TEST, &CSubDlg::OnBnClickedBtnTest)
END_MESSAGE_MAP()


// CSubDlg 消息处理程序


void CSubDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CSubDlg::OnBnClickedBtnTest()
{
	// TODO: 在此添加控件通知处理程序代码
	int *p = NULL;
	*(p + 1) = 500;
}
