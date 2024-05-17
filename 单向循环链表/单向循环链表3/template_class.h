# include <iostream>
# include <string>
# include <fstream>
# include <Windows.h>
using namespace std;
template <typename T>
class template_list
{
private:
	T data;					//数据
public:
	template_list();		// 构造函数
	~template_list();		//	析构函数
	template_list* head;	//	头指针
	template_list* next;	//	指向下一个指针域
public:
	// 创建链表
	int creat_list(T data);
	//遍历链表
	void show_list();
	//删除链表元素
	void delete_element(T data1);
	//修改链表元素
	void modify_element(T data1);
	//查找链表元素
	void find_element(T data1);
	//排序链表元素
	void sort_element();
	//清空链表元素
	void clear_list();
	//存储信息
	void save_list(string name);
	//读取信息
	void read_list(string name);
	//测试是否是循环链表
	void test_list();
	//查重
	int check_element(T data);
	//节点排序
	void sort_node();
	//交换两个节点
	void swap_node(template_list<T>* node1, template_list<T>* node2);
	//	对输出进行重载  以便于能够 cout << 对象
	friend ostream& operator<<(ostream& os, template_list<T>& obj)
	{
		template_list<T>* ptr = obj.head;		//	定义ptr指针指向head
		do
		{
			os << ptr->data << endl;			//	输出每一个节点中的自定义数据data
			ptr = ptr->next;					//	遍历
		} while (ptr != obj.head);
		return os;								//	返回 os cout进行输出
	}
	//	对输入进行重载	以便于能够 cin >> 对象
	friend istream& operator>>(istream& is, template_list<T>& obj)
	{
		T data;					//	自定义数据
		is >> data;				//	对数据信息进行输入
		obj.creat_list(data);	//	调用自己写的一个添加函数	将数据添加到链表中
		return is;				//	返回is   cin输入
	}
};


template<typename T>
template_list<T>::template_list()
{
	this->head = NULL;
	this->next = NULL;
}

template<typename T>
template_list<T>::~template_list()
{
	/*template_list<T>* ptr = head;
	while (ptr->next != head)
	{
		template_list<T>* ptr1 = ptr;
		ptr = ptr->next;
		delete ptr1;
		head->next = ptr;
	}
	cout << "1111" << endl;
	delete ptr;
	delete head;*/

	if (head == nullptr)
	{
		return;
	}

	template_list<T>* ptr = head;
	template_list<T>* ptr1 = nullptr;

	do
	{
		ptr1 = ptr->next;
		delete ptr;
		//cout << "我是析构函数,我被调用了" << endl;
		ptr = ptr1;
	} while (ptr != head);

	head = nullptr;
}

template<typename T>
int template_list<T>::creat_list(T data)
{
	//	对数据进行查重	若重复返回 1
	if (check_element(data) == 1)
	{
		cout << "数据重复!" << endl;
		return 1;
	}
	//	定义ptr 并开辟一个空间
	template_list<T>* ptr = new template_list<T>;
	ptr->data = data;	//	将输入的数据赋值给节点

	//	判断头指针是否为空	若为空，将data的值赋给head	同时因为是一个节点，因此head的下一个仍是head
	if (head == nullptr)
	{
		head = ptr;				// 将 data 赋值给 head节点
		ptr->next = head;		// head的指针域扔指向head	构成循环
	}
	//	多个节点
	else
	{
		//	定义节点 ptr1 指向 head头节点
		template_list<T>* ptr1 = head;
		//	循环遍历链表，找到尾部
		while (ptr1->next != head)
		{
			ptr1 = ptr1->next;
		}
		ptr1->next = ptr;	//	更新尾节点
		ptr->next = head;	//	形成闭环
	}

	return 0;	//		返回 0
}

template<typename T>
void template_list<T>::show_list()
{
	//错误的  因为不能等于头节点  当等于头结点的时候结束循环
	//template_list<T>* ptr = head;
	//while (ptr != head)
	//{
	//	cout << ptr->data << " ";
	//	ptr = ptr->next;
	//}

	//	判断链表是否为空
	if (head == nullptr)
	{
		cout << "链表为空！" << endl;
		return;
	}

	//	定义一个ptr指针指向head
	template_list<T>* ptr = head->next;

	do
	{
		cout << ptr->data << endl;	//	输出节点内的内容
		ptr = ptr->next;		//	每次打印完毕都后移一个节点
	} while (ptr != head->next);		//	ptr ！= head

	////检验是否形成环
	//template_list<T>* p = head;
	//template_list<T>* q = head;
	//while (q != nullptr && q->next != nullptr)
	//{
	//	p = p->next;
	//	q = q->next->next;
	//	if (p == q)
	//	{
	//		cout << "成功了，存在环";
	//		break;
	//	}
	//}
	//if (q == nullptr || q->next == nullptr)
	//{
	//	cout << "不存在环";
	//}
	//cout << endl;
	/*template_list<T>* ptr = head;
	for (int i = 0; i < 10; i++)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
		cout << endl;
	}*/
}

