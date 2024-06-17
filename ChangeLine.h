#pragma once
#include "afxdialogex.h"


// ChangeLine 对话框

class ChangeLine : public CDialogEx
{
	DECLARE_DYNAMIC(ChangeLine)

public:
	ChangeLine(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChangeLine();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgChange };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox Line;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CFont c_font;
};
