#pragma once
#include"iostream"
using namespace std;
class Book
{
private:
	int num;//±àºÅ
	string name;
	string maker;
public:
	friend istream& operator>>(istream& in, Book& obj);
	friend ostream& operator<<(ostream& out, Book& obj);
	bool operator==(Book& obj);
	bool operator!=(Book& obj);
	bool operator<=(Book& obj);
};

