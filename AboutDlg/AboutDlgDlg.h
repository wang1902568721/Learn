
// AboutDlgDlg.h : ͷ�ļ�
//

#pragma once
#include "SubDlg.h"

// CAboutDlgDlg �Ի���
class CAboutDlgDlg : public CDialogEx
{
// ����
public:
	CAboutDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTDLG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CSubDlg *subDlg;
public:
	afx_msg void OnBnClickedBtnShowsubdlg();
};
