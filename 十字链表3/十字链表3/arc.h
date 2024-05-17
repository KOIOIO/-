#pragma once
#include"iostream"
using namespace std;
class arc
{
public:
	int tailvertex;//弧尾顶点的位置
	int headvertexx;//弧头顶点的位置
	arc* taillink;//指向弧尾相同
	arc* headlink;//指向弧头相同
};

