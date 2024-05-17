#include"digraph.h"

void menu()
{
	cout << " =============================================================================\n";
	cout << "||                        *********十字链表**********                         ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     【1】--- 创建十字链表                                  ||\n";
	cout << "||                     【2】--- 打印相应节点的度                              ||\n";
	cout << "||                     【3】--- 查询相应节点                                  ||\n";
	cout << "||                     【4】--- 遍历打印节点                                  ||\n";
	cout << "||                     【5】--- 删除节点                                      ||\n";
	cout << "||                     【6】--- 修改节点                                      ||\n";
	cout << "||                     【7】--- 退出程序                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "请输入数字来选择对应的功能：";
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
			cout << "请输入你要删除的节点的值" << endl;
			cin >> value;
			dg.deleteVertex(value);
		}break;
		case 6:
		{
			int oldval;
			int newval;
			cout << "请输入要修改的节点的值和修改后的节点的值" << endl;
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