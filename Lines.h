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
	void inputP(ifstream& in);//���뵽����
	void outputF(ofstream& out);//������ļ�
};

