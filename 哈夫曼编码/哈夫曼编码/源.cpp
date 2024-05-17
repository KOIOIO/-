
#include<iostream>
#include<string>
using namespace std;

class node 
{
public:
	char value;
	int weight;//Ȩ��
	node* left;
	node* right;
	string code;//����
	int date;
	node() 
	{
		left = NULL;
		right = NULL;
		date = 0;
		weight = 0;
	}
	node(int a) 
	{
		this->weight = a;
	}
	void showa() 
	{
		cout << value << "  " << weight << "  " << code << endl;

	}
};
void note(int notes[][127], string  target) 
{	//���н�������
	for (int i = 0; i < 127; i++) 
	{//��¼ÿ����ĸ���ִ���
		notes[0][i] = 0 + i;//�����е�һ�ж��ֱ��¼һ��Сд��ĸ�ı��룬
	}

	for (char a : target) {//a���ε���target�е�ֵ
		for (int i = 0; i < 127; i++) 
		{
			if (notes[0][i] == a) 
			{
				notes[1][i]++;
				break;
			}
		}
	}
}
void set_array(node target1[], int& j, int notes[][127]) 
{//������������
	cout << "�����г��ֵ��ַ�������ֵĴ�������" << endl;
	for (int i = 0; i < 127; i++) 
	{
		if (notes[1][i] != 0) 
		{
			cout << (char)notes[0][i] << ":" << notes[1][i] << endl;
			target1[j].value = (char)notes[0][i];//�����洢�ַ���Ȩ�ص�����
			target1[j].date = 1;
			target1[j++].weight = notes[1][i];
		}
	}
}
void popo(node target1[], int last, int farst) 
{//����ð�����򣬽��������Ȩ�ر�ɵ�������
	for (int i = farst; i < last - 1; i++) 
	{
		for (int j = farst; j < last - 1; j++) 
		{
			if (target1[j].weight > target1[j + 1].weight) 
			{
				node temp;
				temp = target1[j];
				target1[j] = target1[j + 1];
				target1[j + 1] = temp;
			}
		}
	}
}
void set_Hafuman(node target1[], int& farst, node target2[], int& s) 
{//ȡ�������ǰ����������Ͷ�뵽���������У������ٽ�����ǰ����ɾ���������½�ϵ���
	target2[s].weight = target1[farst].weight + target1[farst + 1].weight;
	target2[s + 1] = target1[farst];
	target2[s + 2] = target1[farst + 1];
	target2[s].left = &target2[s + 1];
	target2[s].right = &target2[s + 2];
	farst++;
	target1[farst] = target2[s];
	s = s + 3;
}
void show(node* x, string h, node target3[], int& e) 
{//hΪ����
	if (x->date == 1) 
	{//���ʱָ�����Ҷ�ӽڵ�
		x->code = h;
		cout << x->value << ':' << h << endl;
		target3[e].value = x->value;
		target3[e++].code = x->code;
		return;
	}
	show(x->left, h + "0", target3, e);
	show(x->right, h + "1", target3, e);
}
void show2(string target, node target3[], int last) 
{//չʾ���Ķ�Ӧ����
	cout << "���Ķ�Ӧ����Ϊ��" << endl;
	for (char a : target) 
	{
		for (int i = 0; i < 100; i++) 
		{
			if (a == target3[i].value) 
			{
				cout << target3[i].code << " ";
				break;
			}
		}
	}
	cout << endl;

}
void decode(node target3[], int last) 
{
	string target;
	string p = "";
	cout << "����0-1�����ƴ�����e���˳���";
	cin >> target;
	while (target != "e") 
	{
		string he = "";
		for (char a : target) 
		{
			he += a;
			for (int i = 0; i < last; i++) 
			{
				if (he == target3[i].code) 
				{
					p += target3[i].value;
					p += " ";
					he = "";
					break;
				}
			}
		}
		if (he != "") 
		{
			cout << "��������޷�ת����" << endl << endl;
		}
		else
		{
			cout << "����ת���ĵ���Ϊ��" << p << endl << endl;
		}
		p = "";
		cout << "����0-1�����ƴ�����e���˳���";
		cin >> target;
	}
}

void menu()
{
	cout << " ==============================================================================" << endl;
	cout << "||                   �����������������������������������                     ||" << endl;
	cout << "||============================================================================||" << endl;
	cout << "||============================================================================||" << endl;
	cout << "||                     ��1��--- ����ʮ�����ַ�                                ||" << endl;
	cout << "||                     ��2��--- ���й���������                                ||" << endl;
	cout << "||                     ��3��--- ���й���������                                ||" << endl;
	cout << "||                     ��4��--- �˳�����                                      ||" << endl;
	cout << " ==============================================================================" << endl;
	cout << "������������ѡ���Ӧ�Ĺ��ܣ�";
}
int main() {
	//���ն�
	
	int last = 0;//ָ�����һ����Ч����Ԫ�صĺ�һ��
	int farst = 0;
	int notes[2][127] = { 0 };//�����ʼ��Ϊ0.
	node target1[127];//��ʼ��¼��Ч�ڵ�
	node target2[127];//�洢�����������нڵ�
	node target3[127];//��¼��Ч�ڵ�,��ʱ���ڽڵ�����ÿ���ڵ��codeֵ
	int s = 0;//��������ڵ������
	string target;
	while (1)
	{
		menu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
		{
			cout << "������ģ�";
			//cin.getline(target,5)//����for��eachѭ������
			//cin.getline(target,100);
			//gets(target);
			//getline(cin, target);
			cin >> target;
		/*	for (int i = 0; i <= 1024; i++)
			{
				target[i] = getchar();
				if (target[i] == "\n")
				{
					break;
				}
				else
					continue;
			}*/
			note(notes, target);
			set_array(target1, last, notes);//��������
			//������������
		}break;
		case 2:
		{
			int z = 0;
			int e = 0;
			while (last - farst != 1) {
				popo(target1, last, farst);
				set_Hafuman(target1, farst, target2, s);
			}
			node x;
			x = target1[farst];
			cout << "�����г��ֵ��ַ��Ĺ������������£�" << endl;
			show(&x, "", target3, e);
			show2(target, target3, last);
		}break;
		case 3:
		{
			cout << endl << endl;
			decode(target3, last);
		}break;
		case 4:
		{
			exit(0);
		}
		}
		system("pause");
		system("cls");
	}
	
	
	
}

//int main()
//{
//	string ch;
//	getline(cin, ch);
//	cout << ch;
