#include "Student.h"
#include "Student.h"
#include<stdio.h>
istream& operator>>(istream& in, Student& obj)
{
    cout << "������ѧ����Ϣ" << endl;
    cin >> obj.id;
    cin >> obj.name;
    cin >> obj.score;
    return in;
}

ostream& operator<<(ostream& out, Student& obj)
{
    cout << "ѧ��" << "\t" << "����" << "\t" << "�༶" << endl;
    cout << obj.id << "\t" << obj.name << "\t" << obj.score << endl;
    // TODO: �ڴ˴����� return ���
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

