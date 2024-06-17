#pragma once
class Person
{
public:
	Person();
	Person(string xingming, string mima, string Id);
	string xingming;
	string mima;
	string Id;
	void inputP(ifstream& in);//输入到程序
	void outputF(ofstream& out);//输出到文件
};

