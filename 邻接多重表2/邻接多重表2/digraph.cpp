#include "digraph.h"

digraph::digraph()
{
	//������ָ�븳ֵΪ��
	this->listhead = nullptr;
}

//��������ͼ
void digraph::createundigraph()
{
	int v1, v2;//�����ߵĶ����ֵ
	cout << "����������ͼ�Ķ������ͱ�����" << endl;

	cin >> vertexnum;//���붥����
	cin >> linenum;//���뻡�ĸ���

	//��Ϊֱ�Ӵ�1��ʼ��ţ�����ֱ�ӿ���һ���ռ�
	listhead = new vertex[vertexnum + 1];
	cout << "������ÿ�����������" << endl;
	for (int i = 1; i <= vertexnum; i++)
	{

		//��������ÿ�������������
		cin >> listhead[i].data;

		//������ĵ�һ���߸�ֵΪ��
		listhead[i].firstline = nullptr;
	}

	cout << "������ÿ���������ӵ���������" << endl;

	//���ݻ��������������Ӹ����ڵ�
	for (int i = 1; i <= linenum; i++)
	{

		//�������߽ڵ��ֵ
		cin >> v1;
		cin >> v2;

		//�õ������ڵ��λ��
		int h1 = gethead(v1);
		int h2 = gethead(v2);

		//Ϊ�����ٿռ�
		line* l = new line;

		//���������������λ�ý��и�ֵ
		l->vertex1 = h1;
		l->vertex2 = h2;

		l->ilink = listhead[h1].firstline;
		l->jlink = listhead[h2].firstline;
		
		listhead[h1].firstline = l;
		listhead[h2].firstline = l;
		cout << "���ӳɹ�" << endl;
	}
}

int digraph::gethead(int value)
{

	//��ʼ���±�Ϊ1
	int i = 1;

	//���α�������
	for (i = 1; i <= vertexnum; i++)
	{
		//�������е�ֵ�봫���ֵ��ͬ
		if (listhead[i].data == value)

			//���õ���ֵ����
			return i;
	}
}

void digraph::printGraph()
{
	//cout << "����ͼ���ڽӱ��ʾ����" << endl;
	////���ݶ�������������

	//for (int i = 1; i <= vertexnum; i++)
	//{
	//	//�����λ�ú��������ӡ
	//	cout << "����" << i << "(" << listhead[i].data << "):";

	//	//��ʼ��һ������ָ����Ӧ�ڵ�ĵ�һ����
	//	line* l = listhead[i].firstline;

	//	//��������Χ�Ķ����ֵ��ӡ
	//	while (l != nullptr)
	//	{
	//		if (l->vertex1 == i)
	//			cout << listhead[l->vertex2].data << " ";
	//		else
	//			cout << listhead[l->vertex1].data << " ";

	//		//���ڵ����
	//		l = (l->vertex1 == i) ? l->ilink : l->jlink;
	//	}

	//	cout << endl;
	//}


	cout << "����ͼ���ڽӱ��ʾ����" << endl;
	//���ݶ�������������

	for (int i = 1; i <= vertexnum; i++)
	{
		//�����λ�ú��������ӡ
		cout << "����" << i << "(" << listhead[i].data << "):";

		//��ʼ��һ������ָ����Ӧ�ڵ�ĵ�һ����
		line* l = listhead[i].firstline;

		//��������Χ�Ķ����ֵ��ӡ
		while (l != nullptr)
		{
			if (l->vertex1 == i)
				if (listhead[l->vertex2].data == NULL)
					cout << " ";
				else
					cout << listhead[l->vertex2].data << " ";
			else
				if (listhead[l->vertex1].data == NULL)
					cout << " ";
				else
					cout << listhead[l->vertex1].data << " ";
			//cout << listhead[l->vertex1].data << "  " << listhead[l->vertex2].data << " ";
			//���ڵ����
			//l = (l->vertex1 == i) ? l->ilink : l->jlink;
			if (l->vertex1 == i)
				l = l->ilink;
			else
				l = l->jlink;
		}

		cout << endl;
	}
}



