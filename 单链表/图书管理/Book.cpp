#include "Book.h"

istream& operator>>(istream& in, Book& obj)
{
    in >> obj.num;
    in >> obj.name;
    in >> obj.maker;
    return in;
    // TODO: �ڴ˴����� return ���
}

ostream& operator<<(ostream& out, Book& obj)
{
    out << obj.num << "\t" << obj.name << "\t" << obj.maker;
    return out;
    // TODO: �ڴ˴����� return ���
}

bool Book::operator==(Book& obj)
{
    if (this->num == obj.num)
        return true;
    else
        return false;
}

bool Book::operator!=(Book& obj)
{
    if (this->num != obj.num)
        return true;
    else
        return false;
}

bool Book::operator<=(Book& obj)
{
    if (this->num <= obj.num)
        return true;
    else
        return false;
}
