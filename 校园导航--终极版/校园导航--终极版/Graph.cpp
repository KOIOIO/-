#include "Graph.h"

int Graph::GetnumPoint()
{
    return num_of_Points;//将当前地点的个数返回
}

Graph::Graph()
{
	max_of_Point = DefaultPoints;// 初始化 最大顶点数 
	num_of_Points = 0; // 初始化 顶点个数 
	num_of_Edges = 0; // 初始化 边数 
	List_of_Points = new Point[max_of_Point];// new一个动态的Point类类型的数组 
	arcs = new int* [max_of_Point]; //new一个指针数组 
	for (int i = 0; i < max_of_Point; i++)//为路径开辟空间
		arcs[i] = new int[max_of_Point];
	for (int i = 0; i < max_of_Point; i++)//当下标相同，路径指向自己的时候，路径长度赋值为0
		for (int j = 0; j < max_of_Point; j++)
			arcs[i][j] = (i == j) ? 0 : maxValue;//初始化边的长度 

	readPointfile();//将文件中的顶点信息读入
	readEdgefile();//将文件中的路径
}

Graph::~Graph()
{
	//销毁各种数组
	delete[] List_of_Points;
	delete[] arcs;
	delete[] path;
	delete[] dist;
}

int Graph::NumberOfPoints()
{
	return num_of_Points;//与上面有个函数写重了
}

int Graph::NumberOfEdges()
{
	return num_of_Edges;//返回边的数目
}

Point Graph::getValue(int i)
{
	return List_of_Points[i];//将地点数据整个返回
}

int Graph::getLength(int v1, int v2)
{
	return arcs[v1][v2];//返回边的权值
}

int Graph::getPointPos(char code)
{
	//根据当前顶点的个数进行遍历
	for (int i = 0; i < num_of_Points; i++)
		if (List_of_Points[i].code == code)
		{
			return i;//将找到的下标进行返回
		}

	return -1;
}

bool Graph::insertPoint(char code, string name, string intro)
{
	if (num_of_Points == max_of_Point)//如果达到最大定点数则可以开辟空间
	{
		printf("景点数已经达到最大值！");
		return false;
	}
	//将顶点的信息依次进行赋值
	List_of_Points[num_of_Points].code = code;
	List_of_Points[num_of_Points].name = name;
	List_of_Points[num_of_Points].intro = intro;
	//定点数加1
	num_of_Points++;
	return true;
}

bool Graph::insertEdge(int v1, int v2, int length)
{
	//判断条件
	if (v1 > -1 && v1<num_of_Points && v2>-1 && v2 < num_of_Points)
	{
		arcs[v1][v2] = arcs[v2][v1] = length;//两个下标之间的权值进行赋值
		//路径数++
		num_of_Edges++;
		return true;
	}
	else
		return false;
}

void Graph::Show(int i)
{
	int t = number;
	int j;
	cout << "  景点代号：" << List_of_Points[i].code << endl;
	cout << "  景点名称：" << List_of_Points[i].name << endl;
	cout << "  景点简介：" << List_of_Points[i].intro << endl;
	cout << "  学生评价：" << List_of_Points[i].comments << endl;
	cout << "***************************************" << endl;
}

void Graph::MinPath(int v)
{
	//将n赋值为当前定点数
	int n = NumberOfPoints();
	//为dist和path数组开辟空间
	dist = new int[n];
	path = new int[n];
	bool* S = new bool[n];  //顶点集合,如果s[i]等于true 说明i点已经被加入最短路径集合中 
	int i, j, k, w, min;//用作遍历
	for (i = 0; i < n; i++)
	{
		dist[i] = getLength(v, i); //数组初始化 
		S[i] = false;
		if (i != v && dist[i] < maxValue)
			path[i] = v;//说明i到v有边相连 ，设置path[i]=v 
		else
			path[i] = -1;//说明i到v无边相连 
	}
	S[v] = true;     //顶点v加入顶点集合 
	dist[v] = 0;//自己到自己的最短路径为0
	for (i = 0; i < n - 1; i++)
	{
		min = maxValue;
		int u = v;    //选不在S中具有最短路径的顶点u 
		for (j = 0; j < n; j++)
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		S[u] = true;   //顶点u加入集合S 
		for (k = 0; k < n; k++)
		{
			w = getLength(u, k);
			if (S[k] == false && w < maxValue && dist[u] + w < dist[k])   //顶点k未加入S，且绕过u可以缩短路径 
			{
				dist[k] = dist[u] + w;
				path[k] = u;       //k到u有边相连                            //修改到k的最短路径 
			}
		}
	}
}

