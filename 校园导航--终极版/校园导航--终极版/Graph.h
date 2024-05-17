#pragma once
#include"Time.h"
#include"Point.h"
class Graph :private Point    //定义顶点类的子类 图类 
{

private:
	int max_of_Point;// 图中最大顶点数
	int num_of_Edges;	 // 当前边数
	int num_of_Points;	// 当前顶点数 
	Point* List_of_Points;		// 顶点数组首地址 
	int** arcs;// 保存路径权值，二维数组
	int* path;  // 保存该结点的前一个结点
	int* dist;  // 保存路径长度
	int pathNum;  // 两点间所有路径的数目
public:
	bool visited[];//已经访问过的节点
public:
	int GetnumPoint();

	Graph();  // 构造函数
	~Graph(); // 析构函数
	int NumberOfPoints();  // 返回当前顶点数
	int NumberOfEdges();    // 返回当前边数
	Point getValue(int i); // 取顶点 i 的值,以类名为函数返回值 
	int getLength(int v1, int v2);	 // 取边上长度 
	int getPointPos(char code);	 // 给出顶点代码code在图中位置
	bool insertPoint(char code, string name, string intro);// 插入一个顶点Point
	bool insertEdge(int v1, int v2, int length); // 插入边(v1, v2), 权值为length
	void Show(int i);// 输出顶点i的信息
	void MinPath(int v);  // Dijkstra求最短路径算法
	void ShowMin(int v, int x);     // 输出两顶点间的最短路径和距离
	int FindMinPath(int v, int x);  // 查找多个顶点间的最佳路径 
	//多次使用迪杰特斯拉算法
	void ShowMany();  // 输出多个顶点间的最佳路径
	int Increase(); // 增加景点和道路 
	int** Edg() { return arcs; } 
	virtual void search();    // 景点信息查询 
	virtual void minest();    // 查询两地点间最短距离
	void Map();	   
	void insertcomments();//加入备注 
	void insertcomment(int i, string comment);
	void showTime();
	//针对顶点的文件操作
	void inPointfile();
	void readPointfile();
	//针对边的操作
	void inEdgefile(int point1, int point2, int w);
	void readEdgefile();


	void delete_path();//删除路径
	void delete_vertex();//删除地点
	void DFS(int v);//深度优先遍历
	void BFS(int v);//广度优先遍历
	void school_map()
	{
		cout << "————————————南阳理工学院（西北校区）平面图—————————-" << endl;
		cout << "              《北门》                                                   |" << endl;
		cout << "                 |                   |------《4教》                      |" << endl;
		cout << "                 |--------------------                                   |" << endl;
		cout << "                 |              《生化学院》                             |" << endl;
		cout << " --------《1教》--                   / |                                 |" << endl;
		cout << " |               |                  /  |                                 |" << endl;
		cout << "《3教》          |                 /   |                                 |" << endl;
		cout << " |               |                /    |                                 |" << endl;
		cout << " |               ----------------/     |                                 |" << endl;
		cout << " |               |                     |                                 |" << endl;
		cout << " |           《中关村》                |                                 |" << endl;
		cout << " |                |                    |                                 |" << endl;
		cout << "  \\               |                《西北操场》                          |" << endl;
		cout << "   \\              \\                  |                                   |" << endl;
		cout << "     \\             |                 /                                   |" << endl;
		cout << "       ---------《小礼堂》------------                                   |" << endl;
		cout << "       |             |                                                   |" << endl;
		cout << "      /               \\                                                  |" << endl;
		cout << "     /                 \\                                                 |" << endl;
		cout << "《西北餐厅》            \\                                                |" << endl;
		cout << "     |     \\             \\                                               |" << endl;
		cout << "     |   《下沉广场》---《校医务室》                                     |" << endl;
		cout << "     |        /             |                                            |" << endl;
		cout << "《女生公寓》-               |                                            |" << endl;
		cout << "     \\                      |                                            |" << endl;
		cout << "      |                     |                                            |" << endl;
		cout << " 《土木工程学院》           |                                            |" << endl;
		cout << "      | \\                   |                                            | " << endl;
		cout << "      |   \\                 /                                            |" << endl;
		cout << "      |     \\--《画室》----                                              |" << endl;
		cout << "      |           |                                                      |" << endl;
		cout << "      |      《建筑学院》                                                |" << endl;
		cout << "      |          /                                                       |" << endl;
		cout << " 《智能制造学院》                                                        |" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "————————————南阳理工学院（东南校区）平面图—————————-—" << endl;
		cout << "|齐贤广场*-----                                                            |" << endl;
		cout << "|              \\                                                           |" << endl;
		cout << "|               *信息工程学院-*计算机与软件学院---*菜鸟驿站       *教师公寓|" << endl;
		cout << "|               |             |                                   |        |" << endl;
		cout << "|               *数理学院-----|                                   |        |" << endl;
		cout << "|               |             |                                   |        |" << endl;
		cout << "|                --           |                                   |        |" << endl;
		cout << "|                  |          |                                   |        |" << endl;
		cout << "|张仲景国医国药学院*----------|-----------------------------------*学生公寓|" << endl;
		cout << "|                  | |   梦  ||               |                            |" << endl;
		cout << "|              ----\\ |       ||               |                            |" << endl;
		cout << "|             /   --*|   溪  |*               *东南操场                    |" << endl;
		cout << "|            /      ||       ||               \\                            |" << endl;
		cout << "|           /       ||   湖                   \\                            |" << endl;
		cout << "|          /       /  -------------------------------*东南餐厅             |" << endl;
		cout << "|         /       /                                  |                     |" << endl;
		cout << "|汇森楼*------   /        ---------------------------|                     |" << endl;
		cout << "|             \\ /         |                                                |" << endl;
		cout << "|              *图书馆 ---*体育馆                                          |" << endl;
		cout << "---------------------------------------------------------------------------" << endl;



	}
};

