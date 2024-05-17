
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
	template_class<T>* head;//ͷ�ڵ�
	template_class<T>* next;//���ָ��
	template_class<T>* pior;//ǰ��ָ��
	template_class();//���캯��
	~template_class();//��������
public:
	void init_list(T data);//��ӽڵ�
	void delet_list(T data);//ɾ���ڵ�
	void Change_list(T data);//�ı�ڵ�����
	void search_list(T data);//�����ڵ�
	void print_list();//��ӡ��������
	int Check_list(T data);//�����Ԫ���Ƿ��Ѿ�����
	void Sort_list();//����

	//�ļ�����
	void save(string name);
	void read(string name);
	//���������
public:
	friend istream& operator>>(istream& in, template_class<T>& obj);
	friend ostream& operator<<(ostream& out, template_class<T>& obj);
};

template<typename T>
inline template_class<T>::template_class()
{
	//ָ��ȫ������
	this->head = NULL;
	this->next = NULL;
	this->pior = NULL;
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

template<typename T>
inline void template_class<T>::init_list(T data)
{
	template_class<T>* pcurrent = new template_class<T>;
	pcurrent->data = data;
	if (head == NULL)//���ͷָ��Ϊ��
	{
		head = pcurrent;//�������ֵ����ͷָ��
	}
	else
	{
		template_class<T>* curr = head;//curr��ͷ�ڵ���������������һ���ڵ�
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		//�����һ���ڵ�ĺ��ָ��ָ��pcurrent
		curr->next = pcurrent;
		//pcurrent��ǰ��ָ��ָ��curr
		pcurrent->pior = curr;
		//pcurent�ĺ��ָ�븳ֵΪ��
		pcurrent->next = NULL;
	}
}

//template<typename T>
//inline void template_class<T>::delet_list(T data)
//{
//	if (head == NULL)
//	{
//		cout << "û�п���ɾ��������" << endl;
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
//			cout << "ɾ�����";
//			return;
//		}
//		else if (head->data == data || head->next != NULL)
//		{
//			head = head->next;
//			delete pcurrent;
//			pcurrent = NULL;
//			cout << "ɾ�����";
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
//				cout << "ɾ�����";
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
//				cout << "�������������ݲ�����" << endl;
//				return;
//			}
//
//		}
//		break;
//	} while (1);
//		cout << "û��Ҫɾ��������" << endl;
//		return;
//}

template<typename T>
inline void template_class<T>::delet_list(T data)
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
					template_class<T>* last = head;
					while (last->next != NULL)
					{
						last = last->next;	//	����β��ָ��
					}
					head = head->next; // ����ͷ��ָ��
					last->next = NULL; // �������һ���ڵ�� next ָ��
					delete pcurrent;
				}
				cout << "ɾ���ɹ���" << endl;
				system("pause");
				return;
			}
			else
			{
				pcurrent->next->pior = curr;
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

		cout << "���������޸ĺ������" << endl;
		cin >> data1;
		if (!this->Check_list(data1))//ʹ��check��������
		{
			pcurrent->data = data1;
			cout << "�޸����" << endl;
		}
		else
		{
			cout << "�����ظ�" << endl;
			return;
		}
	}
}

template<typename T>
inline void template_class<T>::search_list(T data)
{
	if (head == NULL)
	{
		cout << "û�����ݿ��Բ�ѯ" << endl;
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
				cout << "û����Ҫ�ҵ�����" << endl;
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
		cout << "û�п��Դ�ӡ������" << endl;
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
		cout << "û�����ݿ�������" << endl;
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

	T tempData; // ������ʱ�����洢����
	while (read_file >> tempData) // ֻҪ�ܶ������ݾͻ᷵��bool���͵�true
	{
		this->init_list(tempData); // ���ú�����������ӵ�������
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
