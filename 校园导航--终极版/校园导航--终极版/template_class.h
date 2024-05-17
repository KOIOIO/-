
#pragma once
#include"iostream"
#include"fstream"

using namespace std;
template<typename T>
class template_class
{
private:
	T data;
public:
	template_class<T>* head;//头节点
	template_class<T>* next;//后继指针
	template_class<T>* pior;//前驱指针
	template_class();//构造函数
	~template_class();//析构函数
public:
	void init_list(T data);//添加节点
	void delet_list(T data);//删除节点
	void Change_list(T data);//改变节点数据
	void search_list(T data);//搜索节点
	void print_list();//打印整条链表
	int Check_list(T data);//检查新元素是否已经存在
	void Sort_list();//排序

	//文件操作
	void save(string name);
	void read(string name);
	//运算符重载
public:
	friend istream& operator>>(istream& in, template_class<T>& obj);
	friend ostream& operator<<(ostream& out, template_class<T>& obj);
};

template<typename T>
inline template_class<T>::template_class()
{
	//指针全部赋空
	this->head = NULL;
	this->next = NULL;
	this->pior = NULL;
}

template<typename T>
inline template_class<T>::~template_class()
{
	//如果头节点为空
	if (head == NULL)
	{
		return;
	}

	template_class<T>* pcurrent = head;
	template_class<T>* curr = NULL;

	while (pcurrent->next != NULL)
	{
		curr = pcurrent;
		pcurrent = pcurrent->next;
		delete curr;
	}
	//销毁最后的节点
	delete pcurrent;
	pcurrent = NULL;
	curr = NULL;

}

template<typename T>
inline void template_class<T>::init_list(T data)
{
	template_class<T>* pcurrent = new template_class<T>;
	pcurrent->data = data;
	if (head == NULL)//如果头指针为空
	{
		head = pcurrent;//将输入的值赋给头指针
	}
	else
	{
		template_class<T>* curr = head;//curr从头节点出发，遍历到最后一个节点
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		//将最后一个节点的后继指针指向pcurrent
		curr->next = pcurrent;
		//pcurrent的前驱指针指向curr
		pcurrent->pior = curr;
		//pcurent的后继指针赋值为空
		pcurrent->next = NULL;
	}
}

//template<typename T>
//inline void template_class<T>::delet_list(T data)
//{
//	if (head == NULL)
//	{
//		cout << "没有可以删除的数据" << endl;
//		return;
//	}
//
//	template_class<T>* pcurrent = head;
//	template_class<T>* curr = NULL;
//	do
//	{
//		if (head->data == data || head->next == NULL)
//		{
//			delete head;
//			head = NULL;
//			cout << "删除完成";
//			return;
//		}
//		else if (head->data == data || head->next != NULL)
//		{
//			head = head->next;
//			delete pcurrent;
//			pcurrent = NULL;
//			cout << "删除完成";
//			return;
//		}
//		else if (head->data != data || head->next != NULL)
//		{
//			while (pcurrent->data != data)
//			{
//				curr = pcurrent;
//				pcurrent = pcurrent->next;
//			}
//			if (pcurrent->data == data || pcurrent->next != NULL)
//			{
//				pcurrent->next->pior = curr;
//				curr->next = pcurrent->next;
//				cout << "删除完成";
//				return;
//			}
//			else if (pcurrent->data == data || pcurrent->next == NULL)
//			{
//				curr->next = NULL;
//				delete pcurrent;
//				pcurrent = NULL;
//			}
//			else if (pcurrent->next == NULL || pcurrent->data != data)
//			{
//				cout << "你所描述的数据不存在" << endl;
//				return;
//			}
//
//		}
//		break;
//	} while (1);
//		cout << "没有要删除的数据" << endl;
//		return;
//}

