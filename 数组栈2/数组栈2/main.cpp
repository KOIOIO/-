#include"template_Stack.h"

void menu()
{
	cout << "\t\t\t\t\t\t" << "1.��ջ" << endl;
	cout << "\t\t\t\t\t\t" << "2.��ջ" << endl;
	cout << "\t\t\t\t\t\t" << "3.����" << endl;
	cout << "\t\t\t\t\t\t" << "4.��ѯ" << endl;
	cout << "\t\t\t\t\t\t" << "5.��ӡ" << endl;
}
void main()
{
	template_Stack<int>int_Stack;
	while (1)

	{
		menu();
		cout << "���������ѡ��" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int data;
			cout << "����������" << endl;
			cin >> data;
			int_Stack.push(data);
		}break;
		case 2:
		{
			int_Stack.pop();
		}break;
		case 3:
		{
			int da;
			cout << "��������Ҫ���ĵ�����" << endl;
			cin >> da;
			int_Stack.Change(da);
		}break;
		case 4:
		{
			int d;
			cout << "��������Ҫ��ѯ������" << endl;
			cin >> d;
			int_Stack.search(d);
		}break;
		case 5:
		{
			int_Stack.print_Stack();
		}

		}
		system("pause");
		system("cls");

	}
}