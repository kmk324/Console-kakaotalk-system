#pragma once
#pragma once
#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "ItemType.h"

#define MAXSIZE 100

/**
*	array based simple  unsorted list.
*/

template <typename T>
class SortedList //add할 때 sorted 기능을 삭제했음. 사실상 unsorted 리스트임.
{
public:
	/**
	*	default constructor.
	*/
	SortedList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~SortedList() {}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/

	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	primary key를 기준으로 정렬이 되도록 알맞은 자리에 항목을 추가한다.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	일부만 채워져있는 data에 알맞은 정보를 저장한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	data 안의 멤버 변수가 모두 채워진다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return	찾으면 1, 찾지 못하면 0을 리턴한다.
	*/
	int Get(T& data);

	/**
	*	@brief	사용자가 지정한 ItemType를 배열에서 삭제한다.
	*	@pre	data의 ID 변수는 채워져있어야 한다.
	*	@post	사용자가 입력한 항목은 삭제되고 length가 1줄어든다.
	*	@param	data : 일부만 채워져있는 ItemType.
	*	@return 삭제에 성공했으면 1, 아니면 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	사용자가 지정한 ItemType에 해당하는 배열의 자리에 파라미터의 내용을 복사한다.
	*	@pre	data의 모든 변수가 채워져있어야 한다.
	*	@post	사용자가 지정한 항목이 data와 같아진다.
	*	@param	data : 모든 변수가 채워져있는 ItemType.
	*	@return	성공적으로 수정했으면 1, 아니면 0을 리턴한다.
	*/
	int Replace(T data);



private:
	T m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};
/////////////////////////////////////////////////////////////////////////////


// Make list empty.
template <typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
template <typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
template <typename T>
bool SortedList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// add a new data into list.
template <typename T>
int SortedList<T>::Add(T inData)
{
	if (!IsFull())	//꽉 차지 않았으면 항목을 추가한다.
	{

		m_Array[m_Length] = inData;
		m_Length++;
		return 1;	//항목을 추가했으므로 1을 리턴해준다.
	}
	else	//꽉 찼으므로 추가할 수 없다.
		return 0;	//0을 리턴해준다.
}

// Initialize list iterator.
template <typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}
// move list iterator to the next item in list and get that item.
template <typename T>
int SortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//ID값만 존재하는 data에 (배열 안에 존재하는 항목들 중) 알맞는 항목을 찾아 복사해준다.
template <typename T>
int SortedList<T>::Get(T& data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetId() == data.GetId())	//data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
		{
			data = m_Array[i];
			return 1;	//data에 복사해준 뒤 1을 리턴한다.
		}
	}
	return 0;	//찾지 못하면 0을 리턴한다.
}

//ID값만 존재하는 data를 이용하여 그 ID값과 같은 ID를 가지고 있는 항목을 지워주고 length를 1 빼준다.
template <typename T>
int SortedList<T>::Delete(T data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetId() == data.GetId())	//data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
		{
			for (int j = i; j<m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	//지울 항목의 자리에 다음 항목을 복사하고 이것을 마지막 항목까지 반복한다. m_Length를 1 줄여준다.
			return 1;	//항목을 삭제하는데 성공했으므로 1을 리턴해준다.
		}
	}
	return 0;	//항목을 삭제하는데 실패했으므로 0을 리턴해준다.
}


//data를 이용하여 그 ID값을 가지고 있는 항목을 찾고 그곳에 data의 내용을 복사한다.
template <typename T>
int SortedList<T>::Replace(T data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetId() == data.GetId())	//data와 'List 중 하나의 항목'의 ID값이 같을 때
		{
			m_Array[i].SetRecord(data.GetId(), data.GetName(), data.GetAddress(), data.GetBirth(), data.GetGender(), data.GetStatusMemo(), data.GetPw(), data.GetBGP());	//data의 내용을 List의 항목에 복사한다.
			return 1;	//항목을 수정하는데 성공했으므로 1을 리턴해준다.
		}
	}
	return 0;	//항목을 수정하는데 실패했으므로 0을 리턴해준다.
}



#endif	// _SORTEDLIST_H
