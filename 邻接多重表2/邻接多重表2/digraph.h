#pragma once
#include"line.h"
#include"vertex.h"
class digraph
{
public:
	//����
	vertex* listhead;
	int vertexnum = 0;//������
	int linenum = 0;//����
	digraph();
	void createundigraph();//����ͼ
	int gethead(int value);//��ȡ�����±�
	void printGraph();//��ӡͼ
	void deleteNode(int value);//ɾ������
	void search();//��������
	void modify();//���Ķ����ֵ
	void getdegree();//��ö���Ķ�
	~digraph();
};

