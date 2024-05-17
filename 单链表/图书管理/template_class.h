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
	//�ļ�����
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
	//���ͷ�ڵ�Ϊ��
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
	//�������Ľڵ�
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
//	T tempData; // ������ʱ�����洢����
//	while (read_file >> tempData) // ֻҪ�ܶ������ݾͻ᷵��bool���͵�true
//	{
//		this->insert_list(tempData); // ���ú�����������ӵ�������
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
		cout << "�����ѳɹ�д���ļ�" << endl;
	}
	else
	{
		cout << "�޷����ļ�" << endl;
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
		cout << "�����ѳɹ����ļ��ж�ȡ" << endl;
	}
	else
	{
		cout << "�޷����ļ�" << endl;
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
		cout << "����Ϊ�գ��޷�ɾ����" << endl;
		return;
	}

	//	�ֱ���ptr��ptr1ָ��ָ��head,nupptr(��ָ��)
	template_class<T>* pcurrent = head;
	template_class<T>* curr = NULL;

	do
	{

		if (pcurrent->data == data)
		{
			//	���ɾ��ͷ�ڵ�
			if (pcurrent == head)
			{
				//	���ֻ��һ���ڵ�
				if (head->next == NULL)
				{
					// ����ֻ��һ���ڵ�
					delete head;
					head = NULL;
				}
				else
				{
					// �����ж���ڵ�
					
					head = head->next;
					delete pcurrent;
					pcurrent = NULL;
				}
				cout << "ɾ���ɹ���" << endl;
				system("pause");
				return;
			}
			else
			{
				
				curr->next = pcurrent->next;

				delete pcurrent;
				cout << "ɾ���ɹ���" << endl;
				system("pause");
				return;
			}
		}

		curr = pcurrent;			//	������ǰ��ָ��
		pcurrent = pcurrent->next;	//	ptrָ�����

	} while (pcurrent->next != NULL);

	cout << "δ�ҵ�Ҫɾ���Ľڵ㣡" << endl;
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
		cout << "�������µ�����" << endl;
		cin >> dat;
		pcurrent->data = dat;
		cout << "���ĳɹ�" << endl;
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
			cout << "û���������" << endl;
		}
	}
}

template<typename T>
inline void template_class<T>::print_list()
{
	if (head == NULL)
	{
		cout << "û��Ҫ��ӡ������" << endl;
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
			cout << "�����ظ�" << endl;
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