void digraph::deleteNode(int value) {
	// �ҵ�Ҫɾ���Ľڵ��λ��
	int index = gethead(value);
	if (index == -1) {
		cout << "�ڵ㲻���ڣ�" << endl;
		return;
	}

	// ɾ����ýڵ���صı�
	line* p = listhead[index].firstline;
	while (p != nullptr) {
		// �ҵ���ڵ������ıߣ�ɾ��
		int v = p->vertex2;
		int j = gethead(v);
		line* pre = nullptr;
		line* q = listhead[j].firstline;
		while (q != nullptr && q->vertex2 != value) {
			pre = q;
			q = q->jlink;
		}
		if (pre == nullptr) {
			listhead[j].firstline = q->jlink;
		}
		else {
			pre->jlink = q->jlink;
		}
		delete q;
		p = p->ilink;
	}

	// ɾ���ýڵ�
	for (int i = index; i < vertexnum - 1; i++) {
		listhead[i] = listhead[i + 1];
	}
	vertexnum--;

	// ���������ڵ�ı�
	for (int i = 0; i < vertexnum; i++) {
		line* pre = nullptr;
		line* q = listhead[i].firstline;
		while (q != nullptr) {
			if (q->vertex2 == value) {
				if (pre == nullptr) {
					listhead[i].firstline = q->ilink;
				}
				else {
					pre->ilink = q->ilink;
				}
				delete q;
				linenum--;
				break;
			}
			pre = q;
			q = q->ilink;
		}
	}
}

//void digraph::deleteNode(int value)
//{
//	// ����Ҫɾ���Ľڵ�
//	vertex* current = listhead;
//	vertex* previous = nullptr;
//	while (current != nullptr && current->data != value)
//	{
//		previous = current;
//		current->firstline = current->firstline->ilink;
//	}
//
//	if (current == nullptr)
//	{
//		cout << "�ڵ㲻����" << endl;
//		return;
//	}
//
//	// ɾ����ýڵ���صı�
//	line* lineToDelete = current->firstline;
//	while (lineToDelete != nullptr)
//	{
//		line* nextLine = lineToDelete->ilink;
//
//		// ɾ����ñ���صĶ��������
//		vertex* vertex1 = listhead;
//		vertex* vertex2 = listhead;
//		while (vertex1 != nullptr && vertex1->data != lineToDelete->vertex1)
//		{
//			vertex1 ->firstline= vertex1->firstline->ilink;
//		}
//		while (vertex2 != nullptr && vertex2->data != lineToDelete->vertex2)
//		{
//			vertex2 ->firstline= vertex2->firstline->ilink;
//		}
//
//		// ɾ������1������
//		line* currentLine = vertex1->firstline;
//		line* previousLine = nullptr;
//		while (currentLine != nullptr && currentLine != lineToDelete)
//		{
//			previousLine = currentLine;
//			currentLine = currentLine->ilink;
//		}
//		if (previousLine == nullptr)
//		{
//			vertex1->firstline = currentLine->ilink;
//		}
//		else
//		{
//			previousLine->ilink = currentLine->ilink;
//		}
//
//		// ɾ������2������
//		currentLine = vertex2->firstline;
//		previousLine = nullptr;
//		while (currentLine != nullptr && currentLine != lineToDelete)
//		{
//			previousLine = currentLine;
//			currentLine = currentLine->jlink;
//		}
//		if (previousLine == nullptr)
//		{
//			vertex2->firstline = currentLine->jlink;
//		}
//		else
//		{
//			previousLine->jlink = currentLine->jlink;
//		}
//
//		delete lineToDelete;
//		lineToDelete = nextLine;
//	}
//
//	// ɾ���ڵ�
//	if (previous == nullptr)
//	{
//		listhead ->firstline= current->firstline->ilink;
//	}
//	else
//	{
//		previous->firstline->ilink = current->firstline->ilink;
//	}
//	delete current;
//
//	vertexnum--;
//	linenum--;
//}

