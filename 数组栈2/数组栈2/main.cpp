#include"template_Stack.h"

void menu()
{
	cout << "\t\t\t\t\t\t" << "1.入栈" << endl;
	cout << "\t\t\t\t\t\t" << "2.出栈" << endl;
	cout << "\t\t\t\t\t\t" << "3.更改" << endl;
	cout << "\t\t\t\t\t\t" << "4.查询" << endl;
	cout << "\t\t\t\t\t\t" << "5.打印" << endl;
}
void main()
{
	template_Stack<int>int_Stack;
	while (1)

	{
		menu();
		cout << "请输入你的选择：" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int data;
			cout << "请输入数据" << endl;
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
			cout << "请输入你要更改的数据" << endl;
			cin >> da;
			int_Stack.Change(da);
		}break;
		case 4:
		{
			int d;
			cout << "请输入你要查询的数据" << endl;
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