#pragma once
#include "Lines.h"
#include "Person.h"
class Functions
{
public:
	vector<Person> Users;
	vector<Lines> LINEs;
	bool Login(Person pu);
	int Registerr(Person pt, CString sure);
	void BackSave(CString Path);
	Person onlineUser;
	int curIndex; //当前用户索引号
	vector<double> Money;
	vector<vector<string>> TicketHistory;
};