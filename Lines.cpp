#include "pch.h"
#include "Lines.h"

Lines::Lines()
{
}

Lines::Lines(string line, int stations, string status, string first, string last)
{
	this->line = line;
	this->stations = stations;
	this->status = status;
	this->first = first;
	this->last = last;
}

void Lines::inputP(ifstream& in)
{
	in >> line;
	in >> stations;
	in >> status;
	in >> first;
	in >> last;
}

void Lines::outputF(ofstream& out)
{
	out << line << "\t" << stations << "\t" << status << "\t" << first << "\t" << last << "\n";
}
