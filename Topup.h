#pragma once
#include "afxdialogex.h"


// Topup 对话框

class Topup : public CDialogEx
{
	DECLARE_DYNAMIC(Topup)

public:
	Topup(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Topup();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgTopup };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString mima;
	double qian;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
