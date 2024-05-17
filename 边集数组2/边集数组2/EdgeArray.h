#pragma once
#include"Edge.h"
class EdgeArray
{
private:
	Edge* edges;
	int size=0;
	int capacity;
public:
	EdgeArray(int capacity);//构造函数
	~EdgeArray();//析构函数
	void addedge(int start,int end,int weight);//增加弧
	void removeadge(int index);//删除弧
	void updateedge(int index, int neweight);//更新弧的权重
	int getIndegree(int vertex);//获得节点的入度
	int getOutdegree(int vertex);//获得节点的出度
	void printegdes();//遍历打印弧
	void changesize();//更改开辟的空间

};

