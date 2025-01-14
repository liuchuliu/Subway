﻿#pragma once
#include "afxdialogex.h"


// Login 对话框

class Login : public CDialogEx
{
	DECLARE_DYNAMIC(Login)

public:
	Login(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Login();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgLogin };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString keyword;
	CString idd;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
