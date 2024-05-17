#include"iostream"
#include"string"
using namespace std;


template <typename T>
class MyStack
{
public:
	MyStack(int _stack_capacity = 8);//Ĭ�ϲ�����������˵������
	~MyStack();

	void Push(const T& _data);//��ջ
	void Pop();//ɾ��
	T& Top();//����ջ������
	bool Empty();//�ж�ջ�Ƿ�Ϊ��
	int Size();//����ջ�Ĵ�С
	void print();

private:
	T* stack;//ջָ��
	int top;//ջ��λ��
	int stack_capacity;//ջ�Ĵ�С
	
	void ChangeSize();//ջ�����ݺ���
};

//���캯������������
template <typename T>
MyStack<T>::MyStack(int _stack_capacity):stack_capacity(_stack_capacity)
{
	stack = new T[stack_capacity];//����һ����СΪstack_capacity��ջ
	top = -1;
}
template <typename T>
MyStack<T>::~MyStack()
{
	delete[] stack;
}
//��ջ
template <typename T>
void MyStack<T>::Push(const T& _data)
{
	if (top == stack_capacity - 1) 
	{//�ж�ջ�Ƿ�����
		ChangeSize();//����
	}
	stack[++top] = _data;
}
//��ջ
template <typename T>
void MyStack<T>::Pop()
{
	if (!Empty())
		top--;
	else
		exit(1);
}
//��ȡջ������
template <typename T>
T& MyStack<T>::Top()
{
	if (!Empty())
		return stack[top];//�ǿվͷ���ջ������
	else
		exit(1);
}
//�п�
template <typename T>
bool MyStack<T>::Empty()
{
	if (top < 0)
		return true;
	else
		return false;
}
//ջ�Ĵ�С
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
//���ݺ���
template <typename T>
void  MyStack<T>::ChangeSize()
{
	cout << "ջ����" << endl;
	int size = stack_capacity * 2;//ջ��������1��

	T* tmp = new T[size];//1.����һ��ԭ��2����С�Ŀռ䡣
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
//		cout << "��������Ҫת��������" << endl;
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
//		cout << "��������Ҫת���ĳ���" << endl;
//		float data;
//		cin >> data;
//		if (data > 0)
//		{
//			//��������
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

	// ������������
	int integerPart = static_cast<int>(decimal);
	while (integerPart != 0) {
		stack.Push(integerPart % 2);
		integerPart /= 2;
	}

	// ����С����
	stack.Push(-1);

	// ����С������
	double fractionPart = decimal - static_cast<int>(decimal);
	while (fractionPart > 0) {
		fractionPart *= 2;
		int bit = static_cast<int>(fractionPart);
		stack.Push(bit);
		fractionPart -= static_cast<int>(fractionPart);
	}

	// ���ɶ������ַ���
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
		cout << "����������" << endl;
		cin >> decimal;
		string binary = DecimalToBinary(decimal);
		cout << "ʮ���� " << decimal << ", ������ " << binary << endl;
	}
	return 0;
}