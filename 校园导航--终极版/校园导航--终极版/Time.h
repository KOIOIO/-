#include"Point.h"
//class Graph;
/*********************************************************************************************************时间类*************************************************************************************/
class Time
{
public:
	Time() {};//构造函数 
	~Time() {};//析构函数  
	virtual void showTime(int x) {
		cout << "您出行的时间为" << endl;

	};
	//输出所需时间  
};


class bike :public Time
{
public:
	void showTime(int x)
	{
		cout << "骑行预计用时：" << x / speed2 << "秒" << endl;
	}
};
class car :public Time
{
public:
	void showTime(int x)
	{
		cout << "小汽车预计用时：" << x / speed3 << "秒" << endl;
	}
};
class walk :public Time
{
public:
	virtual void showTime(int x)
	{

		cout << "步行预计用时：";
		cout << x / speed1 << "秒" << endl;
	}
};

