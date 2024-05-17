#pragma once
#include"vertex.h"
class digraph
{
public:
	vertex* listhead;//表头
	int vertexnum;//节点数
	int arcnum;//弧数
public:
	void creatdigraph();//创建图
	int gethead(int value);//返回数据的下标
	void getdegree();//获得一个顶点的度（入度，出度，总度数）
	void search(); //（通过下标查询数据）
	void traverse();//（遍历打印）
	void deleteVertex(int value);//删除节点
	void modifyVertex(int oldValue, int newValue);//更改节点
	void DFS();
	void BFS();
};

