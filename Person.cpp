#include "pch.h"
#include "Person.h"

Person::Person()
{
}

Person::Person(string xingming, string mima, string Id)
{
	this->xingming = xingming;
	this->mima = mima;
	this->Id = Id;
}

void Person::inputP(ifstream& in)
{
	in >> xingming;
	in >> mima;
	in >> Id;
}

void Person::outputF(ofstream& out)
{
	out << xingming << "\t" << mima << "\t" << Id << "\n";
}
