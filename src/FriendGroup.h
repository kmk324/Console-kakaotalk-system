#pragma once
#include "ItemType.h"
#include <string>
class FriendGroup
{
private:
	string groupname; //친구그룹의 이름
	UnsortedLinkedList<FriendType> GroupFriendList; //친구의 친구그룹리스트를 저장할 변수

public:
	
	FriendGroup() {}
	
	//생성자 오버로딩
	FriendGroup(string s) 
	{
		groupname = s;
	}
	
	//생성자 오버로딩
	FriendGroup(string s, UnsortedLinkedList<FriendType> t)
	{
		groupname = s;
		GroupFriendList = t;
	}

	//파라미터의 프렌드타입 변수fr을 그룹프렌드리스트에 add한다.
	void AddFriend(FriendType fr)
	{
		GroupFriendList.Add(fr);
	}
	~FriendGroup() {}

	//멤버변수 접근을 위한 함수
	string GetGroupname()
	{
		return groupname;
	}

	//멤버변수를 셋 해주는 함수
	void SetGroupname(string s)
	{
		groupname = s;
	}
	//멤버변수 접근을 위한 함수
	UnsortedLinkedList<FriendType>* getGroupFriendList()
	{
		return &GroupFriendList;
	}

	//자료구조를 사용하기 위한 연산자 오버로딩
	bool FriendGroup ::operator<(FriendGroup item)
	{
		return this->groupname < item.groupname ;
	}

	//자료구조를 사용하기 위한 연산자 오버로딩
	bool  FriendGroup ::operator> (FriendGroup item)
	{
		return this->groupname > item.groupname;
	}

	//자료구조를 사용하기 위한 연산자 오버로딩
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


	//친구 그룹리스트 정보 출력.
	void PrintGroupFriendList()
	{
		FriendType m_Array[MAXSIZE]; //지역변수이기 때문에 함수가 끝나면 사라진다.
		FriendType tempFriend;
		GroupFriendList.ResetList();
		cout << "그룹이름 : " << groupname << endl;
		for (int i = 0; i < GroupFriendList.GetLength(); i++)
		{
			GroupFriendList.GetNextItem(tempFriend);
			m_Array[i] = tempFriend;
			m_Array[i].DisplayRecordd();
		}
		cout << endl;
	}

};