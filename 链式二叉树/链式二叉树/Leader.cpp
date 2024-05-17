#include "Leader.h"

ostream& operator<<(ostream& out, Leader& obj)
{
    out << obj.goverment_level << "\t" << obj.name << endl;
    return out;
    // TODO: 在此处插入 return 语句
}

istream& operator>>(istream& in, Leader& obj)
{
    in >> obj.goverment_level;
    in >> obj.name;
    return in;
    // TODO: 在此处插入 return 语句
}

bool Leader::operator<(Leader& obj)
{
    if (this->goverment_level < obj.goverment_level)
        return true;
    else
        return false;
}

bool Leader::operator>(Leader& obj)
{
    if (this->goverment_level > obj.goverment_level)
        return true;
    else
        return false;
}
