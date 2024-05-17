#include"Graph.h"
#include"template_class.h"
class Admin
{
private:
	string name;
	string password;
public:
	friend istream& operator>>(istream& in, Admin& obj)
	{
		cout << "请输入姓名:" << endl;
		in >> obj.name;
		cout << "请输入密码" << endl;
		in >> obj.password;
		return in;
	}

	friend ostream& operator<<(ostream& out, Admin& obj)
	{
		out << obj.name << "\t" << obj.password << endl;

		return out;
	}

	bool operator==(Admin& obj)
	{
		if (this->name == obj.name && this->password == obj.password)
			return true;
		else
			return false;
	}

	bool operator!=(Admin& obj)
	{
		if (this->name != obj.name || this->password != obj.password)
		{
			return true;
		}
		else
			return false;
	}
};

template_class<Admin>L;
void enroll()
{
	Admin data;
	cout << "请输入您的信息" << endl;
	cin >> data;
	L.init_list(data);
	L.save("Admin_list.txt");
}

bool registered()
{
	Admin data;
	cout << "请输入你的信息" << endl;
	cin >> data;
	L.read("Admin_list.txt");
	if (L.Check_list(data))
		return 1;
	else
	{
		cout << "用户名或密码错误，请从新输入" << endl;
		return 0;
	}
}

//进度条
void loading()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	int i;
	char m[300];
	memset(m, 0, 300);
	for (i = 0; i < 101; i++) {
		sprintf(&m[0], "%3d", i);
		m[3] = '%';
		m[4 + i] = '=';
		printf("\r%s>", m);
		fflush(stdout);
		Sleep(10);
	}
	printf("\n");
}

//起始页 
void start_menu()
{
	int i;
	for (i = 0; i < 5; i++)
		cout << endl;
	cout << "         =============================================" << endl;
	cout << "         ==                                         ==" << endl;
	cout << "         ==      欢迎使用南阳理工学院导航系统       ==" << endl;
	cout << "         ==                                         ==" << endl;
	cout << "         =============================================" << endl;
	for (i = 0; i < 5; i++)
		cout << endl;
	
}

//菜单页 
void meau()
{
	



	cout << " =============================================================================\n";
	cout << "||                     ********* 南工导航(用户版）**********                  ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     【1】--- 地点信息查询                                  ||\n";
	cout << "||                     【2】--- 增加您对于地点的备注                          ||\n";
	cout << "||                     【3】--- 查询两地点间最短距离                          ||\n";
	cout << "||                     【4】--- 查询两地点间采用不同出行方式的最短时长        ||\n";
	cout << "||                     【5】--- 查询多个地点间的最佳路径                      ||\n";
	cout << "||                     【6】--- 深度优先遍历                                  ||\n";
	cout << "||                     【7】--- 广度优先遍历                                  ||\n";
	cout << "||                     【0】--- 退出系统                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "请输入数字来选择对应的功能：" << endl;
}


void meau2()
{


	cout << " =============================================================================\n";
	cout << "||                     ********* 南工导航(用户版）**********                  ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     【1】--- 地点信息查询                                  ||\n";
	cout << "||                     【2】--- 增加您对于地点的备注                          ||\n";
	cout << "||                     【3】--- 查询两地点间最短距离                          ||\n";
	cout << "||                     【4】--- 查询两地点间采用不同出行方式的最短时长        ||\n";
	cout << "||                     【5】--- 查询多个地点间的最佳路径                      ||\n";
	cout << "||                     【6】--- 增加地点和道路(该功能为管理员功能)            ||\n";
	cout << "||                     【7】--- 删除道路(该功能为管理员功能)                  ||\n";
	cout << "||                     【8】--- 删除地点(该功能为管理员功能)                  ||\n";
	cout << "||                     【9】--- 深度优先遍历                                  ||\n";
	cout << "||                    【10】--- 广度优先遍历                                  ||\n";
	cout << "||                     【0】--- 退出系统                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "请输入数字来选择对应的功能：" << endl;
}

//	########################  程序主入口  ########################
int main1()
{

	system("color F9");

	Graph g;
	loading();
	Time t;
	int c;
	start_menu();

	while (1)
	{
		system("cls");
		meau();
		g.school_map();
		cout << "请输入您要执行功能的编号：（请输入数字！）";
		cin >> c;

		if (c < 0 || c>7)
		{
			cout << "输入错误，请重新输入！" << endl;
		
		}
		switch (c)
		{
		case 1://景点信息查询 
			g.search();
			break;
		case 2:
			g.insertcomments();
			break;
		case 3: //查询两景点间最短距离
			g.minest();
			break;
		case 4:
			g.showTime();
			break;
		case 5: //查询多个景点间的最佳路径
			g.ShowMany();
			break;
		case 6:
		{
			for (int j = 0; j <= g.GetnumPoint(); j++)
				g.visited[j] = false;
			g.DFS(0);

		}break;
		case 7:
		{
			for (int j = 0; j <= g.GetnumPoint(); j++)
				g.visited[j] = false;
			g.BFS(0);

		}break;
		case 0:  //结束程序 
			cout << "谢谢您的使用！" << endl;
			return 0;
		}
	}
	return 0; // 返回退出
}


int main2()
{

	system("color F9");
	Graph g;
	loading();
	Time t;
	int c;
	start_menu();
	system("pause");
	system("cls");

	
	while (1)
	{
		system("pause");
		system("cls");
		meau2();
		g.school_map();
		cout << "请输入您要执行功能的编号：（请输入数字！）";
		cin >> c;

		if (c < 0 || c>10)
		{
			cout << "输入错误，请重新输入！" << endl;
		}
		switch (c)
		{
		case 1://景点信息查询 
			g.search();
			break;
		case 2:
			g.insertcomments();
			break;
		case 3: //查询两景点间最短距离
			g.minest();
			break;
		case 4:
			g.showTime();
			break;
		case 5: //查询多个景点间的最佳路径
			g.ShowMany();
			break;
		case 6:
			g.Increase();
			break;
		case 7:
			g.delete_path();
			break;
		case 8:
			g.delete_vertex();
			break;
		case 9:
		{
			for (int j = 0; j <= g.GetnumPoint(); j++)
				g.visited[j] = false;
			g.DFS(0);

		}break;
		case 10:
		{
			for (int j = 0; j <= g.GetnumPoint(); j++)
				g.visited[j] = false;

			g.BFS(0);

		}break;
		case 0:  //结束程序 
			cout << "谢谢您的使用！" << endl;
			return 0;
		}
	}
	return 0; // 返回退出
}


int main()
{
	while (1)
	{
		cout << "你是用户还是管理员？【1】用户【2】管理员" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:main1(); break;
		case 2:
		{
			int v;
			cout << "【1】注册，【2】登录" << endl;
			cin >> v;
			switch (v)
			{
			case 1:
				enroll(); break;
			case 2:
				if (registered())
					main2();
				break;
			}
		}
		}
		system("pause");
		system("cls");
	}
}