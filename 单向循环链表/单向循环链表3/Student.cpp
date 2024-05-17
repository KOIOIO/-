#include "Student.h"
#include "Student.h"
#include<stdio.h>
istream& operator>>(istream& in, Student& obj)
{
    cout << "请输入学生信息" << endl;
    cin >> obj.id;
    cin >> obj.name;
    cin >> obj.score;
    return in;
}

ostream& operator<<(ostream& out, Student& obj)
{
    cout << "学号" << "\t" << "姓名" << "\t" << "班级" << endl;
    cout << obj.id << "\t" << obj.name << "\t" << obj.score << endl;
    // TODO: 在此处插入 return 语句
    return out;
}

bool Student::operator==(Student obj2)
{
    if (this->id == obj2.id)
        return true;
    else
        return false;
}

bool Student::operator!=(Student obj2)
{
    if (this->id != this->id)
        return true;
    else
        return false;
}

bool Student::operator<=(Student obj2)
{
    if (this->score <= obj2.score)
        return true;
    else
        return false;
}

