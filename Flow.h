#pragma once
#include "afxdialogex.h"
#include "Functions.h"

// Flow 对话框

class Flow : public CDialogEx
{
	DECLARE_DYNAMIC(Flow)

public:
	Flow(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Flow();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlgPassangerFlow };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl f_list;
	virtual BOOL OnInitDialog();
	void ListUpdate();
	Functions  Interface;
	afx_msg void OnBnClickedButton2();
};