void Graph::ShowMin(int v, int x)
{
	int j, k, n;
	n = NumberOfPoints();
	int* d = new int[n];
	{
		j = x;
		k = 0;
		while (j != v)
		{
			d[k++] = j;//d[]数组逆向接受path中的下标值
			j = path[j];//path是指与j相连的上一个结点 
		}
		cout << getValue(v).name << "到" << getValue(x).name << "的最短路径为：" << endl << getValue(v).name;
		while (k > 0)
		{
			//从数组d的逆向将顶点的名称打印出来
			cout << "-->" << getValue(d[--k]).name;
		}
		/*两种情况下没有道路
		 边的两端相同 0
		 这条边被删除 0
		 根本就没有这条边 maxValue
		*/
		if (dist[x] == 0||dist[x]==maxValue)
		{
			cout << "这两点之间没有道路" << endl;
			return;
		}
		cout << endl << "最短路径长度为：" << dist[x] << endl;
		
	}
	delete[] d;
}

//算法与上面的函数相同，只不过少了些提示语
int Graph::FindMinPath(int v, int x)
{
	int j, k, n;
	n = NumberOfPoints();
	int* d = new int[n];
	{
		j = x;
		k = 0;
		while (j != v)
		{
			d[k++] = j;
			j = path[j];
		}
		while (k > 0)
		{
			cout << "-->" << getValue(d[--k]).name;
		}
	}

	delete[] d;

	return dist[x];//返回v到x的最短路径 
}

void Graph::ShowMany()
{
	system("cls");
	Map();
	//用于存储输入的代码
	int i, j, sum, x, a[num];
	char c[num];
	//过去输入的代码
	for (i = 0;; i++)//输入依次要参观的景点 
	{
		cout << "请输入你要参观的第" << i + 1 << "个地点(输入0结束): ";
		cin >> c[i];
		if (c[i] == '0')
			break;
		while (1)
		{
			a[i] = getPointPos(c[i]);
			if (a[i] == -1)
			{
				cout << "输入错误，请重新输入" << endl;
				cout << "请输入你要参观的第" << i + 1 << "个地点(输入0结束): ";
				getchar();
				cin >> c[i];
			}
			else
			{
				break;
			}
		}
	}
	cout << getValue(a[0]).name;
	//多次使用迪杰特斯拉算法
	for (j = 0, sum = 0; j < i - 1; j++)
	{
		MinPath(a[j]);
		x = FindMinPath(a[j], a[j + 1]);
		sum += x;
	}
	cout << endl << "最短路径长度为：" << sum << endl;
	cout << "按回车键继续";
	system("pause");
}

int Graph::Increase()
{
	
	
	int f;
	system("cls");
	Map();
	char code;
	string name;
	string intro;
	cout << "请输入要增加的地点的代码：";
	cin >> code;
	while (1)
	{
		f = 0;
		for (int i = 0; i < num_of_Points; i++)
		{
			if (code == getValue(i).code)
			{
					cout << "已有该代码请重新输入" << endl;
					f = 1;
					break;
			}
		}
		if (f == 1)
		{
			cout << "请输入要增加的地点的代码：";
			cin >> code;
		}
		else
		{
				break;
		}
	}
	cout << "请输入要增加的地点的名称：";
	cin.ignore();
	getline(cin, name);
	cout << "请输入要增加的地点的简介：";
	getline(cin, intro);
	insertPoint(code, name, intro);
	inPointfile();
	int v1, v2, length;
	char code1, code2;
	cout << "起始地点：";
	cin >> code1;
	cout << "终止地点：";
	cin >> code2;
	while (1)
	{
		v1 = getPointPos(code1);
		v2 = getPointPos(code2);
		if (v1 == -1 || v2 == -1)
		{
			cout << "输入错误，请重新输入" << endl;
			cout << "编号如上图，请输入您要查询的两个地点的编号：" << endl;
			cout << "起始地点：";
			cin >> code1;
			cout << "终止地点：";
			cin >> code2;
		}
		else
		{
			cout << "请输入两地点间的距离：";
			cin >> length;
			insertEdge(v1, v2, length);
			inEdgefile(v1, v2, length);
			break;
		}
	}
	cout << "按回车键继续";
	system("pause");
	
	
	return 0;
}

