#include"BInaryTree.h"
#include"Leader.h"
void menu()
{
	cout << "\t\t\t\t\t" << "[*************************************************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************链式二叉树**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*************************************************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************1.插入数据**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************2.中序遍历**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************3.后序遍历**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************4.先序遍历**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************5.获取深度**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************6.获取叶子节点数****************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************7.获取同层节点******************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************8.获取节点最大值****************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************9.获取孩子双亲******************]" << endl;
	cout << "\t\t\t\t\t" << "[*************************************************]" << endl;
}



int main()
{
	BinaryTree<int>Tree;
	while (1)
	{
		menu();
		int x;
		cout << "请输入你的选择" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int data;
			cout << "请输入你的数据" << endl;
			cin >> data;
			Tree.insert(data);
		}break;
		case 2:
		{
			Tree.leftTraversal();
		}break;
		case 3:
		{
			Tree.rightTraversal();
		}break;
		case 4:
		{
			Tree.midTraversal();
		}break;
		case 5:
		{
			cout << "二叉树深度：" << Tree.getDepth() << endl;
		}break;
		case 6:
		{
			cout << "二叉树叶子节点个数：" << Tree.getleafCount() << endl;
		}break;
		case 7:
		{
			int level;
			cout << "你要查询哪一层？" << endl;
			cin >> level;
			Tree.printsamelevel(level);
		}break;
		case 8:
		{
			cout << "所有节点最大值：" << Tree.getMaxvalue() << endl;
		}break;
		case 9:
		{
			int val;
			cout << "请输入你要查找的值" << endl;
			cin >> val;
			cout << "改节点的双亲：" << Tree.getParentNode(val) << endl;
		}
		}
		system("pause");
		system("cls");
	}
}