// Buy.cpp: 实现文件
//

#include "pch.h"
#include "Subway.h"
#include "afxdialogex.h"
#include "Buy.h"


// Buy 对话框

IMPLEMENT_DYNAMIC(Buy, CDialogEx)

Buy::Buy(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgBuy, pParent)
	, start(_T(""))
	, end(_T(""))
{

}

Buy::~Buy()
{
}

void Buy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, start);
	DDX_Text(pDX, IDC_EDIT2, end);
}


BEGIN_MESSAGE_MAP(Buy, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Buy::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Buy::OnBnClickedButton1)
END_MESSAGE_MAP()


// Buy 消息处理程序


void Buy::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}


void Buy::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (start == TEXT("") || end == TEXT(""))
	{
		MessageBox(TEXT("请输入完整的出发站和到达站信息"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}
