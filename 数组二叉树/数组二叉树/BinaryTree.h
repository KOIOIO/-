#pragma once
#include"iostream"
#include<math.h>
#include<iomanip>
using namespace std;
template<typename T>
class BinaryTree
{
private:
	T* treeArray;
	int size;
public:
	BinaryTree(int maxsize);
	void insert(int n);
	void preTraversal(int index);//前序遍历
	void midTraversal(int index);//中序遍历
	void posTraversal(int index);//后序遍历
	int getDepth();//获取树的深度
	int getLeafCount();//获取叶子节点数
	T getMAxValue();//获取节点最大值
	void print_same_level(int level);//打印同层节点
	T getParent(int index);//获得节点双亲
	//堆排序
	//未完成
	void BuildMaxHeap(int size, int index);
	void heapSort(int size);
	//将二叉树输出
	void printUtil(int index, int space);
	void printtree();
};

template<typename T>
inline BinaryTree<T>::BinaryTree(int maxsize)
{
	size = pow(2, maxsize)-1;//根据层数分配空间
	treeArray = new T[size];
	for (int i = 0; i < size; i++)
	{
		treeArray[i] = -1;
	}
}

template<typename T>
inline void BinaryTree<T>::insert(int n)
{
	for (int index = 0; index < n; index++)
	{
		int data=0;
		cin >> data;
		treeArray[index] = data;
	}
}

template<typename T>
inline void BinaryTree<T>::preTraversal(int index)
{
	if (index >= 0 && index < size && treeArray[index] != -1)
	{
		cout << treeArray[index] << " ";
		preTraversal(2 * index + 1);//左子树
		preTraversal(2 * index + 2);//右子树
	}
}

template<typename T>
inline void BinaryTree<T>::midTraversal(int index)
{
	if (index >= 0 && index < size && treeArray[index] != -1)
	{
		midTraversal(2 * index + 1);
		cout << treeArray[index] << " ";
		midTraversal(2 * index + 2);
	}
}

template<typename T>
inline void BinaryTree<T>::posTraversal(int index)
{
	if (index >= 0 && index < size && treeArray[index] != -1)
	{
		posTraversal(2 * index + 1);
		posTraversal(2 * index + 2);
		cout << treeArray[index] << " ";
	}
}

template<typename T>
inline int BinaryTree<T>::getDepth()
{
	return log(size + 1);
}

template<typename T>
inline int BinaryTree<T>::getLeafCount()
{
	int count = 0;
	for (int i = 0; i < size; i++) 
	{
		if (treeArray[i] != -1 && treeArray[2 * i + 1] == -1 && treeArray[2 * i + 2] == -1) 
		{
			count++; // 叶子节点的判断条件：左右子节点都为空
		}
	}
	return count;
}

template<typename T>
inline T BinaryTree<T>::getMAxValue()
{
	T max = treeArray[0];
	for (int i = 0; i < size; i++)
	{
		if (treeArray[i] > max)
		{
			max = treeArray[i];
		}
	}
	return max;
}

template<typename T>
inline void BinaryTree<T>::print_same_level(int level)
{
	int start = pow(2, level - 1) - 1;
	int end = pow(2, level) - 2;
	for (int i = start; i <= end; i++)
	{
		if (treeArray[i] != -1)
		{
			cout << treeArray[i] << " ";
		}
	}
}

template<typename T>
inline T BinaryTree<T>::getParent(int index)
{
	if (index >= 0&& index < size)
	{
		 return treeArray[(index - 1) / 2];
	}
	return -1;
}

template<typename T>
inline void BinaryTree<T>::BuildMaxHeap(int size, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left<size && treeArray[left]>treeArray[largest])
	{
		largest = left;
	}
	if (right<size && treeArray[right]>treeArray[largest])
	{
		largest = right;
	}
	if (largest != index)
	{
		swap(treeArray[index], treeArray[largest]);
		BuildMaxHeap(size, largest);

	}
}

template<typename T>
inline void BinaryTree<T>::heapSort(int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		BuildMaxHeap(size, i);
	}
	for (int i = size; i > 0; i--)
	{
		swap(treeArray[0], treeArray[i]);
		BuildMaxHeap(i, 0);
	}
}

template<typename T>
inline void BinaryTree<T>::printUtil(int index, int space)
{
	if (index >=size  || treeArray[index] == NULL) 
	{
		return;
	}

	space += 5;

	printUtil(2 * index + 1, space);

	cout << setw(space) << treeArray[index] << endl;

	printUtil(2 * index + 2, space);
}

template<typename T>
inline void BinaryTree<T>::printtree()
{
	printUtil(0, 0);
}

//template<typename T>
//inline void BinaryTree<T>::heapify(T arr[], int n, int i)
//{
//	int largest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	if (left<n && arr[left]>arr[largest])
//	{
//		largest = left;
//	}
//	if (right<n && arr[right]>arr[largest])
//	{
//		largest = right;
//	}
//	if (largest != i)
//	{
//		swap(arr[i], arr[largest]);
//		heapify(arr, n, largest);
//	}
//}
//
//template<typename T>
//inline void BinaryTree<T>::heapSort(T arr[], int n)
//{
//	for (int i = n / 2 - 1; i >= 0; i--)
//	{
//		heapify(arr, n, i);
//	}
//	for (int i = n - 1; i > 0; i--)
//	{
//		swap(arr[0], arr[i]);
//		heapify(arr, i, 0);
//	}
//}

