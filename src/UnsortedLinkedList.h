#pragma once
#pragma once

template <typename T>
struct Node
{
	T data;	///< A data for each node.
	Node* next;	///< A node pointer to point succeed node.
};
/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class UnsortedLinkedList
{
public:
	/**
	*	default constructor.
	*/
	UnsortedLinkedList();

	/**
	*	destructor.
	*/
	~UnsortedLinkedList();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	�������� �ִ´�.
	*	@pre	����
	*	@post	�������� �����Ͽ� �ִ´�.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);
	/**
	*	@brief	Delete item into this list.
	*	@pre	����
	*	@post	�ش� ã�Ƽ��������� �����.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Delete(T item);
	/**
	*	@brief	Delete item into this list.
	*	@pre	����
	*	@post	�ش� ã�Ƽ� ������ ���� �ٲ��ش�.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Replace(T item);
	/**
	*	ã�� �������� �ִٸ� �� �������� ��� ����ּҰ� ����
	*/
	Node<T>* Getitem(T item); // ã�� �������� �ִٸ� �� �������� ��� ����ּҰ� ����
							  /**
							  *	m_pList�ּ� ����
							  */
	Node<T>* First(); // ��� �ּ� ����
					  /**
					  *	���� ���� ������
					  */
	UnsortedLinkedList(const UnsortedLinkedList<T>& List); // ���� ���������
										   /**
										   *	=�����ε�
										   */
	void operator=(const UnsortedLinkedList<T>& ll); // =�����ε� 

private:
	Node<T>* m_pList;	///< Pointer for pointing a first node.
	Node<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
UnsortedLinkedList<T>::UnsortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}
template <typename T>
UnsortedLinkedList<T>::UnsortedLinkedList(const UnsortedLinkedList<T>& List)
{
	Node<T>* copy;
	if (List.m_pList == NULL) // �Ķ������ ����Ʈ�� ��尡 ���ٸ�
	{
		this->m_pList = NULL;
		this->m_nLength = List.m_nLength;
	}
	else // ��尡 1���� �ִٸ�
	{
		copy = new Node<T>; //ī���� ��带 ������ְ�
		Node<T>* temp; // ����Ʈ�� ��尪�� ���� �ӽú���
		temp = List.m_pList;
		this->m_pList = copy;// �� ����Ʈ�� ��带 ī�Ƿ� �����ְ�
		copy->data = temp->data; // �Ķ������ ù��° ��带 ī�ǿ� ����
		temp = temp->next; // ������ ��ĭ �Ű���
		while (temp != NULL) // ������ ���� �ƴϸ�(����尡 �����ʴٸ�)
		{
			copy->next = new Node<T>; // ī���� ���� ��� ����
			copy = copy->next; // ī�Ǹ� ��ĭ �Ű���
			copy->next = NULL; // ī���� �ؽ�Ʈ�� ��
			copy->data = temp->data; // ������ ����
			temp = temp->next; // ������ �Ű���
		}
		copy->next = NULL; //ī���� ������ ����� �ؽ�Ʈ�� �������� ��
		this->m_nLength = List.m_nLength; // ���� ����
	}
}

// Class destructor
template <typename T>
UnsortedLinkedList<T>::~UnsortedLinkedList()
{}


// Initialize list to empty state.
template <typename T>
void UnsortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	Node<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int UnsortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int UnsortedLinkedList<T>::Add(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	Node<T> *node = new Node<T>;
	Node<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int UnsortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	Node<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
			this->m_pCurPointer = location;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}

// Initializes current pointer for an iteration through the list.
template <typename T>
void UnsortedLinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void UnsortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	//current position �� ���� ���� �̵�
	else
	{
		m_pCurPointer = m_pCurPointer->next;
	}
	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

template <typename T>
int UnsortedLinkedList<T>::Delete(T item)
{
	if (this->Get(item)) // ���� ���̵��� ã�´ٸ�
	{
		Node<T> *temp = this->m_pCurPointer; // ������ ���� ���̵� ���� ������ �ִ� �� ����
		if (this->m_nLength == 1) // 1���ۿ� �����Ͱ� ���ٸ�
		{

			this->m_pList = NULL; // �ʱ�ȭ���ְ�
			this->ResetList(); // ���½����ְ�
			this->m_nLength--; // �������̰�
			delete temp; // ���� �����Ҵ� ����Ʈ
			return 1;
		}
		else // �ƴ϶��
		{
			this->ResetList();
			this->m_pCurPointer = this->m_pList; // ������Ʈ ó������ �����ְ�
			if (temp == this->m_pList) // ���� ù��°���
			{
				m_pList = m_pList->next; // ó���� ����
				this->m_nLength--; // �������̰�
				delete temp; // �����Ҵ�����
				return 1;
			}
			else // ù��°�ƴ϶��
			{
				while (1)// ������������ �������͸� �����༭ �ش� ������ ����
				{
					if (this->m_pCurPointer->next == temp)  // ���������� ������ ����(�����ҵ�����)��� 
					{
						if (temp->next == NULL)// ������ ��������忴�ٸ�
						{
							this->m_pCurPointer->next = NULL; // ���������� �ؽ�Ʈ�� �������� �ٲ��ְ�
							this->m_nLength--; // �������̰�
							delete temp; //�����Ҵ� ����
							return 1;
						}
						else
						{
							this->m_pCurPointer->next = temp->next; //���������� �ؽ�Ʈ�� ������ �ؽ�Ʈ�� �ٲ���
							this->m_nLength--;// �������̰�
							delete temp; // �����Ҵ� ����
							return 1;
						}
					}
					this->m_pCurPointer = this->m_pCurPointer->next;// �ƴ϶�� �������� ��ĭ �Ű���
				}
			}
		}
	}
	else
	{
		return 0;
	}
}

template <typename T>
int UnsortedLinkedList<T>::Replace(T item)
{
	T temp;
	temp = item;
	if (this->Get(temp)) // ���̵� ��ġ��
	{
		this->m_pCurPointer->data = item; // �ش���̵� �����͸� �־���
		return 1;
	}
	else
	{
		return 0;
	}
}
template <typename T>
Node<T>* UnsortedLinkedList<T>::Getitem(T item)
{
	bool moreToSearch, found;
	Node<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return location;
	else
		return NULL;
}
template <typename T>
Node<T>* UnsortedLinkedList<T>::First()
{
	return this->m_pList;
}
template <typename T>
void UnsortedLinkedList<T>::operator=(const UnsortedLinkedList<T>& ll) //=�����ε� ��������ڿ� �ڵ� ����
{
	Node<T>* copy;
	if (ll.m_pList == NULL)
	{
		this->m_pList = NULL;
		this->m_nLength = ll.m_nLength;
	}
	else
	{
		copy = new Node<T>;
		Node<T>* temp;
		temp = ll.m_pList;
		this->m_pList = copy;
		copy->data = temp->data;
		temp = temp->next;
		while (temp != NULL)
		{
			copy->next = new Node<T>;
			copy = copy->next;
			copy->next = NULL;
			copy->data = temp->data;
			temp = temp->next;
		}
		copy->next = NULL;
		this->m_nLength = ll.m_nLength;
	}
}
