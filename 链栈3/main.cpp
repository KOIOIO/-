#include"template_class.h"

template_class<int>L;
void main()
{
	while (1)
	{
		int data;
		cout << "��������Ҫת��������" << endl;
		cin >> data;
		int answer;
		int h=0;
		
		while (h!=0)
		{
			answer = data % 2;
			h = data / 2;
			L.push(answer);
		}
		L.print();
	}
}