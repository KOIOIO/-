#pragma once
#include"iostream"
#include"template_class.h"
using namespace std;
class Student
{
public:
	int id;
	string name;
	int score;
public:
	friend istream& operator>>(istream& in, Student& obj);
	friend ostream& operator<<(ostream& out, Student& obj);
	bool operator==(Student obj2);
	bool operator!=(Student obj2);
	bool operator<=(Student obj2);
};


