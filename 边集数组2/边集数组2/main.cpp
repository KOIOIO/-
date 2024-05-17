#include"EdgeArray.h"
void menu()
{
	cout << " =============================================================================\n";
	cout << "||                     *********边集数组**********                            ||\n";
	cout << "||============================================================================||\n";
	cout << "||============================================================================||\n";
	cout << "||                     【1】--- 添加新弧                                      ||\n";
	cout << "||                     【2】--- 删除弧                                        ||\n";
	cout << "||                     【3】--- 打印节点的入度                                ||\n";
	cout << "||                     【4】--- 打印节点的出度                                ||\n";
	cout << "||                     【5】--- 遍历打印弧                                    ||\n";
	cout << "||                     【6】--- 修改弧的权值                                  ||\n";
	cout << "||                     【7】--- 退出程序                                      ||\n";
	cout << " ==============================================================================\n";
	cout << "请输入数字来选择对应的功能：";
}

int main()
{
	EdgeArray edge(3);
	cout << "********************************" << endl;
	cout << "创建图成功，开摇！！！！！！！！" << endl;
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
			cout << "请输入起始点的下标" << endl;
			cin >> start;
			cout << "请输入指向点的下标" << endl;
			cin >> end;
			cout << "请输入权值" << endl;
			cin >> weight;
			edge.addedge(start, end, weight);
		}break;
		case 2:
		{
			edge.printegdes();
			int index;
			cout << "请输入你要删除的边的下标" << endl;
			cin >> index;
			edge.removeadge(index);
		}break;
		case 3:
		{
			int vertex;
			cout << "请输入要查询的顶点的下标" << endl;
			cin >> vertex;
			cout << edge.getIndegree(vertex) << endl;
		}break;
		case 4:
		{
			int vertex2;
			cout << "请输入你要查询的顶点的下标" << endl;
			cin >> vertex2;
			cout << edge.getOutdegree(vertex2) << endl;
		}break;
		case 5:edge.printegdes(); break;
		case 6:
		{
			int i;
			cout << "请输入要操作弧的下标" << endl;
			cin >> i;
			int neweight;
			cout << "请输入新的权值" << endl;
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