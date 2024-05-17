#pragma once
#include"iostream"
using namespace std;
template<typename T>
class TreeNode
{
public:
	T val;
	TreeNode<T>* left;
	TreeNode<T>* right;
public:
	TreeNode(T value);
	~TreeNode();
	
};

template<typename T>
inline TreeNode<T>::TreeNode(T value)
{
	val = value;
	left = nullptr;
	right = nullptr;
}

template<typename T>
inline TreeNode<T>::~TreeNode()
{
	delete right;
	delete left;
	left = nullptr;
	right = nullptr;
}

