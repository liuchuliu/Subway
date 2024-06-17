// Flow.cpp: 实现文件
//

#include "pch.h"
#include "Subway.h"
#include "afxdialogex.h"
#include "Flow.h"


// Flow 对话框

IMPLEMENT_DYNAMIC(Flow, CDialogEx)

Flow::Flow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgPassangerFlow, pParent)
{

}

Flow::~Flow()
{
}

void Flow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, f_list);
}


BEGIN_MESSAGE_MAP(Flow, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Flow::OnBnClickedButton2)
END_MESSAGE_MAP()


// Flow 消息处理程序


BOOL Flow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = f_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	f_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	f_list.InsertColumn(0, TEXT("地铁线名"), 0, 116);
	f_list.InsertColumn(1, TEXT("地铁客运量(万人次)"), 0, 116);
	f_list.InsertColumn(2, TEXT("场所客流量(万人次)"), 0, 116);
	f_list.InsertColumn(3, TEXT("客流强度"), 0, 116);
	f_list.InsertColumn(4, TEXT("首趟发车时间"), 0, 116);
	f_list.InsertColumn(5, TEXT("末趟发车时间"), 0, 116);
	ListUpdate();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void Flow::ListUpdate()
{

	f_list.DeleteAllItems();
	CString FilePath = _T(".\\LinesInfo.txt");
	ifstream in(FilePath, ios::in);
	CString str;
	Interface.LINEs.clear();
	if (in.is_open())
	{
		int num;
		in >> num;
		for (int i = 0; i < num; i++)
		{
			Lines ll;
			ll.inputP(in);
			Interface.LINEs.push_back(ll);
		}
	}
	vector<int> flow1, flow2;
	vector<double> flows;
	for (int i = 0; i < 7; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(200, 1200);
		flow1.push_back(dis(gen));
	}
	for (int i = 0; i < 7; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(300, 1600);
		flow2.push_back(dis(gen));
	}
	for (int i = 0; i < 7; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 150);
		flows.push_back((double(dis(gen))) / 100);
	}
	for (int i = 0; i < 7; i++)
	{
		f_list.InsertItem(i, Interface.LINEs[i].line.c_str());
		str.Format(TEXT("%d"), flow1[i]);
		f_list.SetItemText(i, 1, str);
		str.Format(TEXT("%d"), flow2[i]);
		f_list.SetItemText(i, 2, str);
		str.Format(TEXT("%2f"), flows[i]);
		f_list.SetItemText(i, 3, str);
		f_list.SetItemText(i, 4, Interface.LINEs[i].first.c_str());
		f_list.SetItemText(i, 5, Interface.LINEs[i].last.c_str());
	}
}


void Flow::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
