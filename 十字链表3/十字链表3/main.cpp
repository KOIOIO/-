#include"digraph.h"

void menu()
{
	cout << " =============================================================================\n";
	cout << "||                        *********ʮ������**********                         ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     ��1��--- ����ʮ������                                  ||\n";
	cout << "||                     ��2��--- ��ӡ��Ӧ�ڵ�Ķ�                              ||\n";
	cout << "||                     ��3��--- ��ѯ��Ӧ�ڵ�                                  ||\n";
	cout << "||                     ��4��--- ������ӡ�ڵ�                                  ||\n";
	cout << "||                     ��5��--- ɾ���ڵ�                                      ||\n";
	cout << "||                     ��6��--- �޸Ľڵ�                                      ||\n";
	cout << "||                     ��7��--- �˳�����                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "������������ѡ���Ӧ�Ĺ��ܣ�";
}


void main()
{
	digraph dg;
	while (1)
	{
		menu();
		int x;
		cin >> x;
		switch (x)
		{
		case 1:dg.creatdigraph(); break;
		case 2:dg.getdegree(); break;
		case 3:dg.search();break;
		case 4:dg.traverse(); break;
		case 5:
		{
			int value;
			cout << "��������Ҫɾ���Ľڵ��ֵ" << endl;
			cin >> value;
			dg.deleteVertex(value);
		}break;
		case 6:
		{
			int oldval;
			int newval;
			cout << "������Ҫ�޸ĵĽڵ��ֵ���޸ĺ�Ľڵ��ֵ" << endl;
			cin >> oldval;
			cin >> newval;
			dg.modifyVertex(oldval, newval);
		}break;
		case 7:exit(0);
		}
		system("pause");
		system("cls");
	}
}