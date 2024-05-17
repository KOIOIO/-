#pragma once
#define QUEUESIZE 8
#include <iostream>
//#define QUEUESIZE 8
using namespace std;

template <typename T>
class Queue
{
public:
	Queue();                          //构造和析构
	~Queue();
	int getSize();                    //获取长度
	void enQueue(T& e);        //队尾插入元素
	void deQueue();                   //删除队头元素
	void display();             //输出整个队列元素
	bool isEmpty();             //判断是否为空队
	bool isFull();              //判断队是否已满
	void Change_size();
	//如果队列已满就扩增空间
private:

	T queue[QUEUESIZE];
	int front;                //队头、队尾指针      
	int rear;
	int m_size;               //队列长度
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
		cout << "队列中没有元素" << endl;
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
//	cout << "队列扩容" << endl;
//	int new_size = QUEUESIZE * 2;
//	T* tmp = new T[new_size];
//	copy(queue, queue + QUEUESIZE, tmp);
//	queue = tmp;
//	QUEUESIZE *= 2;
//}

//template <typename T>
//void Queue<T>::Change_size()
//{
//	int newSize = QUEUESIZE * 2;  // 扩容后的大小为原来的两倍
//	T* newQueue = new T[newSize]; // 创建新的队列
//
//	// 将原队列中的元素复制到新队列中
//	int i = front;
//	int j = 0;
//	while (i != rear)
//	{
//		newQueue[j] = queue[i];
//		i = (i + 1) % QUEUESIZE;
//		j++;
//	}
//	newQueue[j] = queue[i]; // 复制队尾元素
//
//	delete[] queue; // 释放原队列的内存空间
//	queue = newQueue; // 将新队列赋值给原队列指针
//
//	front = 0; // 更新队头指针
//	rear = m_size - 1; // 更新队尾指针
//	QUEUESIZE = newSize; // 更新队列大小
//}
