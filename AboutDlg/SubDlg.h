#pragma once


// CSubDlg 对话框

class CSubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg)

public:
	CSubDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSubDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUBDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnTest();
};
