# include <iostream>
# include <string>
# include <fstream>
# include <Windows.h>
using namespace std;
template <typename T>
class template_list
{
private:
	T data;					//����
public:
	template_list();		// ���캯��
	~template_list();		//	��������
	template_list* head;	//	ͷָ��
	template_list* next;	//	ָ����һ��ָ����
public:
	// ��������
	int creat_list(T data);
	//��������
	void show_list();
	//ɾ������Ԫ��
	void delete_element(T data1);
	//�޸�����Ԫ��
	void modify_element(T data1);
	//��������Ԫ��
	void find_element(T data1);
	//��������Ԫ��
	void sort_element();
	//�������Ԫ��
	void clear_list();
	//�洢��Ϣ
	void save_list(string name);
	//��ȡ��Ϣ
	void read_list(string name);
	//�����Ƿ���ѭ������
	void test_list();
	//����
	int check_element(T data);
	//�ڵ�����
	void sort_node();
	//���������ڵ�
	void swap_node(template_list<T>* node1, template_list<T>* node2);
	//	�������������  �Ա����ܹ� cout << ����
	friend ostream& operator<<(ostream& os, template_list<T>& obj)
	{
		template_list<T>* ptr = obj.head;		//	����ptrָ��ָ��head
		do
		{
			os << ptr->data << endl;			//	���ÿһ���ڵ��е��Զ�������data
			ptr = ptr->next;					//	����
		} while (ptr != obj.head);
		return os;								//	���� os cout�������
	}
	//	�������������	�Ա����ܹ� cin >> ����
	friend istream& operator>>(istream& is, template_list<T>& obj)
	{
		T data;					//	�Զ�������
		is >> data;				//	��������Ϣ��������
		obj.creat_list(data);	//	�����Լ�д��һ����Ӻ���	��������ӵ�������
		return is;				//	����is   cin����
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
		//cout << "������������,�ұ�������" << endl;
		ptr = ptr1;
	} while (ptr != head);

	head = nullptr;
}

template<typename T>
int template_list<T>::creat_list(T data)
{
	//	�����ݽ��в���	���ظ����� 1
	if (check_element(data) == 1)
	{
		cout << "�����ظ�!" << endl;
		return 1;
	}
	//	����ptr ������һ���ռ�
	template_list<T>* ptr = new template_list<T>;
	ptr->data = data;	//	����������ݸ�ֵ���ڵ�

	//	�ж�ͷָ���Ƿ�Ϊ��	��Ϊ�գ���data��ֵ����head	ͬʱ��Ϊ��һ���ڵ㣬���head����һ������head
	if (head == nullptr)
	{
		head = ptr;				// �� data ��ֵ�� head�ڵ�
		ptr->next = head;		// head��ָ������ָ��head	����ѭ��
	}
	//	����ڵ�
	else
	{
		//	����ڵ� ptr1 ָ�� headͷ�ڵ�
		template_list<T>* ptr1 = head;
		//	ѭ�����������ҵ�β��
		while (ptr1->next != head)
		{
			ptr1 = ptr1->next;
		}
		ptr1->next = ptr;	//	����β�ڵ�
		ptr->next = head;	//	�γɱջ�
	}

	return 0;	//		���� 0
}

