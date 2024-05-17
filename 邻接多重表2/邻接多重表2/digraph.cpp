#include "digraph.h"

digraph::digraph()
{
	//将数组指针赋值为空
	this->listhead = nullptr;
}

//创建无向图
void digraph::createundigraph()
{
	int v1, v2;//弧两边的顶点的值
	cout << "请输入无向图的顶点数和边数：" << endl;

	cin >> vertexnum;//输入顶点数
	cin >> linenum;//输入弧的个数

	//因为直接从1开始编号，所以直接开大一个空间
	listhead = new vertex[vertexnum + 1];
	cout << "请输入每个顶点的数据" << endl;
	for (int i = 1; i <= vertexnum; i++)
	{

		//依次输入每个顶点的数据域
		cin >> listhead[i].data;

		//将顶点的第一条边赋值为空
		listhead[i].firstline = nullptr;
	}

	cout << "请输入每条边所连接的两个顶点" << endl;

	//根据弧的数量依次链接各个节点
	for (int i = 1; i <= linenum; i++)
	{

		//输入两边节点的值
		cin >> v1;
		cin >> v2;

		//得到两个节点的位置
		int h1 = gethead(v1);
		int h2 = gethead(v2);

		//为弧开辟空间
		line* l = new line;

		//将弧中两个顶点的位置进行赋值
		l->vertex1 = h1;
		l->vertex2 = h2;

		l->ilink = listhead[h1].firstline;
		l->jlink = listhead[h2].firstline;
		
		listhead[h1].firstline = l;
		listhead[h2].firstline = l;
		cout << "链接成功" << endl;
	}
}

int digraph::gethead(int value)
{

	//初始化下标为1
	int i = 1;

	//依次遍历数组
	for (i = 1; i <= vertexnum; i++)
	{
		//当数组中的值与传入的值相同
		if (listhead[i].data == value)

			//将得到的值返回
			return i;
	}
}

void digraph::printGraph()
{
	//cout << "无向图的邻接表表示如下" << endl;
	////根据定点数遍历数组

	//for (int i = 1; i <= vertexnum; i++)
	//{
	//	//将点的位置和数据域打印
	//	cout << "顶点" << i << "(" << listhead[i].data << "):";

	//	//初始化一个弧，指向相应节点的第一条边
	//	line* l = listhead[i].firstline;

	//	//将顶点周围的顶点的值打印
	//	while (l != nullptr)
	//	{
	//		if (l->vertex1 == i)
	//			cout << listhead[l->vertex2].data << " ";
	//		else
	//			cout << listhead[l->vertex1].data << " ";

	//		//弧节点遍历
	//		l = (l->vertex1 == i) ? l->ilink : l->jlink;
	//	}

	//	cout << endl;
	//}


	cout << "无向图的邻接表表示如下" << endl;
	//根据定点数遍历数组

	for (int i = 1; i <= vertexnum; i++)
	{
		//将点的位置和数据域打印
		cout << "顶点" << i << "(" << listhead[i].data << "):";

		//初始化一个弧，指向相应节点的第一条边
		line* l = listhead[i].firstline;

		//将顶点周围的顶点的值打印
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
			//弧节点遍历
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
	// 找到要删除的节点的位置
	int index = gethead(value);
	if (index == -1) {
		cout << "节点不存在！" << endl;
		return;
	}

	// 删除与该节点相关的边
	line* p = listhead[index].firstline;
	while (p != nullptr) {
		// 找到与节点相连的边，删除
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

	// 删除该节点
	for (int i = index; i < vertexnum - 1; i++) {
		listhead[i] = listhead[i + 1];
	}
	vertexnum--;

	// 调整其他节点的边
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
//	// 查找要删除的节点
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
//		cout << "节点不存在" << endl;
//		return;
//	}
//
//	// 删除与该节点相关的边
//	line* lineToDelete = current->firstline;
//	while (lineToDelete != nullptr)
//	{
//		line* nextLine = lineToDelete->ilink;
//
//		// 删除与该边相关的顶点的链接
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
//		// 删除顶点1的链接
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
//		// 删除顶点2的链接
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
//	// 删除节点
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
	////接受到删除顶点的下标
	//int h = gethead(value);
	//line* l = listhead[h].firstline;

	////初始化一条弧，使它等于这个顶点的第一条弧
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
		cout << "找不到该节点" << endl;
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
	//定义要查找的节点的值
	int value;
	cout << "请输入要查询的节点的值：" << endl;
	cin >> value;


	int h = gethead(value);//等到相应值的下标
	cout << "节点" << value << "的邻接节点为:";


	//初始化一个弧节点为该顶点的第一条弧
	line* l = listhead[h].firstline;


	//一直遍历并将相应顶点的值打印
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
	//初始化值
	int value;
	cout << "请输入要修改的节点的值" << endl;

	//输入要求的值
	cin >> value;


	//得到相应的数组下标
	int h = gethead(value);
	int newvalue;
	cout << "请输入新的值" << endl;


	//输入新的值
	cin >> newvalue;


	//将新的值赋值给原来的值
	listhead[h].data = newvalue;
}

void digraph::getdegree()
{
	//定义要查询的节点的值
	int value;
	cout << "请输入要计算的节点的值" << endl;

	//将这个值输入
	cin >> value;


	//得到这个值的下标
	int h = gethead(value);


	//初始化这个值的度数为0
	int degree = 0;


	//初始化一个弧节点指向该顶点的第一套弧
	line* l = listhead[h].firstline;


	//遍历相关的弧，并将degree++；
	while (l != nullptr)
	{
		degree++;
		//l = (l->vertex1 == value) ? l->ilink : l->jlink;
		if (l->vertex1 == h)
			l = l->ilink;
		else
			l = l->jlink;
	}

	//将结果打印
	cout << "节点" << value << "的度为" << degree << endl;
}

digraph::~digraph()
{
	//将数组析构
	delete[]listhead;
}
