#pragma once
#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
// friend 정보를 저장하는 클래스.
class FriendType
{
public:
	FriendType()
	{}
	~FriendType()
	{}
	//키보드로부터 ID를 받아오는 함수
	void SetIdFromKB()
	{
		cout << "ID : ";
		cin >> ID;
	}

	//키보드로부터 Name를 받아오는 함수
	void SetNameFromKB()
	{
		cout << "Name : ";
		cin >> name;
	}

	//파라미터에 있는 Tempname으로 name을 설정
	void SetName(string Tempname)
	{
		name = Tempname;
	}
	//파라미터에 있는 TempID로 ID를 설정
	void SetID(string TempId)
	{
		ID = TempId;
	}
	// private데이터 name에 접근하기 위한 함수.
	string GetName()
	{
		return name;
	}

	// private데이터 ID에 접근하기 위한 함수.
	string GetID()
	{
		return ID;
	}

	// 친구의 레코드를 출력해준다.
	void DisplayRecordd()
	{
		cout << "id : " << ID << endl;
		cout << "Name : " << name << endl;

	}
	FriendType &operator=(FriendType &ref); //링크드리스트사용을 위한 연산자 오버로딩.
	bool operator>(FriendType item); //링크드리스트사용을 위한 연산자 오버로딩.
	bool operator<(FriendType item);//링크드리스트사용을 위한 연산자 오버로딩.
	bool operator==(FriendType item);//링크드리스트사용을 위한 연산자 오버로딩.
private:
	string ID; //친구의 ID
	string name; //친구의 Name

};
