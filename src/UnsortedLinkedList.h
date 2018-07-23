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
	*	@brief	아이템을 넣는다.
	*	@pre	없음
	*	@post	아이템을 정렬하여 넣는다.
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
	*	@pre	없음
	*	@post	해당 찾아서아이템을 지운다.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Delete(T item);
	/**
	*	@brief	Delete item into this list.
	*	@pre	없음
	*	@post	해당 찾아서 아이템 값을 바꿔준다.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Replace(T item);
	/**
	*	찾는 아이템이 있다면 그 아이템이 담긴 노드주소값 리턴
	*/
	Node<T>* Getitem(T item); // 찾는 아이템이 있다면 그 아이템이 담긴 노드주소값 리턴
							  /**
							  *	m_pList주소 리턴
							  */
	Node<T>* First(); // 헤드 주소 리턴
					  /**
					  *	깊은 복사 생성자
					  */
	UnsortedLinkedList(const UnsortedLinkedList<T>& List); // 깊은 복사생성자
										   /**
										   *	=오버로딩
										   */
	void operator=(const UnsortedLinkedList<T>& ll); // =오버로딩 

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
	if (List.m_pList == NULL) // 파라미터의 리스트에 노드가 없다면
	{
		this->m_pList = NULL;
		this->m_nLength = List.m_nLength;
	}
	else // 노드가 1개라도 있다면
	{
		copy = new Node<T>; //카피할 노드를 만들어주고
		Node<T>* temp; // 리스트의 헤드값을 받을 임시변수
		temp = List.m_pList;
		this->m_pList = copy;// 이 리스트의 헤드를 카피로 맞춰주고
		copy->data = temp->data; // 파라미터의 첫번째 노드를 카피에 저장
		temp = temp->next; // 템프를 한칸 옮겨줌
		while (temp != NULL) // 템프가 눌이 아니면(옆노드가 없지않다면)
		{
			copy->next = new Node<T>; // 카피의 다음 노드 생성
			copy = copy->next; // 카피를 한칸 옮겨줌
			copy->next = NULL; // 카피의 넥스트는 눌
			copy->data = temp->data; // 데이터 복사
			temp = temp->next; // 옆노드로 옮겨줌
		}
		copy->next = NULL; //카피의 마지막 노드의 넥스트를 눌값으로 함
		this->m_nLength = List.m_nLength; // 길이 복사
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
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
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
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	Node<T> *node = new Node<T>;
	Node<T> *pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
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
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void UnsortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	//current position 을 다음 노드로 이동
	else
	{
		m_pCurPointer = m_pCurPointer->next;
	}
	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}

template <typename T>
int UnsortedLinkedList<T>::Delete(T item)
{
	if (this->Get(item)) // 같은 아이디을 찾는다면
	{
		Node<T> *temp = this->m_pCurPointer; // 템프에 같은 아이디 값을 가지고 있는 곳 저장
		if (this->m_nLength == 1) // 1개밖에 데이터가 없다면
		{

			this->m_pList = NULL; // 초기화해주고
			this->ResetList(); // 리셋시켜주고
			this->m_nLength--; // 길이줄이고
			delete temp; // 템프 동적할당 딜리트
			return 1;
		}
		else // 아니라면
		{
			this->ResetList();
			this->m_pCurPointer = this->m_pList; // 컬포인트 처음으로 맞춰주고
			if (temp == this->m_pList) // 만약 첫번째라면
			{
				m_pList = m_pList->next; // 처음을 빼줌
				this->m_nLength--; // 길이줄이고
				delete temp; // 동적할당제거
				return 1;
			}
			else // 첫번째아니라면
			{
				while (1)// 템프이전으로 컬포인터를 보내줘서 해당 데이터 삭제
				{
					if (this->m_pCurPointer->next == temp)  // 컬포인터의 다음이 템프(제거할데이터)라면 
					{
						if (temp->next == NULL)// 템프가 마지막노드였다면
						{
							this->m_pCurPointer->next = NULL; // 컬포인터의 넥스트를 눌값으로 바꿔주고
							this->m_nLength--; // 길이줄이고
							delete temp; //동적할당 제거
							return 1;
						}
						else
						{
							this->m_pCurPointer->next = temp->next; //컬포인터의 넥스트를 템프의 넥스트로 바꿔줌
							this->m_nLength--;// 길이줄이고
							delete temp; // 동적할당 제거
							return 1;
						}
					}
					this->m_pCurPointer = this->m_pCurPointer->next;// 아니라면 컬포인터 한칸 옮겨줌
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
	if (this->Get(temp)) // 아이디가 겹치면
	{
		this->m_pCurPointer->data = item; // 해당아이디에 데이터를 넣어줌
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
void UnsortedLinkedList<T>::operator=(const UnsortedLinkedList<T>& ll) //=오버로딩 복사생성자와 코드 같음
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
