#pragma once
class Lines
{
public:
	Lines();
	Lines(string line, int stations, string status, string first, string last);
	string line;
	int stations;
	string status;
	string first;
	string last;
	void inputP(ifstream& in);//输入到程序
	void outputF(ofstream& out);//输出到文件
};

