#pragma once
#include"line.h"
class vertex
{
public:
	int data;//数据域
	line* firstline;//第一条依附于该节点的边
};