template<typename T>
void template_list<T>::show_list()
{
	//�����  ��Ϊ���ܵ���ͷ�ڵ�  ������ͷ����ʱ�����ѭ��
	//template_list<T>* ptr = head;
	//while (ptr != head)
	//{
	//	cout << ptr->data << " ";
	//	ptr = ptr->next;
	//}

	//	�ж������Ƿ�Ϊ��
	if (head == nullptr)
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}

	//	����һ��ptrָ��ָ��head
	template_list<T>* ptr = head->next;

	do
	{
		cout << ptr->data << endl;	//	����ڵ��ڵ�����
		ptr = ptr->next;		//	ÿ�δ�ӡ��϶�����һ���ڵ�
	} while (ptr != head->next);		//	ptr ��= head

	////�����Ƿ��γɻ�
	//template_list<T>* p = head;
	//template_list<T>* q = head;
	//while (q != nullptr && q->next != nullptr)
	//{
	//	p = p->next;
	//	q = q->next->next;
	//	if (p == q)
	//	{
	//		cout << "�ɹ��ˣ����ڻ�";
	//		break;
	//	}
	//}
	//if (q == nullptr || q->next == nullptr)
	//{
	//	cout << "�����ڻ�";
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
	//	cout << "����Ϊ�գ��޷�ɾ����" << endl;
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
	//			// ���Ҫɾ���Ľڵ���ͷ���ڵ�
	//			if (head->next == head)
	//			{
	//				// ����ֻ��һ���ڵ�
	//				delete head;
	//				head = nullptr;
	//			}
	//			else
	//			{
	//				// �����ж���ڵ�
	//				template_list<T>* last = head;
	//				while (last->next != head)
	//				{
	//					last = last->next;
	//				}
	//				head = head->next; // ����ͷ��ָ��
	//				last->next = head; // �������һ���ڵ�� next ָ��
	//				delete ptr;
	//			}
	//		}
	//		else
	//		{	
	//			ptr1->next = ptr->next; // ����ǰһ���ڵ�� next ָ��
	//			delete ptr;
	//			cout << "ɾ���ɹ���" << endl;
	//			system("pause");
	//			return;
	//		}
	//		ptr1 = ptr;
	//		ptr = ptr->next;
	//	}
	//	
	//} while (ptr != head);
	//cout << "ɾ��ʧ�ܣ�" << endl;
	//system("pause");

	//	�ж������Ƿ�Ϊ��
	if (head == nullptr)
	{
		cout << "����Ϊ�գ��޷�ɾ����" << endl;
		return;
	}

	//	�ֱ���ptr��ptr1ָ��ָ��head,nupptr(��ָ��)
	template_list<T>* ptr = head;
	template_list<T>* ptr1 = nullptr;

	do
	{
		//	���ڵ��ڵ����ݵ���Ҫɾ��������ʱ������if����ڲ�
		if (ptr->data == data1)
		{
			//	���ɾ��ͷ�ڵ�
			if (ptr == head)
			{
				//	���ֻ��һ���ڵ�
				if (head->next == head)
				{
					// ����ֻ��һ���ڵ�
					delete head;
					head = nullptr;
				}
				else
				{
					// �����ж���ڵ�
					template_list<T>* last = head;
					while (last->next != head)
					{
						last = last->next;	//	����β��ָ��
					}
					head = head->next; // ����ͷ��ָ��
					last->next = head; // �������һ���ڵ�� next ָ��
					delete ptr;
				}
				cout << "ɾ���ɹ���" << endl;
				system("pause");
				return;
			}
			else
			{
				ptr1->next = ptr->next;
				delete ptr;
				cout << "ɾ���ɹ���" << endl;
				system("pause");
				return;
			}
		}

		ptr1 = ptr;			//	������ǰ��ָ��
		ptr = ptr->next;	//	ptrָ�����

	} while (ptr != head);

	cout << "δ�ҵ�Ҫɾ���Ľڵ㣡" << endl;
	system("pause");
}

template<typename T>
void template_list<T>::modify_element(T data1)
{
	//	����ptrָ��ָ��head
	template_list<T>* ptr = head;
	do
	{
		//	���ڵ��ڵ����ݵ���Ҫ�޸ĵ����ʱ������if���
		if (data1 == ptr->data)
		{
			T data2;									//	��һ���µ� T �ͱ���data2
			cout << "��������ĺ�����ݣ�" << endl;
			cin >> data2;								//	�����޸ĺ��ֵ
			ptr->data = data2;							//	��data2 ��ֵ�����ڵ�
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			return;
		}
		ptr = ptr->next;								//	���δ�ҵ�	�ڵ����
	} while (ptr != head);
	cout << "�޸�ʧ�ܣ�" << endl;
	system("pause");
	return;
}

template<typename T>
void template_list<T>::find_element(T data1)
{
	//	����һ��ptrָ��ָ��headͷָ��
	template_list<T>* ptr = head;
	do
	{
		//	���ڵ��ڵ����ݵ��ڲ��ҵ�����ʱ������if ���
		if (ptr->data == data1)
		{
			cout << ptr->data << endl;		//	�����������
			system("pause");
			return;
		}
		ptr = ptr->next;					//	δ�ҵ����ڵ����
	} while (ptr != head);
	cout << "����ʧ�ܣ�" << endl;
	system("pause");
}

template<typename T>
void template_list<T>::sort_element()
{
	//	���ڵ�Ϊ�գ�����һ������ʱ��	�˳�
	if (head == nullptr || head->next == head)
	{
		return;
	}
	template_list<T>* ptr = head->next;
	//	ѭ������
	while (ptr != head)
	{
		template_list<T>* ptr1 = head;
		while (ptr1 != ptr)
		{
			//	����������������н���
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

	//	������ڵ����ν��б���ɾ��.�������
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
	ofstream save_file(name + "����.txt");
	do
	{
		save_file << ptr->data << endl;
		ptr = ptr->next;
	} while (ptr != head);

	//cout << "��ȡ�ɹ���" << endl;
	save_file.close();
}

template<typename T>
void template_list<T>::read_list(string name)
{
	ifstream read_file(name + "����.txt");
	if (!read_file.is_open())
	{
		return;
	}

	T tempData; // ������ʱ�����洢����
	while (read_file >> tempData) // ʹ�����ص�>>�������ȡ����
	{
		this->creat_list(tempData); // ���ú�����������ӵ�������
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