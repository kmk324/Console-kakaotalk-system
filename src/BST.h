#pragma once
#pragma once
#include <iostream>
using namespace std;

template<typename ItemType>
struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

template<typename ItemType>
class BST
{
public:
	BST() {}// constructor
	~BST();        // destructor
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int LengthIs() const;
	ItemType* RetrieveItem(ItemType& item, bool& found) const;
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void PrintTree(ostream &out) const;
	ItemType GetRootPointer();
private:
	TreeNode<ItemType>* root;

};



template<typename T>
bool BST<T>::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
	TreeNode<T>* location;
	try
	{
		location = new TreeNode;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}
template<typename T>
bool BST<T>::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
	return root == NULL;
}


template <class ItemType> int CountNodes(TreeNode<ItemType>* tree);
template<typename T>
int BST<T>::LengthIs() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
	return CountNodes(root);
}

template<typename ItemType>
ItemType* BST<ItemType>::RetrieveItem(ItemType & item, bool & found) const
{
	return Retrieve(root, item, found);
}


template< class ItemType >
int CountNodes(TreeNode<ItemType>* tree)
// Post: returns the number of nodes in the tree.
{
	if (tree == NULL)
		return 0;
	else
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}





template< class ItemType >
ItemType*  Retrieve(TreeNode<ItemType>* ptr, ItemType&  item, bool&   found)
{
	if (ptr == NULL)
	{
		found = false;
	}
	else if (item < ptr->info)				// GO LEFT
		Retrieve(ptr->left, item, found);
	else if (item > ptr->info) 			// GO RIGHT
		Retrieve(ptr->right, item, found);
	else
	{
		item = (ptr->info);   
		found = true;
		return &ptr->info;
	}
}

template< class  ItemType >
void   BST<ItemType> ::InsertItem(ItemType  item)
{
	Insert(root, item);
}

template <class ItemType>
void BST<ItemType> ::MakeEmpty()
{
	Destroy(root);
}

template< class  ItemType >
void Insert(TreeNode<ItemType>*&  ptr, ItemType  item)
{
	if (ptr == NULL)
	{        				// INSERT item HERE AS LEAF
		ptr = new TreeNode<ItemType>;
		ptr->right = NULL;
		ptr->left = NULL;
		ptr->info = item;
	}
	else if (item  <  ptr->info)				// GO LEFT
		Insert(ptr->left, item);
	else if (item  >  ptr->info) 			// GO RIGHT
		Insert(ptr->right, item);
	else if (item == ptr->info)
	{
		cout << "이미 존재하는 ID입니다." << endl;
	}
}


template<typename ItemType >
void Delete(TreeNode<ItemType>*& tree, ItemType item);

template<typename ItemType>
void BST<ItemType>::DeleteItem(ItemType item) // Calls the recursive function Delete to delete item from tree.
{
	Delete(root, item);
}

template< class ItemType>
void  Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree
// Post : item is not in tree
{
	if (item < tree->info)
		Delete(tree->left, item);	// Look in left subtree.
	else if (item > tree->info)
		Delete(tree->right, item);	// Look in right subtree.
	else
		DeleteNode(tree);	// Node found; call DeleteNode.
}



template< class ItemType >
void DeleteNode(TreeNode<ItemType>*& tree)
{
	ItemType data;
	TreeNode<ItemType>* tempPtr;
	tempPtr = tree;
	if (tree->left == NULL)
	{
		tree = tree->right;	delete tempPtr;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;	delete tempPtr;
	}
	else
	{
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);//Delete predecessor node.
	}
}
template <class ItemType >
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the rightmost
//  node in tree.
{
	while (tree->right != NULL)
		tree = tree->right;
	data = tree->info;
}

template <typename T>
void BST<T>::PrintTree(ostream& out) const
{
	//cout << "\tInOrder Traversal" << endl;
	PrintInOrderTraversal(root, out);
	//cout << "\t*****************" << endl;
	//cout << "\tPreOrder Traversal" << endl;
	//PrintPreOrderTraversal(root, out);
	//cout << "\t*****************" << endl;
	//cout << "\tPostOrder Traversal" << endl;
	//PrintPostOrderTraversal(root, out);
	cout << "\t*****************" << endl;
}
//	Inorder로 출력
template <typename T>
void PrintInOrderTraversal(TreeNode<T> *root, ostream &out)
{
	if (root != NULL)								//	root가 NULL일 때 까지
	{
		PrintInOrderTraversal(root->left, out);		//	왼쪽으로 이동 후 재귀실행
		out << root->info << endl;					//	해당 root에 위치한 item 출력
		PrintInOrderTraversal(root->right, out);	//	오른쪽으로 이동 후 재귀실행
	}
}

//	Preorder로 출력
template <typename T>
void PrintPreOrderTraversal(TreeNode<T> *root, ostream &out)
{
	if (root != NULL)								//	root가 NULL일 때 까지
	{
		out << root->info << endl;					//	해당 root에 위치한 item 출력
		PrintPreOrderTraversal(root->left, out);	//	왼쪽으로 이동 후 재귀실행
		PrintPreOrderTraversal(root->right, out);	//	오른쪽으로 이동 후 재귀실행
	}
}

//	Postorder로 출력
template <typename T>
void PrintPostOrderTraversal(TreeNode<T> *root, ostream &out)
{
	if (root != NULL)								//	root가 NULL일 때 까지
	{
		PrintPostOrderTraversal(root->left, out);	//	왼쪽으로 이동 후 재귀실행
		PrintPostOrderTraversal(root->right, out);	//	오른쪽으로 이동 후 재귀실행
		out << root->info << endl;					//	해당 root에 위치한 item 출력
	}
}
//

template< class  ItemType >
BST<ItemType> :: ~BST()		// DESTRUCTOR
{
	Destroy(root);
}

template< class ItemType >
void Destroy(TreeNode<ItemType>* ptr)
// Post:  All nodes of the tree pointed to by ptr are deallocated.
{
	if (ptr != NULL)
	{
		Destroy(ptr->left);
		Destroy(ptr->right);
		delete  ptr;
	}
}

/**
*	@brief 루트노드의 정보를 리턴.
*/
template<typename ItemType>
ItemType BST<ItemType> :: GetRootPointer()
{
	return root->info;//
}

