#pragma once
#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;
// friend ������ �����ϴ� Ŭ����.
class FriendType
{
public:
	FriendType()
	{}
	~FriendType()
	{}
	//Ű����κ��� ID�� �޾ƿ��� �Լ�
	void SetIdFromKB()
	{
		cout << "ID : ";
		cin >> ID;
	}

	//Ű����κ��� Name�� �޾ƿ��� �Լ�
	void SetNameFromKB()
	{
		cout << "Name : ";
		cin >> name;
	}

	//�Ķ���Ϳ� �ִ� Tempname���� name�� ����
	void SetName(string Tempname)
	{
		name = Tempname;
	}
	//�Ķ���Ϳ� �ִ� TempID�� ID�� ����
	void SetID(string TempId)
	{
		ID = TempId;
	}
	// private������ name�� �����ϱ� ���� �Լ�.
	string GetName()
	{
		return name;
	}

	// private������ ID�� �����ϱ� ���� �Լ�.
	string GetID()
	{
		return ID;
	}

	// ģ���� ���ڵ带 ������ش�.
	void DisplayRecordd()
	{
		cout << "id : " << ID << endl;
		cout << "Name : " << name << endl;

	}
	FriendType &operator=(FriendType &ref); //��ũ�帮��Ʈ����� ���� ������ �����ε�.
	bool operator>(FriendType item); //��ũ�帮��Ʈ����� ���� ������ �����ε�.
	bool operator<(FriendType item);//��ũ�帮��Ʈ����� ���� ������ �����ε�.
	bool operator==(FriendType item);//��ũ�帮��Ʈ����� ���� ������ �����ε�.
private:
	string ID; //ģ���� ID
	string name; //ģ���� Name

};
