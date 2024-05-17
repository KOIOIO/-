#include "template_class.h"

template<typename T>
ostream& operator<<(ostream& ou, template_list<T>& obj)
{
    template_list<T>* pcurrent = obj.head;
    do
    {
        ou << pcurrent->data << endl;
        pcurrent = pcurrent->next;
    } while (pcurrent != obj.head);
    return ou;
    // TODO: �ڴ˴����� return ���
}
template<typename T>
istream& operator>>(istream& in, template_list<T>& obj)
{
    T data;
    in >> data;
    obj.init_list(data);
    return in;

    // TODO: �ڴ˴����� return ���
}

