#pragma once
#include "afxdialogex.h"


// Regis 对话框

class Regis : public CDialogEx
{
	DECLARE_DYNAMIC(Regis)

public:
	Regis(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Regis();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgRegis };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString namee;
	CString key1;
	CString key_sure;
	CString iden;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
