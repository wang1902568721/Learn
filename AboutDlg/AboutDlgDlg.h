
// AboutDlgDlg.h : 头文件
//

#pragma once
#include "SubDlg.h"

// CAboutDlgDlg 对话框
class CAboutDlgDlg : public CDialogEx
{
// 构造
public:
	CAboutDlgDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTDLG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CSubDlg *subDlg;
public:
	afx_msg void OnBnClickedBtnShowsubdlg();
};
