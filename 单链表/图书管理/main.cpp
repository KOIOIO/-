#include"template_class.h"
#include"Book.h"
#include<stdlib.h>

void menu()
{
	cout <<"\t\t\t\t\t\t" << "*************************" << endl;
	cout << "\t\t\t\t\t\t" << "********ͼ�����*********" << endl;
	cout << "\t\t\t\t\t\t" << "******1.����鼮*********" << endl;
	cout << "\t\t\t\t\t\t" << "******2.ɾ���鼮*********" << endl;
	cout << "\t\t\t\t\t\t" << "******3.�����鼮*********" << endl;
	cout << "\t\t\t\t\t\t" << "******4.��ѯ�鼮*********" << endl;
	cout << "\t\t\t\t\t\t" << "******5.��ӡ�鼮*********" << endl;
	cout << "\t\t\t\t\t\t" << "******0.�˳�ϵͳ*********" << endl;
	cout << "\t\t\t\t\t\t" << "*************************" << endl;
}
int main()
{
	template_class<Book>L;
	L.read();
	while (true)
	{
		menu();
		cout << "���������ѡ��" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			Book data;
			//while (1)
			//{
				
				cout << "������ͼ����Ϣ" << endl;
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
			cout << "������Ҫɾ����ͼ����Ϣ(ֻҪ�����Լ���)" << endl;
			cin >> dat;
			L.delete_list(dat);
			L.save();
		}break;
		case 3:
		{
			Book da;
			cout << "��������Ҫ���ĵ��鼮��Ϣ�������Լ��ɣ�" << endl;
			cin >> da;
			L.change_list(da);
			L.save();
		}break;
		case 4:
		{
			Book d;
			cout << "��������Ҫ��ѯ���鼮����Ϣ�������Լ��ɣ�" << endl;
			cin >> d;
			cout << "���" << "\t" << "����" << "\t" << "����" << endl;
			L.search_list(d);

		}break;
		case 5:
		{
			cout << "���" << "\t" << "����" << "\t" << "����" << endl;
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