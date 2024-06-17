// ChangeLine.cpp: 实现文件
//

#include "pch.h"
#include "Subway.h"
#include "afxdialogex.h"
#include "ChangeLine.h"


// ChangeLine 对话框

IMPLEMENT_DYNAMIC(ChangeLine, CDialogEx)

ChangeLine::ChangeLine(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgChange, pParent)
{

}

ChangeLine::~ChangeLine()
{
}

void ChangeLine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Line);
}


BEGIN_MESSAGE_MAP(ChangeLine, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ChangeLine::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ChangeLine::OnBnClickedButton2)
END_MESSAGE_MAP()


// ChangeLine 消息处理程序


BOOL ChangeLine::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Line.AddString("1号线");
	Line.AddString("2号线");
	Line.AddString("3号线&西环线");
	Line.AddString("4号线");
	Line.AddString("5号线");
	Line.AddString("6号线");
	Line.AddString("磁浮快线");

	c_font.CreatePointFont(180, _T("宋体"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&c_font);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void ChangeLine::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}


void ChangeLine::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	int index = Line.GetCurSel();
	Line.GetLBText(index, str);
	string ans;
	switch (index)
	{
	case 0: ans = "文昌阁\t五一广场\n侯家塘\t黄土岭"; break;
	case 1: ans = "溁湾镇\t长沙火车站\n五一广场\t万家丽广场\n沙湾公园\t长沙火车南站"; break;
	case 2: ans = "阜埠河\t侯家塘\n朝阳村\t长沙火车站\n月湖公园北"; break;
	case 3: ans = "六沟垄\t溁湾镇\n阜埠河\t黄土岭\n圭塘\t沙湾公园\n长沙火车南站"; break;
	case 4: ans = "月湖公园北\t万家丽广场\n芙蓉区政府\t圭塘"; break;
	case 5: ans = "文昌阁\t芙蓉区政府\n朝阳村\t六沟垄"; break;
	case 6: ans = "磁浮高铁站\t磁浮机场站"; break;
	default:
		break;
	}
	MessageBox(ans.c_str(), TEXT("换乘站"));
}
