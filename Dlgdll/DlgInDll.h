#pragma once


// CDlgInDll 对话框

class CDlgInDll : public CDialog
{
	DECLARE_DYNAMIC(CDlgInDll)

public:
	CDlgInDll(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgInDll();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