//void digraph::deleteNode(int value)
//{
	////���ܵ�ɾ��������±�
	//int h = gethead(value);
	//line* l = listhead[h].firstline;

	////��ʼ��һ������ʹ�������������ĵ�һ����
	//line* l = listhead[h].firstline;
	//while (l != nullptr)
	//{
	//	int v = (l->vertex1 == h) ? l->vertex2 : l->vertex1;
	//	line* next = (l->vertex1 == h) ? l->ilink : l->jlink;

	//	line* prev = nullptr;
	//	line *temp = listhead[v].firstline;
	//	while (temp != nullptr && temp != l)
	//	{
	//		prev = temp;
	//		temp = (temp->vertex1 == v) ? temp->ilink : temp->jlink;
	//	}
	//	if (prev == nullptr)
	//		listhead[v].firstline = next;
	//	else
	//	{
	//		if (prev->vertex1 == v)
	//			prev->ilink = next;
	//		else
	//			prev->jlink = next;
	//	}
	//	delete l;
	//	l = nullptr;
	//	l = next;
	//}
	//listhead[h].firstline = nullptr;
	//for (int i = h; i < vertexnum ; i++)
	//{
	//	listhead[i] = listhead[i + 1];
	//}
	//vertexnum--;

	//int h = gethead(value);
	//line* l = listhead[h].firstline;
	//line* pcurrent = nullptr;
	//while (l != nullptr)
	//{
	//	pcurrent = l;
	//	l = (l->vertex1 == h) ? l->ilink : l->jlink;
	//	delete pcurrent;
	//}
	//for (int i = h; i < vertexnum ; i++)
	//{
	//	listhead[i] = listhead[i + 1];
	//}
	//vertexnum--;
	//vertexnum--;
	/*int index = gethead(value);
	if (index == -1)
	{
		cout << "�Ҳ����ýڵ�" << endl;
		return;
	}
	line* current = listhead[index].firstline;
	while (current != nullptr)
	{
		line* temp = current;
		current = current->jlink;
		line** link = &listhead[temp->vertex1].firstline;
		while (*link != nullptr)
		{
			if (*link == temp)
			{
				*link = temp->ilink;
				break;
			}
			link = &((*link)->ilink);
		}
		delete temp;
		temp = nullptr;
		linenum--;
	}
	current = listhead[index].firstline;
	while (current != nullptr)
	{
		line* temp = current;
		current = current->ilink;
		line** tlink = &listhead[temp->vertex2].firstline;
		while (*tlink != nullptr)
		{
			if (*tlink == temp)
			{
				*tlink == temp->jlink;
				break;
			}
			tlink = &((*tlink)->jlink);
		}
		delete temp;
		temp = nullptr;
		linenum--;
	}
	for (int i = index; i < vertexnum; i++)
	{
		listhead[i] = listhead[i + 1];

	}
	vertexnum--;*/


//}



void digraph::search()
{
	//����Ҫ���ҵĽڵ��ֵ
	int value;
	cout << "������Ҫ��ѯ�Ľڵ��ֵ��" << endl;
	cin >> value;


	int h = gethead(value);//�ȵ���Ӧֵ���±�
	cout << "�ڵ�" << value << "���ڽӽڵ�Ϊ:";


	//��ʼ��һ�����ڵ�Ϊ�ö���ĵ�һ����
	line* l = listhead[h].firstline;


	//һֱ����������Ӧ�����ֵ��ӡ
	while (l != nullptr)
	{
		if (l->vertex1 == h)
			cout << listhead[l->vertex2].data << " ";
		else
			cout << listhead[l->vertex1].data << " ";
		//l = (l->vertex1 == h) ? l->ilink : l->jlink;
		if (l->vertex1 == h)
			l = l->ilink;
		else
			l = l->jlink;
	}
	cout << endl;
}

void digraph::modify()
{
	//��ʼ��ֵ
	int value;
	cout << "������Ҫ�޸ĵĽڵ��ֵ" << endl;

	//����Ҫ���ֵ
	cin >> value;


	//�õ���Ӧ�������±�
	int h = gethead(value);
	int newvalue;
	cout << "�������µ�ֵ" << endl;


	//�����µ�ֵ
	cin >> newvalue;


	//���µ�ֵ��ֵ��ԭ����ֵ
	listhead[h].data = newvalue;
}

void digraph::getdegree()
{
	//����Ҫ��ѯ�Ľڵ��ֵ
	int value;
	cout << "������Ҫ����Ľڵ��ֵ" << endl;

	//�����ֵ����
	cin >> value;


	//�õ����ֵ���±�
	int h = gethead(value);


	//��ʼ�����ֵ�Ķ���Ϊ0
	int degree = 0;


	//��ʼ��һ�����ڵ�ָ��ö���ĵ�һ�׻�
	line* l = listhead[h].firstline;


	//������صĻ�������degree++��
	while (l != nullptr)
	{
		degree++;
		//l = (l->vertex1 == value) ? l->ilink : l->jlink;
		if (l->vertex1 == h)
			l = l->ilink;
		else
			l = l->jlink;
	}

	//�������ӡ
	cout << "�ڵ�" << value << "�Ķ�Ϊ" << degree << endl;
}

digraph::~digraph()
{
	//����������
	delete[]listhead;
}
