#pragma once
class Person
{
public:
	Person();
	Person(string xingming, string mima, string Id);
	string xingming;
	string mima;
	string Id;
	void inputP(ifstream& in);//���뵽����
	void outputF(ofstream& out);//������ļ�
};

