#pragma once
#include"vertex.h"
class digraph
{
public:
	vertex* listhead;//��ͷ
	int vertexnum;//�ڵ���
	int arcnum;//����
public:
	void creatdigraph();//����ͼ
	int gethead(int value);//�������ݵ��±�
	void getdegree();//���һ������Ķȣ���ȣ����ȣ��ܶ�����
	void search(); //��ͨ���±��ѯ���ݣ�
	void traverse();//��������ӡ��
	void deleteVertex(int value);//ɾ���ڵ�
	void modifyVertex(int oldValue, int newValue);//���Ľڵ�
	void DFS();
	void BFS();
};

