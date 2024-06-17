#include "pch.h"
#include "Functions.h"

bool Functions::Login(Person pu)
{
    CString FilePath1 = _T(".\\users.txt");
    CString FilePath2 = _T(".\\LinesInfo.txt");
    CString FilePath3 = _T(".\\Wallet.txt");
    ifstream in1(FilePath1, ios::in);
    ifstream in2(FilePath2, ios::in);
    ifstream in3(FilePath3, ios::in);
    Users.clear();
    Money.clear();
    TicketHistory.clear();
    int num1, num2;
    if (in1.is_open())
    {
        in1 >> num1;
        for (int i = 0; i < num1; i++)
        {
            Person son;
            son.inputP(in1);
            Users.push_back(son);
        }
    }
    for (int i = 0; i < Users.size(); i++)
    {
        if (pu.xingming == Users[i].xingming && pu.mima == Users[i].mima && pu.Id == Users[i].Id)
        {
            onlineUser = pu;
            curIndex = i;
            LINEs.clear();
            if (in2.is_open())
            {
                in2 >> num2;
                for (int i = 0; i < num2; i++)
                {
                    Lines ll;
                    ll.inputP(in2);
                    LINEs.push_back(ll);
                }
            }
            int num;
            if (in3.is_open())
            {
                in3 >> num;
                vector<vector<string>> History(num + 1);
                for (int i = 0; i < num; i++)
                {
                    double tmp;
                    in3 >> tmp;
                    Money.push_back(tmp);
                    string tr;

                    while (in3 >> tr && tr != "eof")
                    {
                        History[i].push_back(tr);
                    }
                }
                TicketHistory = History;
            }
            return true;
        }
    }
    return false;
}

int Functions::Registerr(Person pt, CString sure)
{
    if (pt.mima.c_str() != sure)
    {
        return 0;
    }
    CString Path = _T(".\\users.txt");
    CString Path2 = _T(".\\Wallet.txt");
    Users.clear();
    Money.clear();
    TicketHistory.clear();
    ifstream in(Path, ios::in); 
    ifstream in2(Path2, ios::in);//同时给新用户注册钱包服务
    int summary,num;
    if (in.is_open())
    {
        in >> summary;
        for (int i = 0; i < summary; i++)
        {
            Person Per;
            Per.inputP(in);
            Users.push_back(Per);
        }
    }
    if (in2.is_open())
    {
        in2 >> num;
        vector<vector<string>> History(num+1);
        for (int i = 0; i < num; i++)
        {
            double tmp;
            in2 >> tmp;
            Money.push_back(tmp);
            string tr;

            while (in2 >> tr && tr != "eof")
            {
                History[i].push_back(tr);
            }
        }
        //History[num].push_back("eof");
        TicketHistory = History;
    }
    //新用户加入
    Users.push_back(pt);
    Money.push_back(0);
    BackSave(Path);
    ofstream out(Path2, ios::out);
    if (out.is_open())
    {
        out << Money.size() << "\n";
        for (int i = 0; i < Money.size(); i++)
        {
            out << fixed << setprecision(2) << Money[i];
            for (int j = 0; j < TicketHistory[i].size(); j++)
            {
                out << "\t" << TicketHistory[i][j];
            }
            out << "\t" << "eof" << "\n";
        }
        out.close();
    }
    return 1;
}

void  Functions::BackSave(CString FilePath)
{
    ofstream out(FilePath, ios::out);
    if (out.is_open())
    {
        out << Users.size() << endl;
        for (int i = 0; i < Users.size(); i++)
        {
            Users[i].outputF(out);
        }
        out.close();
    }
}