void Graph::search()
{
	int i;
	char code;
	while (1)
	{

		Map();
		cout << "请输入要查询的地点编号(输入0退出)：";
		cin >> code;
		if (code == '0')
			break;
		i = getPointPos(code);
		if (i == -1)
		{
			cout << "输入错误，请重新输入" << endl;
		}
		else
		{
			Show(i);
			cout << "按回车键继续";
			system("pause");
			system("cls");
		}
	}
}

void Graph::minest()
{
	system("cls");
	Map();
	int v1, v2;
	char code1, code2;
	cout << "编号如上图，请输入您要查询的两个景点的编号：" << endl;
	cout << "起始地点：";
	cin >> code1;
	cout << "终止地点：";
	cin >> code2;
	while (1)
	{
		v1 = getPointPos(code1);
		v2 = getPointPos(code2);
		if (v1 == -1 || v2 == -1)
		{
			cout << "输入错误，请重新输入" << endl;
			cout << "起始地点：";
			cin >> code1;
			cout << "终止地点：";
			cin >> code2;
		}
		else
		{
			MinPath(v1);
			ShowMin(v1, v2);
			break;
		}
	}
	cout << "按回车键继续";
	system("pause");
	system("cls");
}

void Graph::Map()
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "============================================" << endl;
	cout << "============================================" << endl;
	for (int i = 1; i <= num_of_Points; i++)
	{
		cout << List_of_Points[i - 1].code << std::left << setw(15) << List_of_Points[i - 1].name;//std：：left 左对齐  setw（15） 占十五行内容

		if (i % 3 == 0)
			cout << endl;
	}
	cout << endl << "============================================" << endl;
}

void Graph::insertcomments()
{
	char code;
	string comment;
	Map();
	int i;
	cout << "请输入您要添加备注的地点编号： " << endl;
	while (1) 
	{
		cin >> code;
		i = getPointPos(code);
		if (i == -1) printf("输入错误，请重新输入！");
		else break;
	}
	cout << "请输入您对于" << List_of_Points[i].name << "的看法~！(输入0号结束)" << endl;
	cin.ignore();
	getline(cin, comment, '0');
	insertcomment(i, comment);
	cout << "输入成功！";
	getchar();
}

void Graph::insertcomment(int i, string comment)
{
	//书写评论
	List_of_Points[i].comments += comment + "\n";
}

void Graph::showTime()
{
	system("cls");
	Graph::Map();
	char code1, code2;
	int v1, v2;
	walk walk1;
	bike bike1;

	car car1;
	cout << "请输入您要查询的两个地点的编号：" << endl;
	cout << "起始地点：";
	cin >> code1;
	cout << "终止地点：";
	cin >> code2;

	while (1)
	{
		char t1; system("cls"); Graph::Map();
		v1 = getPointPos(code1);
		v2 = getPointPos(code2);
		if (v1 == -1 || v2 == -1)
		{
			cout << "输入错误，请重新输入" << endl;
			cout << "起始地点：";
			cin >> code1;
			cout << "终止地点：";
			cin >> code2;
		}

		else {
			MinPath(v1);
			int x = FindMinPath(v1, v2);
			cout << "请选择您的出行方式：\n" << "1.步行\n" << "2.骑车\n" << "3.开车\n" << endl;
			int t;
			cin >> t;
			while (1) {
				if (t <= 0 || t > 3) {
					cout << "输入错误，请重新输入";
					break;
				}
				else {
					switch (t) {
					case 1:
						walk1.showTime(x);
						break;
					case 2: bike1.showTime(x); break;
					case 3: car1.showTime(x); break;
					}
					cout << "输入任意键继续"; getchar(); break;
				}
				system("pause");
				system("cls");
				break;
			}
			cin >> t1;
			break;
		}
		break;
	}
}

