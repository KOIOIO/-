#include "digraph.h"

void digraph::creatdigraph()//����ͼ
{
	cout << "�����붥�����Ŀ" << endl;
	cin >> vertexnum;//����ڵ���
	listhead = new vertex[vertexnum];//������Ӧ�ڵ����Ŀռ�
	for (int i = 0; i < vertexnum; i++)//����Ϊÿ�������ʼ��
	{
		cout << "�����붥��" << i << "������" << endl;//����������
		cin >> listhead[i].data;
		listhead[i].firstailarc = NULL;//��ÿ��������뻡�ͳ�����ֵΪ��
		listhead[i].firstheadarc = NULL;
	}
	cout << "�����뻡������" << endl;
	int v1, v2;
	cin >> arcnum;//���뻡������
	for (int i = 0; i < arcnum; i++)
	{
		cout << "��ֱ����뻡ͷ�ͻ�β�����ݣ��ÿո�ֿ���" << endl;
		cin >> v1;//���빹�ɻ�ͷ�ͻ�β����������
		cin >> v2;
		int h1 = gethead(v1);//ͨ������������ҵ���Ӧ���±�
		int h2 = gethead(v2);
		arc* newarc = new arc;//�����»���������
		newarc->headvertexx = h1;//���»�������λ��ָ���õ������±�
		newarc->tailvertex = h2;
		newarc->headlink = listhead[h1].firstheadarc;//�����뻡�ĵ�����
		listhead[h1].firstheadarc = newarc;//������ָ��h1��h1�ǻ�ͷ

		newarc->taillink = listhead[h2].firstailarc;//���������ĵ�����
		
		listhead[h2].firstailarc = newarc;//��������h2������h2�ǻ�β
	}
	cout << "�������" << endl;
}

int digraph::gethead(int value)
{
	int j;//�Ȼ᷵�ص��±�
	for (j = 0; j < vertexnum; j++)
	{
		if (listhead[j].data == value)//�������ֵ���������е�ֵ
		{
			break;//����ѭ��
		}
		
	}
	return j;//���±귵��
}

void digraph::getdegree()//���ÿ���ڵ�Ķ�
{
	int outdegree = 0;//����
	int indegree = 0;//���
	cout << "������Ҫ��ȵĶ���" << endl;
	int temp;
	cin >> temp;
	int ver = gethead(temp);//���ݻ�õ�ֵ���õ������±�
	arc* outptr = listhead[ver].firstailarc;//�½�һ��������ָ���һ��β��
	while (outptr)//��outptr��Ϊ��ʱ
	{
		outdegree++;//������++
		outptr = outptr->taillink;//���ų����Ľڵ�������
	}
	cout << "����Ϊ��" << outdegree << endl;//�������ӡ
	arc* inptr = listhead[ver].firstheadarc;//�½�һ��������ָ���һ��ͷ��
	while (inptr)//��inptr��Ϊ��
	{
		indegree++;//�뻡��++
		inptr = inptr->headlink;//�����뻡�Ľڵ�������
	}
	cout << "���Ϊ��" << indegree << endl;//���뻡����ӡ
	cout << "��Ϊ" << outdegree + indegree << endl;//��ӡ�ܶ�
}


void digraph::search()//����ĳ��Ԫ��
{
	int index;//�����±�
	cout << "��������Ҫ��ѯ�Ľڵ�ı��" << endl;
	cin >> index;//�����±�
	cout << listhead[index].data << endl;
	//ֱ�ӽ����±�����������
}

//void digraph::traverse()//������ӡ
//{
//	for (int i = 0; i < vertexnum; i++)//��������ֱ�ӷ���ÿ������
//	{
//		arc* current = listhead[i].firstheadarc;//��ָ��ָ��ڵ��ͷ��
//		while (current != nullptr)//��current��Ϊ��ʱ
//		{
//			cout << "Tail: " << current->tailvertex<<"-->" << " Head: " << current->headvertexx << endl;//��������Ļ�ͷ��βԪ���±��ӡ
//			current = current->taillink;
//		}
//	}
//}


void digraph::traverse() 
{
	cout << "�ڵ㼰������صĻ�" << endl;
	for (int i = 0; i < vertexnum; i++)
	{
		cout << "�ڵ��ֵ" << listhead[i].data << ":";
		if (listhead[i].firstailarc == nullptr && listhead[i].firstheadarc == nullptr)
		{
			cout << endl;
			continue;
		}
		arc* current = listhead[i].firstailarc;
		while (current != nullptr)
		{
			cout << "->(" << listhead[current->tailvertex].data << "," << listhead[current->headvertexx].data << ")";
			current = current->taillink;
		}
		cout << endl;
	}
	
}


/*void digraph::deletevertex(int value)
{
	for (int i = 0; i < vertexnum; i++)
	{
		if (listhead[i].data == value)
		{
			arc* current = listhead[i].firstheadarc;
			arc* pcurrent = listhead[i].firstailarc;
			while (current != nullptr)
			{
				arc* temp = current;
				current = current->taillink;
				delete temp;
				temp = nullptr;
			}
			while (pcurrent != nullptr)
			{
				arc* temp1 = pcurrent;
				pcurrent = pcurrent->headlink;
				delete temp1;
				temp1 = nullptr;
			}
			for (int j = i; j < vertexnum - 1; j++)
			{
				listhead[j] = listhead[j + 1];
			}
			vertexnum--;
			break;
		}
	}
}  */  

void digraph::deleteVertex(int value) 
{
	int index = gethead(value);
	if (index == -1)
	{
		cout << "�Ҳ����ýڵ�" << endl;
		return;
	}
	arc* current = listhead[index].firstailarc;
	while (current != nullptr)
	{
		arc* tempArc = current;
		current = current->taillink;
		arc** headLinkPtr = &listhead[tempArc->headvertexx].firstheadarc;
		while (*headLinkPtr != nullptr)
		{
			if (*headLinkPtr == tempArc)
			{
				*headLinkPtr = tempArc->headlink;
				break;
			}
			headLinkPtr = &((*headLinkPtr)->headlink);
		}
		delete tempArc;
		tempArc = nullptr;
		arcnum--;
	}
	current = listhead[index].firstheadarc;
	while (current != nullptr)
	{
		arc* tempArc = current;
		current = current->headlink;
		arc** tailLinkPtr = &listhead[tempArc->tailvertex].firstailarc;
		while (*tailLinkPtr != nullptr)
		{
			if (*tailLinkPtr == tempArc)
			{
				*tailLinkPtr = tempArc->taillink;
				break;
			}
			tailLinkPtr = &((*tailLinkPtr)->taillink);
		}
		delete tempArc;
		tempArc = nullptr;
		arcnum--;
	}
	for (int i = index; i < vertexnum - 1; i++)
	{
		listhead[i] = listhead[i + 1];
	}
	vertexnum--;
}


void digraph::modifyVertex(int oldValue, int newValue)
{
	for (int i = 0; i < vertexnum; i++)
	{
		if (listhead[i].data == oldValue)
		{
			listhead[i].data = newValue;
			break;
		}
	}
}

void digraph::DFS()
{
}

void digraph::BFS()
{
}
