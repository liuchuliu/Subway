#pragma once
#include "afxdialogex.h"


// Buy 对话框

class Buy : public CDialogEx
{
	DECLARE_DYNAMIC(Buy)

public:
	Buy(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Buy();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgBuy };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString start;
	CString end;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
