#pragma once
#include"iostream"
using namespace std;
class line
{
public:
	//该边依附的顶点所在的位置
	int vertex1;
	int vertex2;
	//指向vertex1的下一条边
	line* ilink;
	//指向vertex2的下一条边
	line* jlink;
};

