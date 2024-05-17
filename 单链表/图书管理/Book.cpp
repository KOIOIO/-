#include "Book.h"

istream& operator>>(istream& in, Book& obj)
{
    in >> obj.num;
    in >> obj.name;
    in >> obj.maker;
    return in;
    // TODO: 在此处插入 return 语句
}

ostream& operator<<(ostream& out, Book& obj)
{
    out << obj.num << "\t" << obj.name << "\t" << obj.maker;
    return out;
    // TODO: 在此处插入 return 语句
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
