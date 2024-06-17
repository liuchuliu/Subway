// Topup.cpp: 实现文件
//

#include "pch.h"
#include "Subway.h"
#include "afxdialogex.h"
#include "Topup.h"


// Topup 对话框

IMPLEMENT_DYNAMIC(Topup, CDialogEx)

Topup::Topup(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgTopup, pParent)
	, mima(_T(""))
	, qian(0)
{

}

Topup::~Topup()
{
}

void Topup::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mima);
	DDX_Text(pDX, IDC_EDIT2, qian);
}


BEGIN_MESSAGE_MAP(Topup, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Topup::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Topup::OnBnClickedButton2)
END_MESSAGE_MAP()


// Topup 消息处理程序


void Topup::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (mima == TEXT(""))
	{
		MessageBox(TEXT("请填写密码"), TEXT("提示"));
	}
	else if (qian < 0)
	{
		MessageBox(TEXT("请输入合理金额"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}


void Topup::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
