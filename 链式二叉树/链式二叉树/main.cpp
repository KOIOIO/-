#include"BInaryTree.h"
#include"Leader.h"
void menu()
{
	cout << "\t\t\t\t\t" << "[*************************************************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************��ʽ������**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*************************************************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************1.��������**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************2.�������**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************3.�������**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************4.�������**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************5.��ȡ���**********************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************6.��ȡҶ�ӽڵ���****************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************7.��ȡͬ��ڵ�******************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************8.��ȡ�ڵ����ֵ****************]" << endl;
	cout << "\t\t\t\t\t" << "[*****************9.��ȡ����˫��******************]" << endl;
	cout << "\t\t\t\t\t" << "[*************************************************]" << endl;
}



int main()
{
	BinaryTree<int>Tree;
	while (1)
	{
		menu();
		int x;
		cout << "���������ѡ��" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int data;
			cout << "�������������" << endl;
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
			cout << "��������ȣ�" << Tree.getDepth() << endl;
		}break;
		case 6:
		{
			cout << "������Ҷ�ӽڵ������" << Tree.getleafCount() << endl;
		}break;
		case 7:
		{
			int level;
			cout << "��Ҫ��ѯ��һ�㣿" << endl;
			cin >> level;
			Tree.printsamelevel(level);
		}break;
		case 8:
		{
			cout << "���нڵ����ֵ��" << Tree.getMaxvalue() << endl;
		}break;
		case 9:
		{
			int val;
			cout << "��������Ҫ���ҵ�ֵ" << endl;
			cin >> val;
			cout << "�Ľڵ��˫�ף�" << Tree.getParentNode(val) << endl;
		}
		}
		system("pause");
		system("cls");
	}
}