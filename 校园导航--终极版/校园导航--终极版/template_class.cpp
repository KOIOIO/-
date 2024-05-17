#include "template_class.h"
#include "template_class.h"
template<typename T>
istream& operator>>(istream& in, template_class<T>& obj)
{
    T data;
    in >> data;
    obj.init_list(data);
    return in;
    // TODO: 在此处插入 return 语句
}

template<typename T>
ostream& operator<<(ostream& out, template_class<T>& obj)
{
    if (obj.head == NULL)
    {
        return;
    }

    else
    {
        template_class<T>* pcurrent = obj.head;
        do
        {
            out << pcurrent->data << endl;
            pcurrent = pcurrent->next;
        } while (pcurrent->next != NULL);
    }
    return out;
    // TODO: 在此处插入 return 语句
}
