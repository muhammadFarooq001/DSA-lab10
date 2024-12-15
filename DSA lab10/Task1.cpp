#include<iostream>
using namespace std;
#include<vector>
template<typename T>
class Node
{
public:
	T data;
	Node* left;
	Node* right;
	Node(T val, Node* l=nullptr, Node* r=nullptr)
	{
		data = val;
		left = l;
		right = r;
	}
};
template<typename T>
class Tree
{
	Node<T>* root = nullptr;
	bool search(Node<T>* temp, int value);
	int countNodes(Node<T>* node);
	int findHeight(Node<T>* node);
public:
	void insertData(T val);
	void inOrder(Node<T>* node);
	void preOrder(Node<T>* node);
	void postOrder(Node<T>* node);
	bool search( int value);
	int countNodes();
	int findHeight();
	bool isBalanced();
	//void creatTree(int size);
};
int main()
{
	//Node<int> t{ 10 };
	Tree<int> obj;
	obj.insertData(5);
	obj.insertData(10);
	/*obj.insertData(15);
	obj.insertData(16);
	obj.insertData(17);*/
	cout<<obj.isBalanced();

}
template<typename T>
bool Tree<T>::isBalanced()
{
	if (!root)
	{
		return true;
	}
	int left = findHeight(root->left);
	int right = findHeight(root->right);
	return (left+1==right || right+1==left || left==right) ? true : false;
}
template<typename T>
int Tree<T>::findHeight(Node<T>* node)
{
	if (node == nullptr) 
	{
		return -1;
	}
	int left = findHeight(node->left);
	int right = findHeight(node->right);
	return 1 + max(left, right);
}
template<typename T>
int Tree<T>::findHeight()
{
	return findHeight(root);
}
template<typename T>
int Tree<T>::countNodes(Node<T> *temp)
{
	static int count = 0;
	if (!temp)
	{
		return count;
	}
	count++;
	countNodes(temp->left);
	countNodes(temp->right);
	return count;
}
template<typename T>
int Tree<T>::countNodes()
{
	return countNodes(root);
}
template<typename T>
bool Tree<T>::search(int value)
{
	return search(root, value);
}
template<typename T>
bool Tree<T>::search(Node<T> *temp,int value)
{
	bool flag = false;
	if (temp == nullptr)
	{
		return  false;
	}
	else if (temp->data == value)
	{
		flag= true;
	}
	return flag + search(temp->left,value) + search(temp->right,value);
}
template<typename T>
void Tree<T>::inOrder(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	inOrder(node->left);
	cout << node->data << ' ';
	inOrder(node->right);

}
template<typename T>
void Tree<T>::preOrder(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data << ' ';
	preOrder(node->left);
	preOrder(node->right);
}
template<typename T>
void Tree<T>::postOrder(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << ' ';
}
template<typename T>
void Tree<T>::insertData(T val)
{
	if (root == nullptr)
	{
		//cout << "enter first time";
		root = new Node<T>{ val };
		return;
	}
	Node<T>* temp = root, * previous = root;
	bool flag = false;
	while (temp != nullptr && flag == false)
	{
		if (temp->data < val)
		{
			previous = temp;
			temp = temp->right;
		}
		else if (temp->data > val)
		{
			previous = temp;
			temp = temp->left;
		}
		else
		{
			flag = true;
		}
	}
	if (temp == nullptr && flag == false)
	{
		if (previous->data < val)
		{
			previous->right = new Node<T>{ val };
		}
		else
		{
			previous->left = new Node<T>{ val };
		}
		return;
	}
	else
	{
		cout << "data is already insert\n";
	}
}

