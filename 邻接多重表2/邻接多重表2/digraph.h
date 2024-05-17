#pragma once
#include"line.h"
#include"vertex.h"
class digraph
{
public:
	//构建
	vertex* listhead;
	int vertexnum = 0;//顶点数
	int linenum = 0;//弧数
	digraph();
	void createundigraph();//创建图
	int gethead(int value);//获取顶点下标
	void printGraph();//打印图
	void deleteNode(int value);//删除顶点
	void search();//搜索顶点
	void modify();//更改顶点的值
	void getdegree();//获得顶点的度
	~digraph();
};

