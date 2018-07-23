#pragma once
#include "ItemType.h"
#include <string>
class FriendGroup
{
private:
	string groupname; //ģ���׷��� �̸�
	UnsortedLinkedList<FriendType> GroupFriendList; //ģ���� ģ���׷츮��Ʈ�� ������ ����

public:
	
	FriendGroup() {}
	
	//������ �����ε�
	FriendGroup(string s) 
	{
		groupname = s;
	}
	
	//������ �����ε�
	FriendGroup(string s, UnsortedLinkedList<FriendType> t)
	{
		groupname = s;
		GroupFriendList = t;
	}

	//�Ķ������ ������Ÿ�� ����fr�� �׷������帮��Ʈ�� add�Ѵ�.
	void AddFriend(FriendType fr)
	{
		GroupFriendList.Add(fr);
	}
	~FriendGroup() {}

	//������� ������ ���� �Լ�
	string GetGroupname()
	{
		return groupname;
	}

	//��������� �� ���ִ� �Լ�
	void SetGroupname(string s)
	{
		groupname = s;
	}
	//������� ������ ���� �Լ�
	UnsortedLinkedList<FriendType>* getGroupFriendList()
	{
		return &GroupFriendList;
	}

	//�ڷᱸ���� ����ϱ� ���� ������ �����ε�
	bool FriendGroup ::operator<(FriendGroup item)
	{
		return this->groupname < item.groupname ;
	}

	//�ڷᱸ���� ����ϱ� ���� ������ �����ε�
	bool  FriendGroup ::operator> (FriendGroup item)
	{
		return this->groupname > item.groupname;
	}

	//�ڷᱸ���� ����ϱ� ���� ������ �����ε�
	void FriendGroup ::operator = (FriendGroup &item)
	{
		groupname = item.groupname;
	//	FriendType Temp;
	//	for (int i = 0; GroupFriendList.GetLength(); i++)
	//	{
		GroupFriendList = *item.getGroupFriendList();
			//GroupFriendList.GetNextItem(Temp);
			
			//GroupFriendList = item.GroupFriendList;
	//	}
	}


	//ģ�� �׷츮��Ʈ ���� ���.
	void PrintGroupFriendList()
	{
		FriendType m_Array[MAXSIZE]; //���������̱� ������ �Լ��� ������ �������.
		FriendType tempFriend;
		GroupFriendList.ResetList();
		cout << "�׷��̸� : " << groupname << endl;
		for (int i = 0; i < GroupFriendList.GetLength(); i++)
		{
			GroupFriendList.GetNextItem(tempFriend);
			m_Array[i] = tempFriend;
			m_Array[i].DisplayRecordd();
		}
		cout << endl;
	}

};