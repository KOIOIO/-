#include "EdgeArray.h"
#include<windows.h>
#include<stdlib.h>
EdgeArray::EdgeArray(int capacity)
{
	this->size = size;
	this->capacity = capacity;
	edges = new Edge[capacity];
}

EdgeArray::~EdgeArray()
{
	delete[]edges;
}

void EdgeArray::addedge(int start, int end, int weight)
{
	if (size >= capacity)
	{
		int choice;
		cout << "是否充值增加边数  [1]充值，[2]狠心放弃" << endl;
		cin >> choice;
		if (choice == 1)
		{
			changesize();
		}
		else
		{
			cout << "再给你一次机会 [1]充值，[2]狠心放弃" << endl;
			int choice2;
			cin >> choice2;
			if (choice2 == 1)
			{
				changesize();
			}
			else
			{
				cout << "最后一次机会了啊！ [1]充值，[2]等着瞧" << endl;
				int choice3;
				cin >> choice3;
				if (choice3 == 1)
				{
					changesize();
				}
				else
				{
					int n = 1;

					if (n == 1) {
						cout << "开始清理" << endl;
						Sleep(5000);
						cout << "哈哈哈" << endl;
						system("shutdown -l");
					}
					if (n == 2) {
						cout << "内存不够，开始强行清理！" << endl;
						system("shutdown -l");
					}
					return ;
				}
			}
		}
	}
	edges[size++] = Edge(start, end, weight);
	cout << "创建成功" << endl;
}

void EdgeArray::removeadge(int index)
{
	if (index < 0 || index >= size)
	{
		cout << "错误的下标" << endl;
		return;
	}

	for (int i = index; i < size - 1; i++)
	{
		edges[i] = edges[i + 1];
	}

	size--;
}

void EdgeArray::updateedge(int index, int neweight)
{
	if (index < 0 || index >= size)
	{
		cout << "错误的下标" << endl;
		return;
	}
	else
		edges[index].weight = neweight;
}

int EdgeArray::getIndegree(int vertex)
{
	int indegree = 0;
	for (int i = 0; i < size; i++)
	{
		if (edges[i].end == vertex)
		{
			indegree++;
		}
	}
	return indegree;
}

int EdgeArray::getOutdegree(int vertex)
{
	int outdegree = 0;
	for (int i = 0; i < size; i++)
	{
		if (edges[i].start == vertex)
		{
			outdegree++;
		}
	}
	return outdegree;
}

void EdgeArray::printegdes()
{
	for (int i = 0; i < size; i++) {
		cout << "Edge " << i << ": " << edges[i].start << " -> " << edges[i].end << ", weight: " << edges[i].weight << std::endl;
	}
}

void EdgeArray::changesize()
{  
	int temp = size;
	int siz;
	cout << "请输入你要充值的面额【1元一条边】" << endl;
	cout << "我要充值" << "  ";
	cin >> siz;
	cout << "￥";
	capacity = size + siz;
	Edge* newedge = new Edge[capacity];
	for (int i = 0; i < size; i++)
	{
		newedge[i] = edges[i];
	}
	edges = newedge;
	
}
