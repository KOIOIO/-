#include "digraph.h"

void digraph::creatdigraph()//构建图
{
	cout << "请输入顶点的数目" << endl;
	cin >> vertexnum;//输入节点数
	listhead = new vertex[vertexnum];//开辟相应节点数的空间
	for (int i = 0; i < vertexnum; i++)//依次为每个顶点初始化
	{
		cout << "请输入顶点" << i << "的数据" << endl;//输入数据域
		cin >> listhead[i].data;
		listhead[i].firstailarc = NULL;//将每个顶点的入弧和出弧赋值为空
		listhead[i].firstheadarc = NULL;
	}
	cout << "请输入弧的数量" << endl;
	int v1, v2;
	cin >> arcnum;//输入弧的数量
	for (int i = 0; i < arcnum; i++)
	{
		cout << "请分别输入弧头和弧尾的数据（用空格分开）" << endl;
		cin >> v1;//输入构成弧头和弧尾的两个数据
		cin >> v2;
		int h1 = gethead(v1);//通过输入的数据找到对应的下表
		int h2 = gethead(v2);
		arc* newarc = new arc;//创建新弧用于连接
		newarc->headvertexx = h1;//将新弧的数据位置指向获得的两个下标
		newarc->tailvertex = h2;
		newarc->headlink = listhead[h1].firstheadarc;//创建入弧的单链表
		listhead[h1].firstheadarc = newarc;//这条弧指向h1，h1是弧头

		newarc->taillink = listhead[h2].firstailarc;//创建出弧的单链表
		
		listhead[h2].firstailarc = newarc;//这条弧从h2出发，h2是弧尾
	}
	cout << "构建完毕" << endl;
}

int digraph::gethead(int value)
{
	int j;//等会返回的下标
	for (j = 0; j < vertexnum; j++)
	{
		if (listhead[j].data == value)//当输入的值等于数组中的值
		{
			break;//跳出循环
		}
		
	}
	return j;//将下标返回
}

void digraph::getdegree()//获得每个节点的度
{
	int outdegree = 0;//出度
	int indegree = 0;//入度
	cout << "请输入要求度的顶点" << endl;
	int temp;
	cin >> temp;
	int ver = gethead(temp);//根据获得的值，得到数组下标
	arc* outptr = listhead[ver].firstailarc;//新建一个弧对象指向第一个尾弧
	while (outptr)//当outptr不为空时
	{
		outdegree++;//出弧数++
		outptr = outptr->taillink;//沿着出弧的节点向后遍历
	}
	cout << "出度为：" << outdegree << endl;//将结果打印
	arc* inptr = listhead[ver].firstheadarc;//新建一个弧对象指向第一个头弧
	while (inptr)//当inptr不为空
	{
		indegree++;//入弧数++
		inptr = inptr->headlink;//沿着入弧的节点向后遍历
	}
	cout << "入度为：" << indegree << endl;//将入弧数打印
	cout << "度为" << outdegree + indegree << endl;//打印总度
}


void digraph::search()//查找某个元素
{
	int index;//定义下标
	cout << "请输入你要查询的节点的编号" << endl;
	cin >> index;//输入下标
	cout << listhead[index].data << endl;
	//直接将该下标的数据域输出
}

//void digraph::traverse()//遍历打印
//{
//	for (int i = 0; i < vertexnum; i++)//按照数组直接访问每个数据
//	{
//		arc* current = listhead[i].firstheadarc;//用指针指向节点的头弧
//		while (current != nullptr)//当current不为空时
//		{
//			cout << "Tail: " << current->tailvertex<<"-->" << " Head: " << current->headvertexx << endl;//将这个弧的弧头弧尾元素下标打印
//			current = current->taillink;
//		}
//	}
//}


void digraph::traverse() 
{
	cout << "节点及与其相关的弧" << endl;
	for (int i = 0; i < vertexnum; i++)
	{
		cout << "节点的值" << listhead[i].data << ":";
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
		cout << "找不到该节点" << endl;
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