template<typename T>
inline void template_class<T>::delet_list(T data)
{
	if (head == NULL)
	{
		cout << "链表为空，无法删除！" << endl;
		return;
	}

	//	分别定义ptr，ptr1指针指向head,nupptr(空指针)
	template_class<T>* pcurrent = head;
	template_class<T>* curr = NULL;

	do
	{

		if (pcurrent->data == data)
		{
			//	如果删除头节点
			if (pcurrent == head)
			{
				//	如果只有一个节点
				if (head->next == NULL)
				{
					// 链表只有一个节点
					delete head;
					head = NULL;
				}
				else
				{
					// 链表有多个节点
					template_class<T>* last = head;
					while (last->next != NULL)
					{
						last = last->next;	//	更新尾部指针
					}
					head = head->next; // 更新头部指针
					last->next = NULL; // 更新最后一个节点的 next 指针
					delete pcurrent;
				}
				cout << "删除成功！" << endl;
				system("pause");
				return;
			}
			else
			{
				pcurrent->next->pior = curr;
				curr->next = pcurrent->next;

				delete pcurrent;
				cout << "删除成功！" << endl;
				system("pause");
				return;
			}
		}

		curr = pcurrent;			//	更新其前驱指针
		pcurrent = pcurrent->next;	//	ptr指针后移

	} while (pcurrent->next != NULL);

	cout << "未找到要删除的节点！" << endl;
	this->print_list();

}

template<typename T>
inline void template_class<T>::Change_list(T data)
{
	if (head == NULL)
		return;
	else
	{
		template_class<T>* pcurrent = head;
		do
		{
			if (pcurrent->data == data)
				break;
			else
				pcurrent = pcurrent->next;
		} while (pcurrent->next != NULL);
		T data1;

		cout << "请输入你修改后的数据" << endl;
		cin >> data1;
		if (!this->Check_list(data1))//使用check函数查重
		{
			pcurrent->data = data1;
			cout << "修改完成" << endl;
		}
		else
		{
			cout << "请勿重复" << endl;
			return;
		}
	}
}

template<typename T>
inline void template_class<T>::search_list(T data)
{
	if (head == NULL)
	{
		cout << "没有数据可以查询" << endl;
		return;
	}
	else
	{
		template_class<T>* pcurrent = head;
		while (pcurrent->next != NULL)
		{
			if (pcurrent->data == data)
			{
				break;
			}
			pcurrent = pcurrent->next;
			if (pcurrent->next == NULL && pcurrent->data != data)
			{
				cout << "没有你要找的数据" << endl;
				return;
			}
		}
		cout << pcurrent->data << endl;
	}
}

template<typename T>
inline void template_class<T>::print_list()
{
	if (head == NULL)
	{
		cout << "没有可以打印的数据" << endl;
	}

	else
	{
		template_class<T>* pcurrent = head;
		while (pcurrent->next != NULL)
		{

			cout << pcurrent->data << endl;
			pcurrent = pcurrent->next;
		}
		cout << pcurrent->data << endl;
	}
}

template<typename T>
inline int template_class<T>::Check_list(T data)
{
	template_class<T>* pcurrent = head;
	while (pcurrent != NULL)
	{
		if (pcurrent->data == data)
			return 1;
		pcurrent = pcurrent->next;
	}
	return 0;
}

template<typename T>
inline void template_class<T>::Sort_list()
{
	template_class<T>* current = head;
	template_class<T>* nextNode = NULL;
	T temp;

	if (head == nullptr) {
		cout << "没有数据可以排序" << endl;
		return;
	}

	while (current->next != NULL) {
		nextNode = current->next;

		while (nextNode != NULL) {
			if (current->data < nextNode->data) {
				temp = current->data;
				current->data = nextNode->data;
				nextNode->data = temp;
			}
			nextNode = nextNode->next;
		}
		current = current->next;
	}
	this->print_list();
}

template<typename T>
inline void template_class<T>::save(string name)
{
	template_class<T>* pcurrent = head;
	ofstream save_file(name);
	do
	{
		save_file << pcurrent->data << endl;
		pcurrent = pcurrent->next;
	} while (pcurrent != NULL);

	save_file.close();
}


template<typename T>
inline void template_class<T>::read(string name)
{
	ifstream read_file(name);
	if (!read_file.is_open())
	{
		return;
	}

	T tempData; // 创建临时变量存储数据
	while (read_file >> tempData) // 只要能读到数据就会返回bool类型的true
	{
		this->init_list(tempData); // 调用函数将数据添加到链表中
	}
	read_file.close();
}

//void test()
//{
//	template_class<int> L;
//	L.init_list(1);
//	L.init_list(2);
//	L.init_list(3);
//	L.init_list(4);
//	L.init_list(5);
//	L.print_list();
//	L.delet_list(2);
//	L.print_list();
//	L.Change_list(1);
//	L.print_list();
//	L.search_list(5);
//
//}
//
//int main()
//{
//	test();
//}
