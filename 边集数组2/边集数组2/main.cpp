#include"EdgeArray.h"
void menu()
{
	cout << " =============================================================================\n";
	cout << "||                     *********�߼�����**********                            ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     ��1��--- ����»�                                      ||\n";
	cout << "||                     ��2��--- ɾ����                                        ||\n";
	cout << "||                     ��3��--- ��ӡ�ڵ�����                                ||\n";
	cout << "||                     ��4��--- ��ӡ�ڵ�ĳ���                                ||\n";
	cout << "||                     ��5��--- ������ӡ��                                    ||\n";
	cout << "||                     ��6��--- �޸Ļ���Ȩֵ                                  ||\n";
	cout << "||                     ��7��--- �˳�����                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "������������ѡ���Ӧ�Ĺ��ܣ�";
}

int main()
{
	EdgeArray edge(3);
	cout << "********************************" << endl;
	cout << "����ͼ�ɹ�����ҡ����������������" << endl;
	cout << "********************************" << endl;
	system("start https://www.bilibili.com/video/BV17G4y1U7jh/?spm_id_from=333.337.search-card.all.click&vd_source=95ea617be73fc056e6b99a7b93f38e96");
	while (1)
	{
		menu();
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int end, start, weight;
			cout << "��������ʼ����±�" << endl;
			cin >> start;
			cout << "������ָ�����±�" << endl;
			cin >> end;
			cout << "������Ȩֵ" << endl;
			cin >> weight;
			edge.addedge(start, end, weight);
		}break;
		case 2:
		{
			edge.printegdes();
			int index;
			cout << "��������Ҫɾ���ıߵ��±�" << endl;
			cin >> index;
			edge.removeadge(index);
		}break;
		case 3:
		{
			int vertex;
			cout << "������Ҫ��ѯ�Ķ�����±�" << endl;
			cin >> vertex;
			cout << edge.getIndegree(vertex) << endl;
		}break;
		case 4:
		{
			int vertex2;
			cout << "��������Ҫ��ѯ�Ķ�����±�" << endl;
			cin >> vertex2;
			cout << edge.getOutdegree(vertex2) << endl;
		}break;
		case 5:edge.printegdes(); break;
		case 6:
		{
			int i;
			cout << "������Ҫ���������±�" << endl;
			cin >> i;
			int neweight;
			cout << "�������µ�Ȩֵ" << endl;
			cin >> neweight;
			edge.updateedge(i, neweight);
		}break;
		case 7:
		{
			exit(0);
		}
		}
		system("pause");
		system("cls");
	}
}