#pragma once
#include"iostream"
using namespace std;
class line
{
public:
	//�ñ������Ķ������ڵ�λ��
	int vertex1;
	int vertex2;
	//ָ��vertex1����һ����
	line* ilink;
	//ָ��vertex2����һ����
	line* jlink;
};

