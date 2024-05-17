#pragma once
#include"iostream"
using namespace std;
class Edge
{
public:
	int data;//数据域
	int start;//起点下标
	int end;//终点下标
	int weight;//弧的权重
	Edge(int start, int end, int weight);//构造函数
	Edge();//无参构造函数
};

