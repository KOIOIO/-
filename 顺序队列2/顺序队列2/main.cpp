#include "QUEUE.h"
int main()
{
	Queue<int> queue;
	cout << "*********************" << endl;
	cout << "�³�ʼ���Ķ��еĳ���Ϊ��" << queue.getSize() << endl;
	cout << "���Ƿ�Ϊ��:" << boolalpha << queue.isEmpty() << endl;
	cout << "*********************" << endl;
	for (int i = 0; i < 9; ++i)
		queue.enQueue(i);
	cout << "����Ԫ�غ���еĳ��ȣ�" << queue.getSize() << endl;
	cout << "���Ƿ�Ϊ��:" << boolalpha << queue.isEmpty() << endl;
	cout << "��������Ԫ��:" << endl;
	queue.display();
	cout << endl;
	cout << "*********************" << endl;
	queue.deQueue();
	cout << "ɾ��Ԫ�غ�ĵĶ��еĳ��ȣ�" << queue.getSize() << endl;
	cout << "���Ƿ�Ϊ��:" << boolalpha << queue.isEmpty() << endl;
	cout << "��������Ԫ��:" << endl;
	queue.display();
	cout << endl;
	system("pause");
	return 0;
}
