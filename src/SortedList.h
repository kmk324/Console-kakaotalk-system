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
class SortedList //add�� �� sorted ����� ��������. ��ǻ� unsorted ����Ʈ��.
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
	*	@brief	primary key�� �������� ������ �ǵ��� �˸��� �ڸ��� �׸��� �߰��Ѵ�.
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
	*	@brief	�Ϻθ� ä�����ִ� data�� �˸��� ������ �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	data ���� ��� ������ ��� ä������.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return	ã���� 1, ã�� ���ϸ� 0�� �����Ѵ�.
	*/
	int Get(T& data);

	/**
	*	@brief	����ڰ� ������ ItemType�� �迭���� �����Ѵ�.
	*	@pre	data�� ID ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� �Է��� �׸��� �����ǰ� length�� 1�پ���.
	*	@param	data : �Ϻθ� ä�����ִ� ItemType.
	*	@return ������ ���������� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	����ڰ� ������ ItemType�� �ش��ϴ� �迭�� �ڸ��� �Ķ������ ������ �����Ѵ�.
	*	@pre	data�� ��� ������ ä�����־�� �Ѵ�.
	*	@post	����ڰ� ������ �׸��� data�� ��������.
	*	@param	data : ��� ������ ä�����ִ� ItemType.
	*	@return	���������� ���������� 1, �ƴϸ� 0�� �����Ѵ�.
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
	if (!IsFull())	//�� ���� �ʾ����� �׸��� �߰��Ѵ�.
	{

		m_Array[m_Length] = inData;
		m_Length++;
		return 1;	//�׸��� �߰������Ƿ� 1�� �������ش�.
	}
	else	//�� á���Ƿ� �߰��� �� ����.
		return 0;	//0�� �������ش�.
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
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//ID���� �����ϴ� data�� (�迭 �ȿ� �����ϴ� �׸�� ��) �˸´� �׸��� ã�� �������ش�.
template <typename T>
int SortedList<T>::Get(T& data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetId() == data.GetId())	//data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			data = m_Array[i];
			return 1;	//data�� �������� �� 1�� �����Ѵ�.
		}
	}
	return 0;	//ã�� ���ϸ� 0�� �����Ѵ�.
}

//ID���� �����ϴ� data�� �̿��Ͽ� �� ID���� ���� ID�� ������ �ִ� �׸��� �����ְ� length�� 1 ���ش�.
template <typename T>
int SortedList<T>::Delete(T data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetId() == data.GetId())	//data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			for (int j = i; j<m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	//���� �׸��� �ڸ��� ���� �׸��� �����ϰ� �̰��� ������ �׸���� �ݺ��Ѵ�. m_Length�� 1 �ٿ��ش�.
			return 1;	//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
		}
	}
	return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
}


//data�� �̿��Ͽ� �� ID���� ������ �ִ� �׸��� ã�� �װ��� data�� ������ �����Ѵ�.
template <typename T>
int SortedList<T>::Replace(T data)
{
	for (int i = 0; i<m_Length; i++)
	{
		if (m_Array[i].GetId() == data.GetId())	//data�� 'List �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			m_Array[i].SetRecord(data.GetId(), data.GetName(), data.GetAddress(), data.GetBirth(), data.GetGender(), data.GetStatusMemo(), data.GetPw(), data.GetBGP());	//data�� ������ List�� �׸� �����Ѵ�.
			return 1;	//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
		}
	}
	return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
}



#endif	// _SORTEDLIST_H
