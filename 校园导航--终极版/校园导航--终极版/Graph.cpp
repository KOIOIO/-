#include "Graph.h"

int Graph::GetnumPoint()
{
    return num_of_Points;//����ǰ�ص�ĸ�������
}

Graph::Graph()
{
	max_of_Point = DefaultPoints;// ��ʼ�� ��󶥵��� 
	num_of_Points = 0; // ��ʼ�� ������� 
	num_of_Edges = 0; // ��ʼ�� ���� 
	List_of_Points = new Point[max_of_Point];// newһ����̬��Point�����͵����� 
	arcs = new int* [max_of_Point]; //newһ��ָ������ 
	for (int i = 0; i < max_of_Point; i++)//Ϊ·�����ٿռ�
		arcs[i] = new int[max_of_Point];
	for (int i = 0; i < max_of_Point; i++)//���±���ͬ��·��ָ���Լ���ʱ��·�����ȸ�ֵΪ0
		for (int j = 0; j < max_of_Point; j++)
			arcs[i][j] = (i == j) ? 0 : maxValue;//��ʼ���ߵĳ��� 

	readPointfile();//���ļ��еĶ�����Ϣ����
	readEdgefile();//���ļ��е�·��
}

Graph::~Graph()
{
	//���ٸ�������
	delete[] List_of_Points;
	delete[] arcs;
	delete[] path;
	delete[] dist;
}

int Graph::NumberOfPoints()
{
	return num_of_Points;//�������и�����д����
}

int Graph::NumberOfEdges()
{
	return num_of_Edges;//���رߵ���Ŀ
}

Point Graph::getValue(int i)
{
	return List_of_Points[i];//���ص�������������
}

int Graph::getLength(int v1, int v2)
{
	return arcs[v1][v2];//���رߵ�Ȩֵ
}

int Graph::getPointPos(char code)
{
	//���ݵ�ǰ����ĸ������б���
	for (int i = 0; i < num_of_Points; i++)
		if (List_of_Points[i].code == code)
		{
			return i;//���ҵ����±���з���
		}

	return -1;
}

bool Graph::insertPoint(char code, string name, string intro)
{
	if (num_of_Points == max_of_Point)//����ﵽ��󶨵�������Կ��ٿռ�
	{
		printf("�������Ѿ��ﵽ���ֵ��");
		return false;
	}
	//���������Ϣ���ν��и�ֵ
	List_of_Points[num_of_Points].code = code;
	List_of_Points[num_of_Points].name = name;
	List_of_Points[num_of_Points].intro = intro;
	//��������1
	num_of_Points++;
	return true;
}

