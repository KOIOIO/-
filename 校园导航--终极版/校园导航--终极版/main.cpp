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
		cout << "����������:" << endl;
		in >> obj.name;
		cout << "����������" << endl;
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
	cout << "������������Ϣ" << endl;
	cin >> data;
	L.init_list(data);
	L.save("Admin_list.txt");
}

bool registered()
{
	Admin data;
	cout << "�����������Ϣ" << endl;
	cin >> data;
	L.read("Admin_list.txt");
	if (L.Check_list(data))
		return 1;
	else
	{
		cout << "�û���������������������" << endl;
		return 0;
	}
}

//������
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

//��ʼҳ 
void start_menu()
{
	int i;
	for (i = 0; i < 5; i++)
		cout << endl;
	cout << "         =============================================" << endl;
	cout << "         ==                                         ==" << endl;
	cout << "         ==      ��ӭʹ��������ѧԺ����ϵͳ       ==" << endl;
	cout << "         ==                                         ==" << endl;
	cout << "         =============================================" << endl;
	for (i = 0; i < 5; i++)
		cout << endl;
	
}

//�˵�ҳ 
void meau()
{
	



	cout << " =============================================================================\n";
	cout << "||                     ********* �Ϲ�����(�û��棩**********                  ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     ��1��--- �ص���Ϣ��ѯ                                  ||\n";
	cout << "||                     ��2��--- ���������ڵص�ı�ע                          ||\n";
	cout << "||                     ��3��--- ��ѯ���ص����̾���                          ||\n";
	cout << "||                     ��4��--- ��ѯ���ص����ò�ͬ���з�ʽ�����ʱ��        ||\n";
	cout << "||                     ��5��--- ��ѯ����ص������·��                      ||\n";
	cout << "||                     ��6��--- ������ȱ���                                  ||\n";
	cout << "||                     ��7��--- ������ȱ���                                  ||\n";
	cout << "||                     ��0��--- �˳�ϵͳ                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "������������ѡ���Ӧ�Ĺ��ܣ�" << endl;
}


void meau2()
{


	cout << " =============================================================================\n";
	cout << "||                     ********* �Ϲ�����(�û��棩**********                  ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     ��1��--- �ص���Ϣ��ѯ                                  ||\n";
	cout << "||                     ��2��--- ���������ڵص�ı�ע                          ||\n";
	cout << "||                     ��3��--- ��ѯ���ص����̾���                          ||\n";
	cout << "||                     ��4��--- ��ѯ���ص����ò�ͬ���з�ʽ�����ʱ��        ||\n";
	cout << "||                     ��5��--- ��ѯ����ص������·��                      ||\n";
	cout << "||                     ��6��--- ���ӵص�͵�·(�ù���Ϊ����Ա����)            ||\n";
	cout << "||                     ��7��--- ɾ����·(�ù���Ϊ����Ա����)                  ||\n";
	cout << "||                     ��8��--- ɾ���ص�(�ù���Ϊ����Ա����)                  ||\n";
	cout << "||                     ��9��--- ������ȱ���                                  ||\n";
	cout << "||                    ��10��--- ������ȱ���                                  ||\n";
	cout << "||                     ��0��--- �˳�ϵͳ                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "������������ѡ���Ӧ�Ĺ��ܣ�" << endl;
}

//	########################  ���������  ########################
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
		cout << "��������Ҫִ�й��ܵı�ţ������������֣���";
		cin >> c;

		if (c < 0 || c>7)
		{
			cout << "����������������룡" << endl;
		
		}
		switch (c)
		{
		case 1://������Ϣ��ѯ 
			g.search();
			break;
		case 2:
			g.insertcomments();
			break;
		case 3: //��ѯ���������̾���
			g.minest();
			break;
		case 4:
			g.showTime();
			break;
		case 5: //��ѯ������������·��
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
		case 0:  //�������� 
			cout << "лл����ʹ�ã�" << endl;
			return 0;
		}
	}
	return 0; // �����˳�
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
		cout << "��������Ҫִ�й��ܵı�ţ������������֣���";
		cin >> c;

		if (c < 0 || c>10)
		{
			cout << "����������������룡" << endl;
		}
		switch (c)
		{
		case 1://������Ϣ��ѯ 
			g.search();
			break;
		case 2:
			g.insertcomments();
			break;
		case 3: //��ѯ���������̾���
			g.minest();
			break;
		case 4:
			g.showTime();
			break;
		case 5: //��ѯ������������·��
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
		case 0:  //�������� 
			cout << "лл����ʹ�ã�" << endl;
			return 0;
		}
	}
	return 0; // �����˳�
}


int main()
{
	while (1)
	{
		cout << "�����û����ǹ���Ա����1���û���2������Ա" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:main1(); break;
		case 2:
		{
			int v;
			cout << "��1��ע�ᣬ��2����¼" << endl;
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