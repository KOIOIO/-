#include"Point.h"
//class Graph;
/*********************************************************************************************************ʱ����*************************************************************************************/
class Time
{
public:
	Time() {};//���캯�� 
	~Time() {};//��������  
	virtual void showTime(int x) {
		cout << "�����е�ʱ��Ϊ" << endl;

	};
	//�������ʱ��  
};


class bike :public Time
{
public:
	void showTime(int x)
	{
		cout << "����Ԥ����ʱ��" << x / speed2 << "��" << endl;
	}
};
class car :public Time
{
public:
	void showTime(int x)
	{
		cout << "С����Ԥ����ʱ��" << x / speed3 << "��" << endl;
	}
};
class walk :public Time
{
public:
	virtual void showTime(int x)
	{

		cout << "����Ԥ����ʱ��";
		cout << x / speed1 << "��" << endl;
	}
};