bool Graph::insertEdge(int v1, int v2, int length)
{
	//�ж�����
	if (v1 > -1 && v1<num_of_Points && v2>-1 && v2 < num_of_Points)
	{
		arcs[v1][v2] = arcs[v2][v1] = length;//�����±�֮���Ȩֵ���и�ֵ
		//·����++
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
	cout << "  ������ţ�" << List_of_Points[i].code << endl;
	cout << "  �������ƣ�" << List_of_Points[i].name << endl;
	cout << "  �����飺" << List_of_Points[i].intro << endl;
	cout << "  ѧ�����ۣ�" << List_of_Points[i].comments << endl;
	cout << "***************************************" << endl;
}

void Graph::MinPath(int v)
{
	//��n��ֵΪ��ǰ������
	int n = NumberOfPoints();
	//Ϊdist��path���鿪�ٿռ�
	dist = new int[n];
	path = new int[n];
	bool* S = new bool[n];  //���㼯��,���s[i]����true ˵��i���Ѿ����������·�������� 
	int i, j, k, w, min;//��������
	for (i = 0; i < n; i++)
	{
		dist[i] = getLength(v, i); //�����ʼ�� 
		S[i] = false;
		if (i != v && dist[i] < maxValue)
			path[i] = v;//˵��i��v�б����� ������path[i]=v 
		else
			path[i] = -1;//˵��i��v�ޱ����� 
	}
	S[v] = true;     //����v���붥�㼯�� 
	dist[v] = 0;//�Լ����Լ������·��Ϊ0
	for (i = 0; i < n - 1; i++)
	{
		min = maxValue;
		int u = v;    //ѡ����S�о������·���Ķ���u 
		for (j = 0; j < n; j++)
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		S[u] = true;   //����u���뼯��S 
		for (k = 0; k < n; k++)
		{
			w = getLength(u, k);
			if (S[k] == false && w < maxValue && dist[u] + w < dist[k])   //����kδ����S�����ƹ�u��������·�� 
			{
				dist[k] = dist[u] + w;
				path[k] = u;       //k��u�б�����                            //�޸ĵ�k�����·�� 
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
			d[k++] = j;//d[]�����������path�е��±�ֵ
			j = path[j];//path��ָ��j��������һ����� 
		}
		cout << getValue(v).name << "��" << getValue(x).name << "�����·��Ϊ��" << endl << getValue(v).name;
		while (k > 0)
		{
			//������d�����򽫶�������ƴ�ӡ����
			cout << "-->" << getValue(d[--k]).name;
		}
		/*���������û�е�·
		 �ߵ�������ͬ 0
		 �����߱�ɾ�� 0
		 ������û�������� maxValue
		*/
		if (dist[x] == 0||dist[x]==maxValue)
		{
			cout << "������֮��û�е�·" << endl;
			return;
		}
		cout << endl << "���·������Ϊ��" << dist[x] << endl;
		
	}
	delete[] d;
}

//�㷨������ĺ�����ͬ��ֻ��������Щ��ʾ��
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

	return dist[x];//����v��x�����·�� 
}

void Graph::ShowMany()
{
	system("cls");
	Map();
	//���ڴ洢����Ĵ���
	int i, j, sum, x, a[num];
	char c[num];
	//��ȥ����Ĵ���
	for (i = 0;; i++)//��������Ҫ�ι۵ľ��� 
	{
		cout << "��������Ҫ�ι۵ĵ�" << i + 1 << "���ص�(����0����): ";
		cin >> c[i];
		if (c[i] == '0')
			break;
		while (1)
		{
			a[i] = getPointPos(c[i]);
			if (a[i] == -1)
			{
				cout << "�����������������" << endl;
				cout << "��������Ҫ�ι۵ĵ�" << i + 1 << "���ص�(����0����): ";
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
	//���ʹ�õϽ���˹���㷨
	for (j = 0, sum = 0; j < i - 1; j++)
	{
		MinPath(a[j]);
		x = FindMinPath(a[j], a[j + 1]);
		sum += x;
	}
	cout << endl << "���·������Ϊ��" << sum << endl;
	cout << "���س�������";
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
	cout << "������Ҫ���ӵĵص�Ĵ��룺";
	cin >> code;
	while (1)
	{
		f = 0;
		for (int i = 0; i < num_of_Points; i++)
		{
			if (code == getValue(i).code)
			{
					cout << "���иô�������������" << endl;
					f = 1;
					break;
			}
		}
		if (f == 1)
		{
			cout << "������Ҫ���ӵĵص�Ĵ��룺";
			cin >> code;
		}
		else
		{
				break;
		}
	}
	cout << "������Ҫ���ӵĵص�����ƣ�";
	cin.ignore();
	getline(cin, name);
	cout << "������Ҫ���ӵĵص�ļ�飺";
	getline(cin, intro);
	insertPoint(code, name, intro);
	inPointfile();
	int v1, v2, length;
	char code1, code2;
	cout << "��ʼ�ص㣺";
	cin >> code1;
	cout << "��ֹ�ص㣺";
	cin >> code2;
	while (1)
	{
		v1 = getPointPos(code1);
		v2 = getPointPos(code2);
		if (v1 == -1 || v2 == -1)
		{
			cout << "�����������������" << endl;
			cout << "�������ͼ����������Ҫ��ѯ�������ص�ı�ţ�" << endl;
			cout << "��ʼ�ص㣺";
			cin >> code1;
			cout << "��ֹ�ص㣺";
			cin >> code2;
		}
		else
		{
			cout << "���������ص��ľ��룺";
			cin >> length;
			insertEdge(v1, v2, length);
			inEdgefile(v1, v2, length);
			break;
		}
	}
	cout << "���س�������";
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
		cout << "������Ҫ��ѯ�ĵص���(����0�˳�)��";
		cin >> code;
		if (code == '0')
			break;
		i = getPointPos(code);
		if (i == -1)
		{
			cout << "�����������������" << endl;
		}
		else
		{
			Show(i);
			cout << "���س�������";
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
	cout << "�������ͼ����������Ҫ��ѯ����������ı�ţ�" << endl;
	cout << "��ʼ�ص㣺";
	cin >> code1;
	cout << "��ֹ�ص㣺";
	cin >> code2;
	while (1)
	{
		v1 = getPointPos(code1);
		v2 = getPointPos(code2);
		if (v1 == -1 || v2 == -1)
		{
			cout << "�����������������" << endl;
			cout << "��ʼ�ص㣺";
			cin >> code1;
			cout << "��ֹ�ص㣺";
			cin >> code2;
		}
		else
		{
			MinPath(v1);
			ShowMin(v1, v2);
			break;
		}
	}
	cout << "���س�������";
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
		cout << List_of_Points[i - 1].code << std::left << setw(15) << List_of_Points[i - 1].name;//std����left �����  setw��15�� ռʮ��������

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
	cout << "��������Ҫ��ӱ�ע�ĵص��ţ� " << endl;
	while (1) 
	{
		cin >> code;
		i = getPointPos(code);
		if (i == -1) printf("����������������룡");
		else break;
	}
	cout << "������������" << List_of_Points[i].name << "�Ŀ���~��(����0�Ž���)" << endl;
	cin.ignore();
	getline(cin, comment, '0');
	insertcomment(i, comment);
	cout << "����ɹ���";
	getchar();
}

void Graph::insertcomment(int i, string comment)
{
	//��д����
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
	cout << "��������Ҫ��ѯ�������ص�ı�ţ�" << endl;
	cout << "��ʼ�ص㣺";
	cin >> code1;
	cout << "��ֹ�ص㣺";
	cin >> code2;

	while (1)
	{
		char t1; system("cls"); Graph::Map();
		v1 = getPointPos(code1);
		v2 = getPointPos(code2);
		if (v1 == -1 || v2 == -1)
		{
			cout << "�����������������" << endl;
			cout << "��ʼ�ص㣺";
			cin >> code1;
			cout << "��ֹ�ص㣺";
			cin >> code2;
		}

		else {
			MinPath(v1);
			int x = FindMinPath(v1, v2);
			cout << "��ѡ�����ĳ��з�ʽ��\n" << "1.����\n" << "2.�ﳵ\n" << "3.����\n" << endl;
			int t;
			cin >> t;
			while (1) {
				if (t <= 0 || t > 3) {
					cout << "�����������������";
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
					cout << "�������������"; getchar(); break;
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
	ofstream save_file("�ص�.txt");
	for (int i = 0; i < num; i++)
	{
		save_file << List_of_Points[i].code << "\t" << List_of_Points[i].name << "\t" << List_of_Points[i].intro << "\t" << endl;;
	}
	save_file.close();
}

void Graph::readPointfile()
{
	ifstream read_file("�ص�.txt");
	if (!read_file.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
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
	savefile.open("·��.txt", ios::app);
	savefile << endl << point1 << "\t" << point2 << "\t" << w;
	savefile.close();
}

void Graph::readEdgefile()
{
	ifstream readfile("·��.txt");
	if (!readfile.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
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
	cout << "�������ͼ����������Ҫɾ������������ı�ţ�" << endl;
	cout << "��ʼ�ص㣺";
	cin >> code1;
	cout << "��ֹ�ص㣺";
	cin >> code2;
	//while (1)
	//{
	//	v1 = getPointPos(code1);
	//	v2 = getPointPos(code2);
	//	if (v1 == -1 || v2 == -1)
	//	{
	//		cout << "�����������������" << endl;
	//		cout << "��ʼ���㣺";
	//		cin >> code1;
	//		cout << "��ֹ���㣺";
	//		cin >> code2;
	//	}
	//	else
	//	{
	//		arcs[v1][v2] = 0;
	//		arcs[v2][v1] = 0;
	//		// ���±���
	//		numEdges--;

	//	}
	//}
	v1 = getPointPos(code1);
	v2 = getPointPos(code2);
	arcs[v1][v2] = 0;
	arcs[v2][v1] = 0;
	inEdgefile(v1,v2,arcs[v1][v2]);
	cout << "���س�������";
	
}

void Graph::delete_vertex()
{
	char code;
	cout << "����������ɾ���ĵص�" << endl;
	cin >> code;
	int point = getPointPos(code);
	List_of_Points[point].code = '\0';
	List_of_Points[point].name = "";
	List_of_Points[point].intro = "";
	List_of_Points[point].comments = "";
	// ���¶�����
	num_of_Points--;
	inPointfile();
	// �����ڽӾ�������ö�����صı߳�Ϊ0
	for (int i = 0; i < num_of_Points; i++) {
		//Edges[point][i] = 0;
		arcs[i][point] = 0;
		num_of_Edges--;
	}
}

void Graph::DFS(int v)
{
	// ��ǵ�ǰ�ڵ�Ϊ�ѷ���
	visited[v] = true;
	// �����ǰ�ڵ�
	cout << List_of_Points[v].name << "-> ";
	// ������ǰ�ڵ���ڽӽڵ�
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

	// ����һ���������ڴ洢�����ʵĽڵ�
	queue<int> q;
	// ��ǵ�ǰ�ڵ�Ϊ�ѷ���
	visited[v] = true;
	// ����ǰ�ڵ����
	q.push(v);
	while (!q.empty())
	{
		// ���Ӳ������ǰ�ڵ�
		int cur = q.front();
		q.pop();
		cout << List_of_Points[cur].name << "->";
		// ������ǰ�ڵ���ڽӽڵ�
		for (int i = 0; i < num_of_Points; i++)
		{
			if (arcs[cur][i] != 0 && arcs[cur][i] != maxValue && !visited[i])
			{
				// ����ڽӽڵ�Ϊ�ѷ��ʣ������
				visited[i] = true;
				q.push(i);
			}
		}
	}
	for (int j = 0; j <= num_of_Points; j++)
		visited[j] = false;
}
