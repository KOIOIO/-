#pragma once
#include"iostream"
using namespace std;
template <typename T>
class template_class
{
private:
	T data;
public:
	template_class<T>* head;
	template_class<T>* next;
public:
	template_class();
	~template_class();

public:
	//文件操作
	void save();
	void read();
	friend istream& operator>>(istream& in, template_class<T>& obj);
	friend ostream& operator<<(ostream& out, template_class<T>& obj);
public:
	void insert_list(T data);
	void delete_list(T data);
	void change_list(T data);
	void search_list(T data);
	void print_list();
	int check_list(T data);
};

template<typename T>
inline template_class<T>::template_class()
{
	this->head = NULL;
	this->next = NULL;
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

//template<typename T>
//inline void template_class<T>::save(string name)
//{
//	template_class<T>* pcurrent = head;
//	ofstream save_file(name);
//	do
//	{
//		save_file << pcurrent->data << endl;
//		pcurrent = pcurrent->next;
//	} while (pcurrent != NULL);
//
//	save_file.close();
//}
//
//template<typename T>
//inline void template_class<T>::read(string name)
//{
//	ifstream read_file(name);
//	if (!read_file.is_open())
//	{
//		return;
//	}
//
//	T tempData; // 创建临时变量存储数据
//	while (read_file >> tempData) // 只要能读到数据就会返回bool类型的true
//	{
//		this->insert_list(tempData); // 调用函数将数据添加到链表中
//	}
//	read_file.close();
//}
#include <fstream>

template <typename T>
void template_class<T>::save()
{
	ofstream file("data.txt");
	if (file.is_open())
	{
		template_class<T>* current = head;
		while (current != nullptr)
		{
			file << current->data << endl;
			current = current->next;
		}
		file.close();
		cout << "数据已成功写入文件" << endl;
	}
	else
	{
		cout << "无法打开文件" << endl;
	}
}

template <typename T>
void template_class<T>::read()
{
	ifstream file("data.txt");
	if (file.is_open())
	{
		T value;
		while (file >> value)
		{
			insert_list(value);
		}
		file.close();
		cout << "数据已成功从文件中读取" << endl;
	}
	else
	{
		cout << "无法打开文件" << endl;
	}
}


template<typename T>
inline void template_class<T>::insert_list(T data)
{
	template_class<T>* curr = new template_class<T>;
	curr->data = data;
	if (head == NULL)
	{
		head = curr;
		return;
	}
	
	template_class<T>* pcurrent = head;
	while (pcurrent->next != NULL)
	{
		pcurrent = pcurrent->next;
	}
	pcurrent->next = curr;
	curr->next = NULL;
}

template<typename T>
inline void template_class<T>::delete_list(T data)
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
					
					head = head->next;
					delete pcurrent;
					pcurrent = NULL;
				}
				cout << "删除成功！" << endl;
				system("pause");
				return;
			}
			else
			{
				
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
inline void template_class<T>::change_list(T data)
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		template_class<T>* pcurrent = head;
		while (pcurrent->data != data)
		{
			pcurrent = pcurrent->next;
		}
		T dat;
		cout << "请输入新的数据" << endl;
		cin >> dat;
		pcurrent->data = dat;
		cout << "更改成功" << endl;
	}
}

template<typename T>
inline void template_class<T>::search_list(T data)
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		template_class<T>* pcurrent = head;
		while (pcurrent->data != data && pcurrent->next != NULL)
		{
			pcurrent = pcurrent->next;
		}
		if (pcurrent->next == NULL && pcurrent->data == data)
		{
			cout << pcurrent->data << endl;
		}
		if (pcurrent->next != NULL && pcurrent->data == data)
		{
			cout << pcurrent->data << endl;
		}
		if (pcurrent->next == NULL && pcurrent->data != data)
		{
			cout << "没有这个数据" << endl;
		}
	}
}

template<typename T>
inline void template_class<T>::print_list()
{
	if (head == NULL)
	{
		cout << "没有要打印的数据" << endl;
		return;
	}
	template_class<T>* pcurrent = head;
	while (pcurrent->next!= NULL)
	{
		cout << pcurrent->data << endl;
		pcurrent = pcurrent->next;
	}
	cout << pcurrent->data << endl;

}

template<typename T>
inline int template_class<T>::check_list(T data)
{
	template_class<T>* pcurrent = head;
	while (pcurrent != NULL)
	{
		if (pcurrent->data == data)
		{
			cout << "不得重复" << endl;
			return 1;
		}
		pcurrent = pcurrent->next;
	}

}

//void test()
//{
//	template_class<int>L;
//	L.insert_list(1);
//	L.insert_list(2);
//	L.insert_list(3);
//	L.insert_list(4);
//	L.insert_list(5);
//	L.print_list();
//	L.delete_list(2);
//	L.print_list();
//	L.search_list(3);
//	L.change_list(5);
//	L.print_list();
//}
//
//int main()
//{
//	test();
//}