#include"iostream"
#include"string"
using namespace std;


template <typename T>
class MyStack
{
public:
	MyStack(int _stack_capacity = 8);//默认参数在声明处说明即可
	~MyStack();

	void Push(const T& _data);//入栈
	void Pop();//删除
	T& Top();//返回栈顶数据
	bool Empty();//判断栈是否为空
	int Size();//返回栈的大小
	void print();

private:
	T* stack;//栈指针
	int top;//栈顶位置
	int stack_capacity;//栈的大小
	
	void ChangeSize();//栈的扩容函数
};

//构造函数和析构函数
template <typename T>
MyStack<T>::MyStack(int _stack_capacity):stack_capacity(_stack_capacity)
{
	stack = new T[stack_capacity];//生成一个大小为stack_capacity的栈
	top = -1;
}
template <typename T>
MyStack<T>::~MyStack()
{
	delete[] stack;
}
//入栈
template <typename T>
void MyStack<T>::Push(const T& _data)
{
	if (top == stack_capacity - 1) 
	{//判断栈是否满了
		ChangeSize();//扩容
	}
	stack[++top] = _data;
}
//出栈
template <typename T>
void MyStack<T>::Pop()
{
	if (!Empty())
		top--;
	else
		exit(1);
}
//获取栈顶数据
template <typename T>
T& MyStack<T>::Top()
{
	if (!Empty())
		return stack[top];//非空就返回栈顶数据
	else
		exit(1);
}
//判空
template <typename T>
bool MyStack<T>::Empty()
{
	if (top < 0)
		return true;
	else
		return false;
}
//栈的大小
template <typename T>
int MyStack<T>::Size()
{
	return (top + 1);
}
template<typename T>
void MyStack<T>::print()
{
	while (top != 0)
	{
		cout << stack[top];
		top--;
	}
	cout << stack[top];
}
//扩容函数
template <typename T>
void  MyStack<T>::ChangeSize()
{
	cout << "栈扩容" << endl;
	int size = stack_capacity * 2;//栈容量扩大1倍

	T* tmp = new T[size];//1.申请一块原来2倍大小的空间。
	copy(stack, stack + stack_capacity, tmp);
	delete[] stack;
	stack = tmp;//
	stack_capacity = size;
}





//int main()
//{
//	while (1)
//	{
//		MyStack<int>Q;
//		MyStack<int>P;
//		cout << "请输入你要转化的数据" << endl;
//
//		int data;
//		cin >> data;
//		int data1 = data;
//
//		while (data)
//		{
//			Q.Push(data % 2);
//			data /= 2;
//		}
//		Q.print();
//		cout << endl;
//	}
//


//int main()
//{
//	while (1)
//	{
//		MyStack<int>Stack;
//		MyStack<float>Stack1;
//		cout << "请输入你要转化的程序" << endl;
//		float data;
//		cin >> data;
//		if (data > 0)
//		{
//			//整数部分
//			int data1 = data / 1;
//			while (data1)
//			{
//				Stack.Push(data1 % 2);
//				data1 /= 2;
//			}
//			Stack.print();
//			cout << ".";
//			
//
//
//		}
//	}
//

std::string DecimalToBinary(double decimal) {
	MyStack<int> stack;

	// 处理整数部分
	int integerPart = static_cast<int>(decimal);
	while (integerPart != 0) {
		stack.Push(integerPart % 2);
		integerPart /= 2;
	}

	// 加上小数点
	stack.Push(-1);

	// 处理小数部分
	double fractionPart = decimal - static_cast<int>(decimal);
	while (fractionPart > 0) {
		fractionPart *= 2;
		int bit = static_cast<int>(fractionPart);
		stack.Push(bit);
		fractionPart -= static_cast<int>(fractionPart);
	}

	// 生成二进制字符串
	string binaryStr;
	while (!stack.Empty()) {
		int value = stack.Top();
		stack.Pop();
		if (value == -1) {
			binaryStr += ".";
		}
		else {
			binaryStr += to_string(value);
		}
	}

	return binaryStr;
}

int main() {
	while (1)
	{
		double decimal;
		cout << "请输入数据" << endl;
		cin >> decimal;
		string binary = DecimalToBinary(decimal);
		cout << "十进制 " << decimal << ", 二进制 " << binary << endl;
	}
	return 0;
}