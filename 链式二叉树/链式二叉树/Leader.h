#pragma once
#include"iostream"
using namespace std;
class Leader
{
private:
	string name;
	int goverment_level;
public:
	friend ostream& operator<<(ostream& out, Leader& obj);
	friend istream& operator>>(istream& in, Leader& obj);
	bool operator<(Leader& obj);
	bool operator>(Leader& obj);
};

