
// SubwayDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Subway.h"
#include "SubwayDlg.h"
#include "afxdialogex.h"
#include "Login.h"
#include "Regis.h"
#include "Flow.h"
#include "ChangeLine.h"
#include "Topup.h"
#include "Buy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSubwayDlg 对话框



CSubwayDlg::CSubwayDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SUBWAY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSubwayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, l_list);
}

BEGIN_MESSAGE_MAP(CSubwayDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSubwayDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSubwayDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CSubwayDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CSubwayDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON10, &CSubwayDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CSubwayDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON5, &CSubwayDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CSubwayDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CSubwayDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CSubwayDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CSubwayDlg 消息处理程序

BOOL CSubwayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	DWORD dwStyle = l_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	l_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	l_list.InsertColumn(0, TEXT("地铁线名"), 0, 116);
	l_list.InsertColumn(1, TEXT("地铁站数"), 0, 116);
	l_list.InsertColumn(2, TEXT("状态"), 0, 116);
	l_list.InsertColumn(3, TEXT("首趟发车时间"), 0, 116);
	l_list.InsertColumn(4, TEXT("末趟发车时间"), 0, 116);

	l_font.CreatePointFont(220, _T("黑体"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&l_font);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSubwayDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSubwayDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSubwayDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSubwayDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == false)
	{
		Login ll;
		if (ll.DoModal() == IDOK)
		{
			Person Per(ll.name.GetBuffer(), ll.keyword.GetBuffer(), ll.idd.GetBuffer());
			flag = Interface.Login(Per);
			if (flag)
			{
				MessageBox(TEXT("用户成功登录"), TEXT("提示"));
				UpdateList();
			}
			else
			{
				MessageBox(TEXT("信息错误，请重新登录"), TEXT("提示"));
			}
		}
	}
	else
	{
		MessageBox(TEXT("请勿重复登录"), TEXT("提示"));
	}
}

void CSubwayDlg::UpdateList()
{
	l_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < Interface.LINEs.size(); i++)
	{
		l_list.InsertItem(i, Interface.LINEs[i].line.c_str());
		str.Format(TEXT("%d"), Interface.LINEs[i].stations);
		l_list.SetItemText(i, 1, str);
		l_list.SetItemText(i, 2, Interface.LINEs[i].status.c_str());
		l_list.SetItemText(i, 3, Interface.LINEs[i].first.c_str());
		l_list.SetItemText(i, 4, Interface.LINEs[i].last.c_str());
	}
}


void CSubwayDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Regis r;
	if (IDOK == r.DoModal())
	{
		Person pr(r.namee.GetBuffer(), r.key1.GetBuffer(), r.iden.GetBuffer());
		if (Interface.Registerr(pr, r.key_sure.GetBuffer()) == 1)
		{
			flag = false;//注册成功重新登录
			MessageBox(TEXT("注册成功"), TEXT("提示"));
		}
		else
		{
			MessageBox(TEXT("注册失败"), TEXT("提示"));
		}

	}
}


void CSubwayDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码，通知
	if (flag == true)
	{
		string st = "";
		vector<string> notice;
		vector<string> date;
		CString FilePath = _T(".\\通知公告.txt");
		ifstream in(FilePath, ios::in);
		if (in.is_open())
		{
			int num;
			in >> num;
			for (int i = 0; i < num; i++)
			{
				string tmp1, tmp2;
				in >> tmp1;
				in >> tmp2;
				notice.push_back(tmp1);
				date.push_back(tmp2);

			}
		}
		for (int i = 0; i < notice.size(); i++)
		{
			st += notice[i];
			st += "\t";
			st += date[i];
			st += "\n";
		}
		MessageBox(st.c_str(), TEXT("公告通知"));
	}
	else
	{
		MessageBox(TEXT("请登录以使用本功能"), TEXT("提示"));
	}
}


void CSubwayDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确认退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		exit(0);
	}
	else
	{
		return;
	}
}


void CSubwayDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == true)
	{
		Flow fl;
		if (fl.DoModal() == IDOK)
		{
			//客流
		}
	}
	else
	{
		MessageBox(TEXT("请登录以使用本功能"), TEXT("提示"));
	}
}


void CSubwayDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (flag == true)
	{
		ChangeLine CL;
		if (CL.DoModal() == IDOK)
		{
			//换乘信息
		}
	}
	else
	{
		MessageBox(TEXT("请登录以使用本功能"), TEXT("提示"));
	}
}


void CSubwayDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码，票务查询
	if (flag == true)
	{
		CString str;
		string ans = "";
		double mm = Interface.Money[Interface.curIndex];
		for (int i = 0; i < Interface.TicketHistory[Interface.curIndex].size(); i++)
		{
			ans += Interface.TicketHistory[Interface.curIndex][i];
			ans += "\n";
		}
		str.Format(TEXT("用户：%s\n余额：%2f\n历史购票记录：\n%s"), Interface.onlineUser.xingming.c_str(), mm, ans.c_str());
		MessageBox(str, TEXT("票务查询"));
	}
	else
	{
		MessageBox(TEXT("请登录以使用本功能"), TEXT("提示"));
	}
}


void CSubwayDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码，车辆位置
	if (flag == true)
	{
		int index = l_list.GetSelectionMark();
		int left, right;
		if (index < 7 && index > -1)
		{
			CString str;
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dis(0, 6);
			left = dis(gen);
			std::random_device rd2;
			std::mt19937 gen2(rd2());
			std::uniform_int_distribution<> dis2(0, 6);
			right = dis2(gen2);
			str.Format(TEXT("左侧最近车辆距离%d站\n右侧最近车辆距离%d站"), left, right);
			MessageBox(str, TEXT("提示"));
		}
		else if(index > 7)
		{
			MessageBox(TEXT("请选择运营中的线路"), TEXT("提示"));
		}
		else
		{
			MessageBox(TEXT("请选择线路"), TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("请登录以使用本功能"), TEXT("提示"));
	}
}


void CSubwayDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码，购票
	if (flag == true)
	{
		Buy bb;
		if (IDOK == bb.DoModal())
		{
			double curMoney = Interface.Money[Interface.curIndex];
			if (curMoney < 1.4)
			{
				MessageBox(TEXT("余额不足，请充值"), TEXT("提示"));
			}
			else
			{
				string s = bb.start.GetBuffer();
				string e = bb.end.GetBuffer();
				string h = s + "to" + e;
				Interface.TicketHistory[Interface.curIndex].push_back(h);
				MessageBox(TEXT("购票成功"), TEXT("提示"));
				Interface.Money[Interface.curIndex] -= 1.4;
				CString Path2 = _T(".\\Wallet.txt");
				ofstream out(Path2, ios::out);
				if (out.is_open())
				{
					out << Interface.Money.size() << "\n";
					for (int i = 0; i < Interface.Money.size(); i++)
					{
						out << fixed << setprecision(2) << Interface.Money[i];
						for (int j = 0; j < Interface.TicketHistory[i].size(); j++)
						{
							out << "\t" << Interface.TicketHistory[i][j];
						}
						out << "\t" << "eof" << "\n";
					}
					out.close();
				}
			}
		}
	}
	else
	{
		MessageBox(TEXT("请登录以使用本功能"), TEXT("提示"));
	}
}


void CSubwayDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码，充值
	if (flag == true)
	{
		Topup tt;
		int ff = 0;
		if (tt.DoModal() == IDOK)
		{
			if (Interface.onlineUser.mima == tt.mima.GetBuffer())
			{
				Interface.Money[Interface.curIndex] += tt.qian;
				MessageBox(TEXT("充值成功"), TEXT("提示"));
				CString Path2 = _T(".\\Wallet.txt");
				ofstream out(Path2, ios::out);
				if (out.is_open())
				{
					out << Interface.Money.size() << "\n";
					for (int i = 0; i < Interface.Money.size(); i++)
					{
						out << fixed << setprecision(2) << Interface.Money[i];
						for (int j = 0; j < Interface.TicketHistory[i].size(); j++)
						{
							out << "\t" << Interface.TicketHistory[i][j];
						}
						out <<"\t" << "eof" << "\n";
					}
					out.close();
				}
			}
			else
			{
				if (ff == 3)
				{
					MessageBox(TEXT("身份信息失效，请重新登录"), TEXT("提示"));
					flag = false;
				}
				else {
					MessageBox(TEXT("密码错误，充值失败"), TEXT("提示"));
					ff++;
				}
			}
		}
	}
	else
	{
		MessageBox(TEXT("请登录以使用本功能"), TEXT("提示"));
	}
}
