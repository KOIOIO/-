#include"BinaryTree.h"
void menu()
{
	cout << "\t\t\t\t\t" << "[...*************************************************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*******************数组二叉树********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*************************************************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************1.插入数据**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************2.先序遍历**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************3.中序遍历**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************4.后序遍历**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************5.获取深度**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************6.获取叶子节点数****************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************7.获取同层节点******************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************8.获取节点最大值****************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************9.获取孩子双亲******************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************10.完全二叉树堆排序*************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************11.打印二叉树*******************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*************************************************...]" << endl;
}

int main()
{
	int size;
	cout << "您想开个深度多少的二叉树?" << endl;
	cin >> size;
	BinaryTree<int> tree(size);
	
	while (1)
	{
		menu();
		int x;
		cout << "请输入你的选择：" << endl;
		cin >> x;
		int n;
		switch (x)
		{
		case 1:
		{
			cout << "请输入你要插入几个元素" << endl;
			
			cin >> n;
			tree.insert(n);
		}break;
		case 2:
		{
			tree.preTraversal(0);
		}break;
		case 3:
		{
			tree.midTraversal(0);
		}break;
		case 4:
		{
			tree.posTraversal(0);
		}break;
		case 5:
		{
			cout << "深度为：" << tree.getDepth() << endl;
		}break;
		case 6:
		{
			cout << "叶子节点数为：" << tree.getLeafCount() << endl;
		}break;
		case 7:
		{
			int level;
			cout << "你要查询哪一层级:" << endl;
			cin >> level;
			tree.print_same_level(level);
		}break;
		case 8:
		{
			cout << "最大值：" << tree.getMAxValue() << endl;
		}break;
		case 9:
		{
			cout << "请输入孩子节点的下表" << endl;
			int index;
			cin >> index;
			cout << "孩子的双亲为：" << tree.getParent(index) << endl;
		}break;
		case 10:
		{
			tree.heapSort(n);
		}break;
		case 11:
		{
			tree.printtree();
		}break;
		}
		system("pause");
		system("cls");
	}
}