template<typename T>
void template_list<T>::delete_element(T data1)
{
	//if (head == nullptr)
	//{
	//	cout << "链表为空，无法删除！" << endl;
	//	return;
	//}
	//template_list<T>* ptr1 = nullptr;
	//template_list<T>* ptr = head;
	//do
	//{
	//	if (ptr->data == data1)
	//	{
	//		if (ptr == head)
	//		{
	//			// 如果要删除的节点是头部节点
	//			if (head->next == head)
	//			{
	//				// 链表只有一个节点
	//				delete head;
	//				head = nullptr;
	//			}
	//			else
	//			{
	//				// 链表有多个节点
	//				template_list<T>* last = head;
	//				while (last->next != head)
	//				{
	//					last = last->next;
	//				}
	//				head = head->next; // 更新头部指针
	//				last->next = head; // 更新最后一个节点的 next 指针
	//				delete ptr;
	//			}
	//		}
	//		else
	//		{	
	//			ptr1->next = ptr->next; // 更新前一个节点的 next 指针
	//			delete ptr;
	//			cout << "删除成功！" << endl;
	//			system("pause");
	//			return;
	//		}
	//		ptr1 = ptr;
	//		ptr = ptr->next;
	//	}
	//	
	//} while (ptr != head);
	//cout << "删除失败！" << endl;
	//system("pause");

	//	判断链表是否为空
	if (head == nullptr)
	{
		cout << "链表为空，无法删除！" << endl;
		return;
	}

	//	分别定义ptr，ptr1指针指向head,nupptr(空指针)
	template_list<T>* ptr = head;
	template_list<T>* ptr1 = nullptr;

	do
	{
		//	当节点内的数据等于要删除的数据时，进行if语句内部
		if (ptr->data == data1)
		{
			//	如果删除头节点
			if (ptr == head)
			{
				//	如果只有一个节点
				if (head->next == head)
				{
					// 链表只有一个节点
					delete head;
					head = nullptr;
				}
				else
				{
					// 链表有多个节点
					template_list<T>* last = head;
					while (last->next != head)
					{
						last = last->next;	//	更新尾部指针
					}
					head = head->next; // 更新头部指针
					last->next = head; // 更新最后一个节点的 next 指针
					delete ptr;
				}
				cout << "删除成功！" << endl;
				system("pause");
				return;
			}
			else
			{
				ptr1->next = ptr->next;
				delete ptr;
				cout << "删除成功！" << endl;
				system("pause");
				return;
			}
		}

		ptr1 = ptr;			//	更新其前驱指针
		ptr = ptr->next;	//	ptr指针后移

	} while (ptr != head);

	cout << "未找到要删除的节点！" << endl;
	system("pause");
}

template<typename T>
void template_list<T>::modify_element(T data1)
{
	//	定义ptr指针指向head
	template_list<T>* ptr = head;
	do
	{
		//	当节点内的内容等于要修改的序号时，进入if语句
		if (data1 == ptr->data)
		{
			T data2;									//	定一个新的 T 型变量data2
			cout << "请输入更改后的数据：" << endl;
			cin >> data2;								//	输入修改后的值
			ptr->data = data2;							//	将data2 的值赋给节点
			cout << "修改成功！" << endl;
			system("pause");
			return;
		}
		ptr = ptr->next;								//	如果未找到	节点后移
	} while (ptr != head);
	cout << "修改失败！" << endl;
	system("pause");
	return;
}

template<typename T>
void template_list<T>::find_element(T data1)
{
	//	定义一个ptr指针指向head头指针
	template_list<T>* ptr = head;
	do
	{
		//	当节点内的数据等于查找的数据时，进入if 语句
		if (ptr->data == data1)
		{
			cout << ptr->data << endl;		//	输出结点的内容
			system("pause");
			return;
		}
		ptr = ptr->next;					//	未找到，节点后移
	} while (ptr != head);
	cout << "查找失败！" << endl;
	system("pause");
}

template<typename T>
void template_list<T>::sort_element()
{
	//	当节点为空，或者一个结点的时候	退出
	if (head == nullptr || head->next == head)
	{
		return;
	}
	template_list<T>* ptr = head->next;
	//	循环遍历
	while (ptr != head)
	{
		template_list<T>* ptr1 = head;
		while (ptr1 != ptr)
		{
			//	如果符合条件，进行交换
			if (ptr->data < ptr1->data)
			{
				T data1 = ptr->data;
				ptr->data = ptr1->data;
				ptr1->data = data1;

			}
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
}

template<typename T>
void template_list<T>::clear_list()
{
	if (head == nullptr)
	{
		return;
	}

	template_list<T>* ptr = head;

	//	对链表节点依次进行遍历删除.清空链表
	do
	{
		template_list<T>* ptr1 = ptr;
		ptr = ptr->next;
		delete ptr1;
	} while (ptr != head);

	head = nullptr;
}

template<typename T>
void template_list<T>::save_list(string name)
{
	template_list<T>* ptr = head;
	ofstream save_file(name + "数据.txt");
	do
	{
		save_file << ptr->data << endl;
		ptr = ptr->next;
	} while (ptr != head);

	//cout << "存取成功！" << endl;
	save_file.close();
}

template<typename T>
void template_list<T>::read_list(string name)
{
	ifstream read_file(name + "数据.txt");
	if (!read_file.is_open())
	{
		return;
	}

	T tempData; // 创建临时变量存储数据
	while (read_file >> tempData) // 使用重载的>>运算符读取数据
	{
		this->creat_list(tempData); // 调用函数将数据添加到链表中
	}
	read_file.close();
}

template<typename T>
void template_list<T>::test_list()
{
	creat_list(1);
	creat_list(2);
	creat_list(3);
	creat_list(4);
	creat_list(5);
	template_list<T>* ptr = head;
	for (int i = 0; i < 10; i++)
	{
		cout << ptr->data << endl;
		ptr = ptr->next;
		if ((i + 1) % 5 == 0)
			cout << endl;
	}

	clear_list();
}

template<typename T>
int template_list<T>::check_element(T data)
{
	template_list<T>* ptr = head;

	if (ptr == nullptr)
	{
		return -1;
	}

	do
	{
		if (data == ptr->data)
		{
			return 1;
		}
		ptr = ptr->next;
	} while (ptr != head);

	return -1;
}