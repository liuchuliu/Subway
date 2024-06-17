// Regis.cpp: 实现文件
//

#include "pch.h"
#include "Subway.h"
#include "afxdialogex.h"
#include "Regis.h"


// Regis 对话框

IMPLEMENT_DYNAMIC(Regis, CDialogEx)

Regis::Regis(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgRegis, pParent)
	, namee(_T(""))
	, key1(_T(""))
	, key_sure(_T(""))
	, iden(_T(""))
{

}

Regis::~Regis()
{
}

void Regis::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, namee);
	DDX_Text(pDX, IDC_EDIT2, key1);
	DDX_Text(pDX, IDC_EDIT4, key_sure);
	DDX_Text(pDX, IDC_EDIT3, iden);
}


BEGIN_MESSAGE_MAP(Regis, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Regis::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Regis::OnBnClickedButton2)
END_MESSAGE_MAP()


// Regis 消息处理程序


void Regis::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (namee == TEXT("") || key1 == TEXT("") || iden == TEXT(""))
	{
		MessageBox(TEXT("请完整填写注册信息"), TEXT("提示"));
	}
	else if (key_sure == TEXT(""))
	{
		MessageBox(TEXT("请再一次填写密码用以真人核验"), TEXT("提示"));
	}
	else if (key_sure != key1)
	{
		MessageBox(TEXT("密码核验失败，请修改"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}


void Regis::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
