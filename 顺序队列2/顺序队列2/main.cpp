#include "QUEUE.h"
int main()
{
	Queue<int> queue;
	cout << "*********************" << endl;
	cout << "新初始化的队列的长度为：" << queue.getSize() << endl;
	cout << "队是否为空:" << boolalpha << queue.isEmpty() << endl;
	cout << "*********************" << endl;
	for (int i = 0; i < 9; ++i)
		queue.enQueue(i);
	cout << "插入元素后队列的长度：" << queue.getSize() << endl;
	cout << "队是否为空:" << boolalpha << queue.isEmpty() << endl;
	cout << "整个队列元素:" << endl;
	queue.display();
	cout << endl;
	cout << "*********************" << endl;
	queue.deQueue();
	cout << "删除元素后的的队列的长度：" << queue.getSize() << endl;
	cout << "队是否为空:" << boolalpha << queue.isEmpty() << endl;
	cout << "整个队列元素:" << endl;
	queue.display();
	cout << endl;
	system("pause");
	return 0;
}
