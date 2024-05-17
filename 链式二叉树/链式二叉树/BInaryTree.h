#pragma once
#include"TreeNode.h"
template<typename T>
class BinaryTree
{
private:
	TreeNode<T>* root;//创建节点类
public:
	BinaryTree();//构造函数
	~BinaryTree();//析构函数
	void insert(T value);//搜索二叉树插入函数
	TreeNode<T>* insertNode(TreeNode<T>* Node, T value);
	void leftTraversal();//中序遍历
	void leftTraversal(TreeNode<T>* node);
	void rightTraversal();//后序遍历
	void rightTraversal(TreeNode<T>*node);
	void midTraversal();//前序遍历
	void midTraversal(TreeNode<T>* node);
	int getDepth();//等到深度
	int getDepth(TreeNode<T>* node);
	int getleafCount();//叶子节点数
	int getleafCount(TreeNode<T>* node);
	void printsamelevel(int level);//各层的数据
	void printsamelevel(TreeNode<T>* node,int level);
	void destory(TreeNode<T>* node);//销毁树
	T getMaxvalue();//等到最大的数据
	T getMaxvalue(TreeNode<T>* node);
	T getParentNode(T value);
	TreeNode<T>* getParentNode(TreeNode<T>* node, T value);
};

template<typename T>
inline BinaryTree<T>::BinaryTree()//构造函数
{
	root = nullptr;//将根节点赋值为空
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	destory(root);//递归将二叉树销毁
}



template<typename T>
inline void BinaryTree<T>::insert(T value)
{
	root = insertNode(root, value);//搜索二叉树的添加
}

//template<typename T>
//inline TreeNode<T>* BinaryTree<T>::insertNode(TreeNode<T>* Node, T value)
//{
//	if (Node == nullptr)//当头节点都没有的时候，说明没有这个树
//	{
//		return new TreeNode<T>(value);//将这个节点进行赋值
//	}
//	if (value < Node->val)//传入的值大于双亲节点的值
//	{
//		Node->left = insertNode(Node->left, value);//向左递归
//	}
//	else
//	{
//		Node->right = insertNode(Node->right, value);
//	}
//	return Node;
//}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::insertNode(TreeNode<T>* Node, T value)
{
	
	if (Node == nullptr)//当头节点都没有的时候，说明没有这个树
	{
		return new TreeNode<T>(value);//将这个节点进行赋值
	}
	else
	{
		bool isleft;
		cout << "向左[1]  向右[0]" << endl;
		cin >> isleft;
		if (isleft)//插入到左子树
		{
			Node->left = insertNode(Node->left, value);//向左递归
		}
		else
		{
			Node->right = insertNode(Node->right, value);//插入到右子树
		}
	}
	return Node;
}
template<typename T>
inline void BinaryTree<T>::leftTraversal()
{
	leftTraversal(root);
}

template<typename T>//中序遍历
inline void BinaryTree<T>::leftTraversal(TreeNode<T>* node)
{
	if (node != nullptr)
	{
		leftTraversal(node->left);
		cout << node->val << " ";
		leftTraversal(node->right);
	}
}

template<typename T>
inline void BinaryTree<T>::rightTraversal()
{
	rightTraversal(root);
}

template<typename T>//后序遍历
inline void BinaryTree<T>::rightTraversal(TreeNode<T>* node)
{
	if (node != nullptr)
	{
		rightTraversal(node->left);
		rightTraversal(node->right);
		cout << node->val << " ";
	}
}

template<typename T>
inline void BinaryTree<T>::midTraversal()
{
	midTraversal(root);
}

template<typename T>//先序遍历
inline void BinaryTree<T>::midTraversal(TreeNode<T>* node)
{
	if (node != NULL)
	{
		cout << node->val << " ";
		midTraversal(node->left); 
		midTraversal(node->right);
	}
}

template<typename T>
inline int BinaryTree<T>::getDepth()
{
	return getDepth(root);
}

template<typename T>
inline int BinaryTree<T>::getDepth(TreeNode<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int leftDepth = getDepth(node->left);
	int rightDepth = getDepth(node->right);
	return max(leftDepth, rightDepth) + 1;
}

template<typename T>
inline int BinaryTree<T>::getleafCount()
{
	return getleafCount(root);
}

template<typename T>
inline int BinaryTree<T>::getleafCount(TreeNode<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	if (node->left == nullptr && node->right == nullptr)
	{
		return 1;
	}
	return getleafCount(node->left) + getleafCount(node->right);
}

template<typename T>
inline void BinaryTree<T>::printsamelevel(int level)
{
	printsamelevel(root, level);
}

template<typename T>
inline void BinaryTree<T>::printsamelevel(TreeNode<T>* node, int level)
{
	if (node == nullptr)
	{
		return;
	}
	if (level == 1)
	{
		cout << node->val << " ";
	}
	else if (level > 1)
	{
		printsamelevel(node->left, level - 1);
		printsamelevel(node->right, level - 1);
	}
}

template<typename T>
inline void BinaryTree<T>::destory(TreeNode<T>* node)
{
	if (node != nullptr)
	{
		destory(node->left);
		destory(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T>
inline T BinaryTree<T>::getMaxvalue()
{
	return getMaxvalue(root);
}

template<typename T>
inline T BinaryTree<T>::getMaxvalue(TreeNode<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	int maxValue = node->val;
	int leftmax = getMaxvalue(node->left);
	int rightmax = getMaxvalue(node->right);
	if (leftmax > maxValue)
	{
		maxValue = leftmax;
	}
	if (rightmax > maxValue)
	{
		maxValue = rightmax;
	}
	return maxValue;
}

template<typename T>
inline T BinaryTree<T>::getParentNode(T value)
{
	TreeNode<T>*node= getParentNode(root, value);
	return node->val;
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::getParentNode(TreeNode<T>* node, T value)
{
	if (node == nullptr || node->val == value)
	{
		return nullptr;
	}
	else if ((node->left != nullptr && node->left->val == value) || (node->right != nullptr && node->right->val == value))
	{
		return node;
	}
	else
	{
		TreeNode<T>* parent = getParentNode(node->left, value);
		if (parent == nullptr)
		{
			parent = getParentNode(node->right, value);
		}
		return parent;
	}
}





