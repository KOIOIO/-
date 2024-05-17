#include"BinaryTree.h"
void menu()
{
	cout << "\t\t\t\t\t" << "[...*************************************************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*******************���������********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*************************************************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************1.��������**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************2.�������**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************3.�������**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************4.�������**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************5.��ȡ���**********************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************6.��ȡҶ�ӽڵ���****************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************7.��ȡͬ��ڵ�******************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************8.��ȡ�ڵ����ֵ****************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************9.��ȡ����˫��******************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************10.��ȫ������������*************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*****************11.��ӡ������*******************...]" << endl;
	cout << "\t\t\t\t\t" << "[...*************************************************...]" << endl;
}

int main()
{
	int size;
	cout << "���뿪����ȶ��ٵĶ�����?" << endl;
	cin >> size;
	BinaryTree<int> tree(size);
	
	while (1)
	{
		menu();
		int x;
		cout << "���������ѡ��" << endl;
		cin >> x;
		int n;
		switch (x)
		{
		case 1:
		{
			cout << "��������Ҫ���뼸��Ԫ��" << endl;
			
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
			cout << "���Ϊ��" << tree.getDepth() << endl;
		}break;
		case 6:
		{
			cout << "Ҷ�ӽڵ���Ϊ��" << tree.getLeafCount() << endl;
		}break;
		case 7:
		{
			int level;
			cout << "��Ҫ��ѯ��һ�㼶:" << endl;
			cin >> level;
			tree.print_same_level(level);
		}break;
		case 8:
		{
			cout << "���ֵ��" << tree.getMAxValue() << endl;
		}break;
		case 9:
		{
			cout << "�����뺢�ӽڵ���±�" << endl;
			int index;
			cin >> index;
			cout << "���ӵ�˫��Ϊ��" << tree.getParent(index) << endl;
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