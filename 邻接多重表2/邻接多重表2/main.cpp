#include"digraph.h"
void menu()
{
	cout << " =============================================================================\n";
	cout << "||                     *********邻接多重表**********                          ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     【1】--- 创建邻接多重表                                ||\n";
	cout << "||                     【2】--- 打印相应节点的度                              ||\n";
 	cout << "||                     【3】--- 查询相应节点                                  ||\n";
	cout << "||                     【4】--- 遍历打印节点                                  ||\n";
	cout << "||                     【5】--- 删除节点                                      ||\n";
	cout << "||                     【6】--- 修改节点                                      ||\n";
	cout << "||                     【7】--- 退出程序                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "请输入数字来选择对应的功能：";
}

int main()
{
	digraph g;
	while (1)
	{
		menu();
		int x;
		cin >> x;
		switch (x)
		{
		case 1:g.createundigraph(); break;
		case 2:g.getdegree(); break;
		case 3:g.search(); break;
		case 4:g.printGraph(); break;
		case 5:
		{
			int value;
			cout << "请输入你要删除的节点的值" << endl;
			cin >> value;
			g.deleteNode(value);
		}break;
		case 6:g.modify(); break;
		case 7:exit(0);
		}
		system("pause");
		system("cls");
	}
}