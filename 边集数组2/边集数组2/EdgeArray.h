#pragma once
#include"Edge.h"
class EdgeArray
{
private:
	Edge* edges;
	int size=0;
	int capacity;
public:
	EdgeArray(int capacity);//���캯��
	~EdgeArray();//��������
	void addedge(int start,int end,int weight);//���ӻ�
	void removeadge(int index);//ɾ����
	void updateedge(int index, int neweight);//���»���Ȩ��
	int getIndegree(int vertex);//��ýڵ�����
	int getOutdegree(int vertex);//��ýڵ�ĳ���
	void printegdes();//������ӡ��
	void changesize();//���Ŀ��ٵĿռ�

};