void Graph::inPointfile()
{
	int num = num_of_Points;
	ofstream save_file("地点.txt");
	for (int i = 0; i < num; i++)
	{
		save_file << List_of_Points[i].code << "\t" << List_of_Points[i].name << "\t" << List_of_Points[i].intro << "\t" << endl;;
	}
	save_file.close();
}

void Graph::readPointfile()
{
	ifstream read_file("地点.txt");
	if (!read_file.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	else
	{
		Point temp;
		while (read_file >> temp.code && read_file >> temp.name && read_file >> temp.intro)
		{
			this->insertPoint(temp.code, temp.name, temp.intro);
		}
	}
	read_file.close();
}

void Graph::inEdgefile(int point1, int point2, int w)
{
	ofstream savefile;
	savefile.open("路径.txt", ios::app);
	savefile << endl << point1 << "\t" << point2 << "\t" << w;
	savefile.close();
}

void Graph::readEdgefile()
{
	ifstream readfile("路径.txt");
	if (!readfile.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	else
	{
		int v1, v2, weight;
		while (readfile >> v1 && readfile >> v2 && readfile >> weight)
		{
			this->insertEdge(v1, v2, weight);
		}
	}
	readfile.close();
}

void Graph::delete_path()
{
	system("cls");
	Map();
	int v1, v2;
	char code1, code2;
	cout << "编号如上图，请输入您要删除的两个景点的编号：" << endl;
	cout << "起始地点：";
	cin >> code1;
	cout << "终止地点：";
	cin >> code2;
	//while (1)
	//{
	//	v1 = getPointPos(code1);
	//	v2 = getPointPos(code2);
	//	if (v1 == -1 || v2 == -1)
	//	{
	//		cout << "输入错误，请重新输入" << endl;
	//		cout << "起始景点：";
	//		cin >> code1;
	//		cout << "终止景点：";
	//		cin >> code2;
	//	}
	//	else
	//	{
	//		arcs[v1][v2] = 0;
	//		arcs[v2][v1] = 0;
	//		// 更新边数
	//		numEdges--;

	//	}
	//}
	v1 = getPointPos(code1);
	v2 = getPointPos(code2);
	arcs[v1][v2] = 0;
	arcs[v2][v1] = 0;
	inEdgefile(v1,v2,arcs[v1][v2]);
	cout << "按回车键继续";
	
}

void Graph::delete_vertex()
{
	char code;
	cout << "请输入你想删除的地点" << endl;
	cin >> code;
	int point = getPointPos(code);
	List_of_Points[point].code = '\0';
	List_of_Points[point].name = "";
	List_of_Points[point].intro = "";
	List_of_Points[point].comments = "";
	// 更新顶点数
	num_of_Points--;
	inPointfile();
	// 更新邻接矩阵中与该顶点相关的边长为0
	for (int i = 0; i < num_of_Points; i++) {
		//Edges[point][i] = 0;
		arcs[i][point] = 0;
		num_of_Edges--;
	}
}

void Graph::DFS(int v)
{
	// 标记当前节点为已访问
	visited[v] = true;
	// 输出当前节点
	cout << List_of_Points[v].name << "-> ";
	// 遍历当前节点的邻接节点
	for (int i = 0; i < num_of_Points; i++)
	{
		if (arcs[v][i] != 0 && arcs[v][i] != maxValue && visited[i] == false)
		{
			DFS(i);
		}
	}
}

void Graph::BFS(int v)
{

	// 创建一个队列用于存储待访问的节点
	queue<int> q;
	// 标记当前节点为已访问
	visited[v] = true;
	// 将当前节点入队
	q.push(v);
	while (!q.empty())
	{
		// 出队并输出当前节点
		int cur = q.front();
		q.pop();
		cout << List_of_Points[cur].name << "->";
		// 遍历当前节点的邻接节点
		for (int i = 0; i < num_of_Points; i++)
		{
			if (arcs[cur][i] != 0 && arcs[cur][i] != maxValue && !visited[i])
			{
				// 标记邻接节点为已访问，并入队
				visited[i] = true;
				q.push(i);
			}
		}
	}
	for (int j = 0; j <= num_of_Points; j++)
		visited[j] = false;
}
