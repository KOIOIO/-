#include "template_class.h"
template<typename T>
ostream& operator<<(ostream& ou, template_class<T>& obj)
{
    template_class<T>* pcurrent = obj.head;
    do
    {
        ou << pcurrent->data << endl;
        pcurrent = pcurrent->next;
    } while (pcurrent != obj.head);
    return ou;
    // TODO: 在此处插入 return 语句
}
template<typename T>
istream& operator>>(istream& in, template_class<T>& obj)
{
    T data;
    in >> data;
    obj.init_list(data);
    return in;

    // TODO: 在此处插入 return 语句
}
