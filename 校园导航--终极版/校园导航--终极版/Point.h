#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>//输入输出 
#include<windows.h> 
#include<stdio.h>
#include"template_class.h"
#include<fstream>
#include<queue>

using namespace std;

static int maxValue = 9999;//最大值 
const int maxPoint = 100;	// 最大顶点数
const int DefaultPoints = 90;	 // 默认顶点数
const int num = 20;
static int number = 0;
//不同交通方式的速度
//步行
static int speed1 = 1;
//骑车
static int speed2 = 3;
//汽车
static int speed3 = 16;
static int min;
class Point//顶点类
{
	friend class Graph;
private:
	//地点的编号
	char code;
	//地点的名称
	string name;
	//地点的介绍
	string intro;
	//地点的评价，不进行初始化
	string comments;

};