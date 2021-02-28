#define _CRT_SECURE_NO_WARN
#include<iostream>
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
	:_pLeft(nullptr)
	, _pRight(nullptr)
	, _data(data)
	{}
	BSTNode<T>* _pLeft;
	BSTNode<T>* _pright;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
	typedef Node* PNode;
public:
	BSTree()
		:_pRoot(nullptr)
	{}
	~BSTree();
	pNode Find(const T& data);
	bool Insert(const T& data)
	{
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}//非空插入为根
	}
	//否则需要找到当前待插入节点的位置，
	PNode pCur = _pRoot;
	pNode pParent = nullptr;
	while (pCur)
	{
		pParent = pCur;
		if (data < pCur->_data)
			pCur = pCur->_pLeft;
		else if (data > pCur->_data)
			pCur = pCur->_pRight;
		else
			return false;
	}//当前pParent的位置就是数据插入位置
	//插入元素
	pCur = new Node(data);
	if (data < pParent->_data)
		pParent->_pLeft = pCur;
	else
		pParent->_pRight = pCur;
	return true;
	bool Erase(const T& data)
	{
		if (nullptr == _pRoot)
			return false;
		pNode pCur = _pRoot;//定义一个dur，以便以找到书中data所在节点
		pNode pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
				break;
		}
		else if (data < pCur->_data)
		{
			pParent = pCur;
			pCur = pCur->_pLeft;
		}
		else
		{
			pParent = pCur;
			pCur = pCur->_pRight;
		}
	}
	if (nullpr = pCur)
		return false;//不再树中，不用删除
	if (nullptr == pCur->_pRight)//右子树Wie空，当前节点只有左子树
	{
		delete pCur;
	}
	if (nullptr == pCur->_pLeft)
	{
		delete pCur;
	}
	else//左右子树都存在,因为删除该节点会导致结构发生变化，根据二叉搜索树，左边节点值小于根，右边节点数大于根，每个子树都是二叉搜索树；
	{
		//找到左子树最大值，或者右子树最小值，来代替目前“根”节点，结构改动幅度小
		while (pCur->_pLeft)
		{
			pParent = pCur->_pLeft;
			pCur = pCur->_pLeft;
		}
		swap(pCur, pParent);
		delete pCur;


		
	}
	return true;
	void InOrder();
private:
	PNode _pRoot;
};
