#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>//������� 
#include<windows.h> 
#include<stdio.h>
#include"template_class.h"
#include<fstream>
#include<queue>

using namespace std;

static int maxValue = 9999;//���ֵ 
const int maxPoint = 100;	// ��󶥵���
const int DefaultPoints = 90;	 // Ĭ�϶�����
const int num = 20;
static int number = 0;
//��ͬ��ͨ��ʽ���ٶ�
//����
static int speed1 = 1;
//�ﳵ
static int speed2 = 3;
//����
static int speed3 = 16;
static int min;
class Point//������
{
	friend class Graph;
private:
	//�ص�ı��
	char code;
	//�ص������
	string name;
	//�ص�Ľ���
	string intro;
	//�ص�����ۣ������г�ʼ��
	string comments;

};