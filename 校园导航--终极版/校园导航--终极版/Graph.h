#pragma once
#include"Time.h"
#include"Point.h"
class Graph :private Point    //���嶥��������� ͼ�� 
{

private:
	int max_of_Point;// ͼ����󶥵���
	int num_of_Edges;	 // ��ǰ����
	int num_of_Points;	// ��ǰ������ 
	Point* List_of_Points;		// ���������׵�ַ 
	int** arcs;// ����·��Ȩֵ����ά����
	int* path;  // ����ý���ǰһ�����
	int* dist;  // ����·������
	int pathNum;  // ���������·������Ŀ
public:
	bool visited[];//�Ѿ����ʹ��Ľڵ�
public:
	int GetnumPoint();

	Graph();  // ���캯��
	~Graph(); // ��������
	int NumberOfPoints();  // ���ص�ǰ������
	int NumberOfEdges();    // ���ص�ǰ����
	Point getValue(int i); // ȡ���� i ��ֵ,������Ϊ��������ֵ 
	int getLength(int v1, int v2);	 // ȡ���ϳ��� 
	int getPointPos(char code);	 // �����������code��ͼ��λ��
	bool insertPoint(char code, string name, string intro);// ����һ������Point
	bool insertEdge(int v1, int v2, int length); // �����(v1, v2), ȨֵΪlength
	void Show(int i);// �������i����Ϣ
	void MinPath(int v);  // Dijkstra�����·���㷨
	void ShowMin(int v, int x);     // ��������������·���;���
	int FindMinPath(int v, int x);  // ���Ҷ�����������·�� 
	//���ʹ�õϽ���˹���㷨
	void ShowMany();  // ���������������·��
	int Increase(); // ���Ӿ���͵�· 
	int** Edg() { return arcs; } 
	virtual void search();    // ������Ϣ��ѯ 
	virtual void minest();    // ��ѯ���ص����̾���
	void Map();	   
	void insertcomments();//���뱸ע 
	void insertcomment(int i, string comment);
	void showTime();
	//��Զ�����ļ�����
	void inPointfile();
	void readPointfile();
	//��ԱߵĲ���
	void inEdgefile(int point1, int point2, int w);
	void readEdgefile();


	void delete_path();//ɾ��·��
	void delete_vertex();//ɾ���ص�
	void DFS(int v);//������ȱ���
	void BFS(int v);//������ȱ���
	void school_map()
	{
		cout << "������������������������������ѧԺ������У����ƽ��ͼ������������������-" << endl;
		cout << "              �����š�                                                   |" << endl;
		cout << "                 |                   |------��4�̡�                      |" << endl;
		cout << "                 |--------------------                                   |" << endl;
		cout << "                 |              ������ѧԺ��                             |" << endl;
		cout << " --------��1�̡�--                   / |                                 |" << endl;
		cout << " |               |                  /  |                                 |" << endl;
		cout << "��3�̡�          |                 /   |                                 |" << endl;
		cout << " |               |                /    |                                 |" << endl;
		cout << " |               ----------------/     |                                 |" << endl;
		cout << " |               |                     |                                 |" << endl;
		cout << " |           ���йش塷                |                                 |" << endl;
		cout << " |                |                    |                                 |" << endl;
		cout << "  \\               |                �������ٳ���                          |" << endl;
		cout << "   \\              \\                  |                                   |" << endl;
		cout << "     \\             |                 /                                   |" << endl;
		cout << "       ---------��С���á�------------                                   |" << endl;
		cout << "       |             |                                                   |" << endl;
		cout << "      /               \\                                                  |" << endl;
		cout << "     /                 \\                                                 |" << endl;
		cout << "������������            \\                                                |" << endl;
		cout << "     |     \\             \\                                               |" << endl;
		cout << "     |   ���³��㳡��---��Уҽ���ҡ�                                     |" << endl;
		cout << "     |        /             |                                            |" << endl;
		cout << "��Ů����Ԣ��-               |                                            |" << endl;
		cout << "     \\                      |                                            |" << endl;
		cout << "      |                     |                                            |" << endl;
		cout << " ����ľ����ѧԺ��           |                                            |" << endl;
		cout << "      | \\                   |                                            | " << endl;
		cout << "      |   \\                 /                                            |" << endl;
		cout << "      |     \\--�����ҡ�----                                              |" << endl;
		cout << "      |           |                                                      |" << endl;
		cout << "      |      ������ѧԺ��                                                |" << endl;
		cout << "      |          /                                                       |" << endl;
		cout << " ����������ѧԺ��                                                        |" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "������������������������������ѧԺ������У����ƽ��ͼ������������������-��" << endl;
		cout << "|���͹㳡*-----                                                            |" << endl;
		cout << "|              \\                                                           |" << endl;
		cout << "|               *��Ϣ����ѧԺ-*����������ѧԺ---*������վ       *��ʦ��Ԣ|" << endl;
		cout << "|               |             |                                   |        |" << endl;
		cout << "|               *����ѧԺ-----|                                   |        |" << endl;
		cout << "|               |             |                                   |        |" << endl;
		cout << "|                --           |                                   |        |" << endl;
		cout << "|                  |          |                                   |        |" << endl;
		cout << "|���پ���ҽ��ҩѧԺ*----------|-----------------------------------*ѧ����Ԣ|" << endl;
		cout << "|                  | |   ��  ||               |                            |" << endl;
		cout << "|              ----\\ |       ||               |                            |" << endl;
		cout << "|             /   --*|   Ϫ  |*               *���ϲٳ�                    |" << endl;
		cout << "|            /      ||       ||               \\                            |" << endl;
		cout << "|           /       ||   ��                   \\                            |" << endl;
		cout << "|          /       /  -------------------------------*���ϲ���             |" << endl;
		cout << "|         /       /                                  |                     |" << endl;
		cout << "|��ɭ¥*------   /        ---------------------------|                     |" << endl;
		cout << "|             \\ /         |                                                |" << endl;
		cout << "|              *ͼ��� ---*������                                          |" << endl;
		cout << "---------------------------------------------------------------------------" << endl;



	}
};

