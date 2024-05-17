#pragma once
#define MAXSIZE 8
#include"iostream"
using namespace std;
template<typename T>
class template_Stack
{
private:
	
	T Stack[MAXSIZE];
	int top;
	
public:
	template_Stack();
	bool isEmpty();
	bool isFull();
	bool push(T data);
	bool pop();
	void Change(T data);
	void search(T data);
	void print_Stack();
	void changesize();
};

template<typename T>
inline template_Stack<T>::template_Stack()
{
	top = -1;
}



template<typename T>
inline bool template_Stack<T>::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template<typename T>
inline bool template_Stack<T>::isFull()
{
	if (top == MAXSIZE - 1)
		return true;
	else
		return false;
}

template<typename T>
inline bool template_Stack<T>::push(T data)
{
	/*if (isFull())
	{
		
	}
	else
	{
		top++;
		Stack[top] = data;
		return true;
	}*/
	if (top == MAXSIZE - 1)
	{
		changesize();
		top++;
		Stack[top] = data;
		return true;
	}
	else
	{
		top++;
		Stack[top] == data;
		return true;
	}
}

template<typename T>
inline bool template_Stack<T>::pop()
{
	T data;
	data = Stack[top];
	top--;
	return data;
}

template<typename T>
inline void template_Stack<T>::Change(T data)
{
	int num = top;
	while (Stack[num] != data)
	{
		num--;
	}
	if (num == 0&&Stack[num]!=data)
	{
		return;
	}
	else
	{
		T dat;
		cout << "����������" << endl;
		cin >> dat;
		Stack[num] = dat;
	}
}

template<typename T>
inline void template_Stack<T>::search(T data)
{
	int num = top;
	while (Stack[num] != data)
	{
		num--;
	}
	if (num == 0 && Stack[num] != data)
	{
		return;
	}
	else
	{
		cout << Stack[num] << endl;
	}
}

template<typename T>
inline void template_Stack<T>::print_Stack()
{
	for (int i = top; i >= 0; i--)
	{
		cout << Stack[i] << endl;
	}
}


//
//template<typename T>
//void template_Stack<T>::changesize()
//{
//	T newStack[MAXSIZE * 2];
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		newStackp[i] = Stack[i];
//	}
//	copy()
//}

template<typename T>
void template_Stack<T>::changesize()
{
	// ����һ���µ�ջ����СΪԭ��������
	T newStack[MAXSIZE * 2];

	// ��ԭջ�е�Ԫ�ظ��Ƶ���ջ��
	for (int i = 0; i <= top; i++)
	{
		newStack[i] = Stack[i];
	}

	// ����ջ�Ĵ�С
	MAXSIZE *= 2;

	// ��ԭջָ��ָ����ջ
	for (int i = 0; i <= top; i++)
	{
		Stack[i] = newStack[i];
	}
}


