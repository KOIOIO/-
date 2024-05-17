#include"template_class.h"
#include"Book.h"
#include<stdlib.h>

void menu()
{
	cout <<"\t\t\t\t\t\t" << "*************************" << endl;
	cout << "\t\t\t\t\t\t" << "********图书管理*********" << endl;
	cout << "\t\t\t\t\t\t" << "******1.添加书籍*********" << endl;
	cout << "\t\t\t\t\t\t" << "******2.删除书籍*********" << endl;
	cout << "\t\t\t\t\t\t" << "******3.更改书籍*********" << endl;
	cout << "\t\t\t\t\t\t" << "******4.查询书籍*********" << endl;
	cout << "\t\t\t\t\t\t" << "******5.打印书籍*********" << endl;
	cout << "\t\t\t\t\t\t" << "******0.退出系统*********" << endl;
	cout << "\t\t\t\t\t\t" << "*************************" << endl;
}
int main()
{
	template_class<Book>L;
	L.read();
	while (true)
	{
		menu();
		cout << "请输入你的选择" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			Book data;
			//while (1)
			//{
				
				cout << "请输入图书信息" << endl;
				cin >> data;
				//if (L.check_list(data))
				//{
					//continue;
				//}
			//}
			L.insert_list(data);
			L.save();
		}break;
		case 2:
		{
			Book dat;
			cout << "请输入要删除的图书信息(只要序号输对即可)" << endl;
			cin >> dat;
			L.delete_list(dat);
			L.save();
		}break;
		case 3:
		{
			Book da;
			cout << "请输入你要更改的书籍信息（序号输对即可）" << endl;
			cin >> da;
			L.change_list(da);
			L.save();
		}break;
		case 4:
		{
			Book d;
			cout << "请输入你要查询的书籍的信息（序号输对即可）" << endl;
			cin >> d;
			cout << "书号" << "\t" << "书名" << "\t" << "作者" << endl;
			L.search_list(d);

		}break;
		case 5:
		{
			cout << "书号" << "\t" << "书名" << "\t" << "作者" << endl;
			L.print_list();
		}break;
		case 0:
		{
			exit(0);
		}
		}
		system("pause");
		system("cls");
	}
}