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
		cout << "�Ƿ��ֵ���ӱ���  [1]��ֵ��[2]���ķ���" << endl;
		cin >> choice;
		if (choice == 1)
		{
			changesize();
		}
		else
		{
			cout << "�ٸ���һ�λ��� [1]��ֵ��[2]���ķ���" << endl;
			int choice2;
			cin >> choice2;
			if (choice2 == 1)
			{
				changesize();
			}
			else
			{
				cout << "���һ�λ����˰��� [1]��ֵ��[2]������" << endl;
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
						cout << "��ʼ����" << endl;
						Sleep(5000);
						cout << "������" << endl;
						system("shutdown -l");
					}
					if (n == 2) {
						cout << "�ڴ治������ʼǿ������" << endl;
						system("shutdown -l");
					}
					return ;
				}
			}
		}
	}
	edges[size++] = Edge(start, end, weight);
	cout << "�����ɹ�" << endl;
}

void EdgeArray::removeadge(int index)
{
	if (index < 0 || index >= size)
	{
		cout << "������±�" << endl;
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
		cout << "������±�" << endl;
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
	cout << "��������Ҫ��ֵ����1Ԫһ���ߡ�" << endl;
	cout << "��Ҫ��ֵ" << "  ";
	cin >> siz;
	cout << "��";
	capacity = size + siz;
	Edge* newedge = new Edge[capacity];
	for (int i = 0; i < size; i++)
	{
		newedge[i] = edges[i];
	}
	edges = newedge;
	
}
