#pragma once


// CDlgInDll �Ի���

class CDlgInDll : public CDialog
{
	DECLARE_DYNAMIC(CDlgInDll)

public:
	CDlgInDll(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgInDll();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
