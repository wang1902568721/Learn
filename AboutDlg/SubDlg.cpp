// SubDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AboutDlg.h"
#include "SubDlg.h"
#include "afxdialogex.h"


// CSubDlg �Ի���

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


// CSubDlg ��Ϣ�������


void CSubDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CSubDlg::OnBnClickedBtnTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int *p = NULL;
	*(p + 1) = 500;
}
