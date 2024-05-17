#pragma once
#include"iostream"
using namespace std;
template<typename T>
class template_class
{
private:
	T data;
public:
	
	template_class<T>*top;
	template_class<T>* next;
public:
	template_class();
	~template_class();
public:
	void print();
	void push(T data);
	void pop(T data);
	void Change(T data);
	void Search(T data);
};

template<typename T>
inline template_class<T>::template_class()
{
	this->next = NULL;
	this->top = NULL;
}

template<typename T>
inline template_class<T>::~template_class()
{
	if (top == NULL)
	{
		
		return;
	}
	else
	{
		template_class<T>* pcurrent = top;
		template_class<T>* curr = NULL;
		while (pcurrent->next != NULL)
		{
			curr = pcurrent;
			pcurrent = pcurrent->next;
			delete curr;
			curr = NULL;
		}
		delete pcurrent;
		pcurrent = NULL;
	}
}

template<typename T>
inline void template_class<T>::print()
{
	if (top == NULL)
	{
		cout << "没有数据" << endl;
		return;
	}
	else
	{
		template_class<T>* pcurrent = top;
		while (pcurrent->next != NULL)
		{
			cout << pcurrent->data << endl;
			pcurrent = pcurrent->next;
		}
		cout << pcurrent->data << endl;
		return;
	}
}

template<typename T>
inline void template_class<T>::push(T data)
{
	template_class<T>* pcurrent = new template_class<T>;
	pcurrent->data = data;
	if (top == NULL)
	{
		top = pcurrent;
	}
	else
	{
		pcurrent->next = top;
		top = pcurrent;
	}
}

template<typename T>
inline void template_class<T>::pop(T data)
{
	if (top == NULL)
	{
		
		return;
	}
	if (top != NULL && top->next == NULL)
	{
		data = top->data;
		delete top;
		top = NULL;
	}
	if (top != NULL && top->next != NULL)
	{
		template_class<T>* curr = top;
		top = top->next;
		data = curr->data;
	
	}
}

template<typename T>
inline void template_class<T>::Change(T data)
{
	template_class<T>* pcurrent = top;
	if (top == NULL)
	{
		cout << "没有数据" << endl;
		return;
	}
	else
	{
		while (pcurrent->data != data)
		{
			pcurrent = pcurrent->next;
		}
		if (pcurrent->next == NULL && pcurrent->data != data)
		{
			cout << "没有目标数据" << endl;
			return;
		}
		else
		{
			T da;
			cout << "请输入数据" << endl;
			cin >> da;
			pcurrent->data = da;
			cout << "更改成功" << endl;
			return;
		}
	}
}

template<typename T>
inline void template_class<T>::Search(T data)
{
	/*template_class<T>* pcurrent = top;
	while (pcurrent->data != data)
	{
		pcurrent = pcurrent->next;
	}
	if (pcurrent->next == NULL && pcurrent->data != data)
	{
		cout << "没有目标数据" << endl;
		return;
	}
	if (pcurrent->next == NULL && pcurrent->data == data)
	{
		cout << pcurrent->data << endl;
		return;
	}
	cout << pcurrent->data << endl;*/

	template_class<T>* pcurrent = top;
	if (top == NULL)
	{
		cout << "没有数据" << endl;
		return;
	}
	else
	{
		while (pcurrent->data != data)
		{
			pcurrent = pcurrent->next;
		}
		if (pcurrent->next == NULL && pcurrent->data != data)
		{
			cout << "没有目标数据" << endl;
			return;
		}
		else
		{
			cout << pcurrent->data << endl;
		}
	}
}





//void test()
//{
//	template_class<int>L;
//	int data;
//	cin >> data;
//	L.push(data);
//	L.print();
//}
//
//int main()
//{
//	test();
//	
//}