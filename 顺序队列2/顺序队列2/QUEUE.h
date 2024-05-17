#pragma once
#define QUEUESIZE 8
#include <iostream>
//#define QUEUESIZE 8
using namespace std;

template <typename T>
class Queue
{
public:
	Queue();                          //���������
	~Queue();
	int getSize();                    //��ȡ����
	void enQueue(T& e);        //��β����Ԫ��
	void deQueue();                   //ɾ����ͷԪ��
	void display();             //�����������Ԫ��
	bool isEmpty();             //�ж��Ƿ�Ϊ�ն�
	bool isFull();              //�ж϶��Ƿ�����
	void Change_size();
	//������������������ռ�
private:

	T queue[QUEUESIZE];
	int front;                //��ͷ����βָ��      
	int rear;
	int m_size;               //���г���
};

template<typename T>
inline Queue<T>::Queue()
{
	this->front = 0;
	this->rear = 0;
	this->m_size = 0;
	queue = new T[QUEUESIZE];
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete[] queue;
}

template<typename T>
inline int Queue<T>::getSize()
{
	m_size = rear - front;
	return m_size;
}

template<typename T>
inline void Queue<T>::enQueue(T& e)
{
	if (m_size == QUEUESIZE)
	{
		Change_size();
		return;
	}
	else
	{
		queue[rear] = e;
		rear++;
	}
}

template<typename T>
inline void Queue<T>::deQueue()
{
	if (rear == front)
	{
		cout << "������û��Ԫ��" << endl;
		return;
	}
	else
	{
		front++;
	}
}

template<typename T>
inline void Queue<T>::display()
{
	if (rear == front)
	{
		return;
	}
	else
	{
		for (int i = front; i < rear; i++)
		{
			cout << queue[i] << "\t";
		}
	}
}

template<typename T>
inline bool Queue<T>::isEmpty()
{
	if (rear == front)
	{
		return true;
	}
	else
		return false;
}

template<typename T>
inline bool Queue<T>::isFull()
{
	if (rear - front == QUEUESIZE - 1)
	{
		return true;
	}
	else
		return false;
}

//template<typename T>
//inline void Queue<T>::Change_size()
//{
//	cout << "��������" << endl;
//	int new_size = QUEUESIZE * 2;
//	T* tmp = new T[new_size];
//	copy(queue, queue + QUEUESIZE, tmp);
//	queue = tmp;
//	QUEUESIZE *= 2;
//}

//template <typename T>
//void Queue<T>::Change_size()
//{
//	int newSize = QUEUESIZE * 2;  // ���ݺ�Ĵ�СΪԭ��������
//	T* newQueue = new T[newSize]; // �����µĶ���
//
//	// ��ԭ�����е�Ԫ�ظ��Ƶ��¶�����
//	int i = front;
//	int j = 0;
//	while (i != rear)
//	{
//		newQueue[j] = queue[i];
//		i = (i + 1) % QUEUESIZE;
//		j++;
//	}
//	newQueue[j] = queue[i]; // ���ƶ�βԪ��
//
//	delete[] queue; // �ͷ�ԭ���е��ڴ�ռ�
//	queue = newQueue; // ���¶��и�ֵ��ԭ����ָ��
//
//	front = 0; // ���¶�ͷָ��
//	rear = m_size - 1; // ���¶�βָ��
//	QUEUESIZE = newSize; // ���¶��д�С
//}
