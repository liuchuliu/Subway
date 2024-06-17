// Login.cpp: 实现文件
//

#include "pch.h"
#include "Subway.h"
#include "afxdialogex.h"
#include "Login.h"


// Login 对话框

IMPLEMENT_DYNAMIC(Login, CDialogEx)

Login::Login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgLogin, pParent)
	, name(_T(""))
	, keyword(_T(""))
	, idd(_T(""))
{

}

Login::~Login()
{
}

void Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, keyword);
	DDX_Text(pDX, IDC_EDIT3, idd);
}


BEGIN_MESSAGE_MAP(Login, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Login::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Login::OnBnClickedButton2)
END_MESSAGE_MAP()


// Login 消息处理程序


void Login::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (name == TEXT("") || keyword == TEXT("") || idd == TEXT(""))
	{
		MessageBox(TEXT("请补充登录信息"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}


void Login::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
