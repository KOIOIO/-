#pragma once
#include"iostream"
using namespace std;
class Edge
{
public:
	int data;//������
	int start;//����±�
	int end;//�յ��±�
	int weight;//����Ȩ��
	Edge(int start, int end, int weight);//���캯��
	Edge();//�޲ι��캯��
};

