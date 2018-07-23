#pragma once
#pragma once
#pragma once
/**
*	@brief	Typedef for Queue testing simply.
*/
#pragma once

#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "FriendType.h"
#include "CircularQueueType.h"
#include "MessageType.h"
#include "LinkedList.h"
#include "SortedList.h"
#include "UnsortedLinkedList.h"
#include "BST.h"
#include "FriendGroup.h"
//#include "ChatRoom.h"
using namespace std;


/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };


/**
*	item information class.
*/
class ItemType
{
public:
	/**
	*	default constructor.
	*/
	ItemType()
	{
		m_Id = -1;
		m_sName = "";
		m_sAddress = "";
		m_sBirth = "-1";
		m_sGender = "";
		m_sStatusMemo = "";
		m_Pw = -1;
		m_BGP = "";

	}

	/**
	*	destructor.
	*/
	~ItemType()
	{
	}

	/**
	*	@brief	Get user id.
	*	@pre	user id is set.
	*	@post	none.
	*	@return	user id.
	*/
	string GetId()
	{
		return m_Id;
	}

	/**
	*	@brief	Get user name.
	*	@pre	user name is set.
	*	@post	none.
	*	@return	user name.
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	Get user PhoneAddress.
	*	@pre	user PhoneAddress is set.
	*	@post	none.
	*	@return	user PhoneAddress.
	*/
	string GetAddress()
	{
		return m_sAddress;
	}

	/**
	*	@brief	Get user Birthday.
	*	@pre	user Birthday is set.
	*	@post	none.
	*	@return	user Birthday.
	*/
	string GetBirth()
	{
		return m_sBirth;
	}


	/**
	*	@brief	Get user Gender.
	*	@pre	user Gender is set.
	*	@post	none.
	*	@return	user Gender.
	*/
	string GetGender()
	{
		return m_sGender;
	}

	/**
	*	@brief	Get user StatusMemo.
	*	@pre	user StatusMemo is set.
	*	@post	none.
	*	@return	user StatusMemo.
	*/
	string GetStatusMemo()
	{
		return m_sStatusMemo;
	}

	/**
	*	@brief	Get user Pw.
	*	@pre	user Pw is set.
	*	@post	none.
	*	@return	user Pw.
	*/
	string GetPw()
	{
		return m_Pw;
	}

	/**
	*	@brief	Get user BGP.
	*	@pre	user BGP is set.
	*	@post	none.
	*	@return	user BackGroundPhotography.
	*/
	string GetBGP()
	{
		return m_BGP;
	}


	/**
	*	@brief	Set user id.
	*	@pre	none.
	*	@post	user id is set.
	*	@param	inId	user id.
	*/
	void SetId(string inId)
	{
		m_Id = inId;
	}

	/**
	*	@brief	Set user name.
	*	@pre	none.
	*	@post	user name is set.
	*	@param	inName	user name.
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	Set user address.
	*	@pre	none.
	*	@post	user address is set.
	*	@param	inAddress	user address.
	*/
	void SetAddress(string inAddress)
	{
		m_sAddress = inAddress;
	}

	/**
	*	@brief	Set user Birth.
	*	@pre	none.
	*	@post	user Birth is set.
	*	@param	inBirth	user Birth.
	*/
	void SetBirth(string inBirth)
	{
		m_sBirth = inBirth;
	}
	/**
	*	@brief	Set user Gender.
	*	@pre	none.
	*	@post	user Gender is set.
	*	@param	inGender	user Gender.
	*/
	void SetGender(string inGender)
	{
		m_sGender = inGender;
	}
	/**
	*	@brief	Set user StatusMemo.
	*	@pre	none.
	*	@post	user StatusMemo is set.
	*	@param	inStatusMemo	user StatusMemo.
	*/
	void SetStatusMemo(string inStatusMemo)
	{
		m_sStatusMemo = inStatusMemo;
	}

	/**
	*	@brief	Set user Pw.
	*	@pre	none.
	*	@post	user Pw is set.
	*	@param	inPw 	user Pw.
	*/
	void SetPw(string inPw)
	{
		m_Pw = inPw;
	}



	/**
	*	@brief	Set user BGP.
	*	@pre	none.
	*	@post	user BGP is set.
	*	@param	inBGP 	user BGP.
	*/
	void SetBGP(string inBGP)
	{
		m_BGP = inBGP;
	}

	/**
	*	@brief	Set user record.
	*	@pre	none.
	*	@post	user record is set.
	*	@param	inId	user id.
	*	@param	inName	user name.
	*	@param	inAddress	user address.
	*	@param	inBirth		user birth.
	*	@param	inGender	user	Gender.
	*	@param	inStatusMemo	user	StatusMemo.
	*	@param	inPw	user	Pw.
	*	@param	inBGP	user	BGP.
	*/
	void SetRecord(string inId, string inName, string inAddress, string inBirth, string inGender, string inStatusMemo, string inPw, string inBGP)
	{
		SetId(inId);
		SetName(inName);
		SetAddress(inAddress);
		SetBirth(inBirth);
		SetGender(inGender);
		SetStatusMemo(inStatusMemo);
		SetPw(inPw);
		SetBGP(inBGP);

	}

	/**
	*	@brief	Display user id on screen.
	*	@pre	user id is set.
	*	@post	user id is on screen.
	*/
	void DisplayIdOnScreen()
	{
		cout << "\tID   : " << m_Id << endl;
	};

	/**
	*	@brief	Display user name on screen.
	*	@pre	user name is set.
	*	@post	user name is on screen.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_sName << endl;
	};

	/**
	*	@brief	Display user address on screen.
	*	@pre	user address is set.
	*	@post	user address is on screen.
	*/
	void DisplayAddressOnScreen()
	{
		cout << "\tAddress : " << m_sAddress << endl;
	};
	/**
	*	@brief	Display user Birth on screen.
	*	@pre	user Birth is set.
	*	@post	user Birth is on screen.
	*/
	void DisplayBirthOnScreen()
	{
		cout << "\tBirth : " << m_sBirth << endl;
	};
	/**
	*	@brief	Display user Gender on screen.
	*	@pre	user Gender is set.
	*	@post	user Gender is on screen.
	*/
	void DisplayGenderOnScreen()
	{
		cout << "\tGender : " << m_sGender << endl;
	};
	/**
	*	@brief	Display user StatusMemo on screen.
	*	@pre	user StatusMemo is set.
	*	@post	user StatusMemo is on screen.
	*/
	void DisplayStatusMemoOnScreen()
	{
		cout << "\tStatusMemo : " << m_sStatusMemo << endl;
	};

	/**
	*	@brief	Display user Pw on screen.
	*	@pre	user Pw is set.
	*	@post	user Pw is on screen.
	*/
	void DisplayPwOnScreen()
	{
		cout << "\tPW : " << m_Pw << endl;
	}

	/**
	*	@brief	Display user BGP on screen.
	*	@pre	user BGP is set.
	*	@post	user BGP is on screen.
	*/
	void DisplayBGPOnScreen()
	{
		cout << "\tBGP : " << m_BGP << endl;
	}


	/**
	*	@brief	Display an user record on screen.
	*	@pre	user record is set.
	*	@post	user record is on screen.
	*/
	void DisplayRecordOnScreen()  // lab03���� �䱸�ϴ� displaymemberInfo �Լ�
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
		DisplayAddressOnScreen();
		DisplayBirthOnScreen();
		DisplayGenderOnScreen();
		DisplayStatusMemoOnScreen();
		DisplayPwOnScreen();
		DisplayBGPOnScreen();

	};

	/**
	*	@brief	Set user id from keyboard.
	*	@pre	none.
	*	@post	user id is set.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set user name from keyboard.
	*	@pre	none.
	*	@post	user name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set user address from keyboard.
	*	@pre	none.
	*	@post	user address is set.
	*/
	void SetAddressFromKB();

	/**
	*	@brief	Set user Birth from keyboard.
	*	@pre	none.
	*	@post	user Birth is set.
	*/
	void SetBirthFromKB();
	/**
	*	@brief	Set user Gender from keyboard.
	*	@pre	none.
	*	@post	user Gender is set.
	*/
	void SetGenderFromKB();
	/**
	*	@brief	Set user StatusMemo from keyboard.
	*	@pre	none.
	*	@post	user StatusMemo is set.
	*/
	void SetStatusMemoFromKB();

	/**
	*	@brief	Set user Pw from keyboard.
	*	@pre	none.
	*	@post	user Pw is set.
	*/
	void SetPwFromKB();

	/**
	*	@brief	Set user BGP from keyboard.
	*	@pre	none.
	*	@post	user BGP is set.
	*/
	void SetBGPFromKB();

	/**
	*	@brief	Set user record from keyboard.
	*	@pre	none.
	*	@post	user record is set.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	user record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new user record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByID(const ItemType &data);

	/**
	*	@brief operator << ����.
	*/
	friend ostream &operator<<(ostream &os, ItemType &ref)
	{
		os << "���̵� : " << ref.m_Id << endl;
		os << "�н����� : " << ref.m_Pw << endl;
		os << "�̸� : " << ref.m_sName << endl;
		os << "����" << ref.m_sGender << endl;
		os << "���¸� : " << ref.m_sStatusMemo << endl;
		os << "���� : " << ref.m_sBirth << endl;
		os << "���ȭ�� ��ġ : " << ref.m_BGP << endl;
		os << "�ڵ��� ��ȣ : " << ref.m_sAddress << endl;
		return os;
	}

	/**
	*	@brief operato = ����.
	*/
	ItemType &operator=(ItemType &ref)
	{
		m_Id = ref.GetId();
		m_BGP = ref.GetBGP();
		m_Pw = ref.GetPw();
		m_sAddress = ref.GetAddress();
		m_sBirth = ref.GetBirth();
		m_sName = ref.GetName();
		m_sStatusMemo = ref.GetStatusMemo();
		m_sGender = ref.GetGender();
		friendGroupList = ref.friendGroupList;
		friendList = ref.friendList;
		return *this;
	}

	/**
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.id > data.id, 0 if not.
	*/
	bool operator>(ItemType item);

	/**
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.id < data.id, 0 if not.
	*/
	bool operator < (ItemType item);

	/**
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@param	data	target item for comparing.
	*	@return	return 1 if this.id == data.id, 0 if not.
	*/
	bool operator==(ItemType item);

	/**
	*	@brief �Ķ���� �޼����� ���ù��� �޼����� �����Ѵ�.
	*	@pre �޼����� ������ ���õǾ� �־�� �Ѵ�.
	*	@param ���ù��� �޼����� ������ �� ��ȯ�� �޽���Ÿ�� ������ reference
	*/
	void GenerateMessage(MessageType& message);

	/**
	*	@brief ȸ���� äƮ����Ʈ�� �Ķ������ �޼����� add���ش�.
	*	@pre �޼����� ���õǾ� �־�� �Ѵ�.
	*	@param äƮ����Ʈ�� add�� �޼���.
	*/
	void AddMessageToChatList(MessageType message);

	/**
	*	@brief ȸ���� Friend����Ʈ�� �Ķ������ Friend�� add���ش�.
	*	@pre Friend�� ���õǾ� �־�� �Ѵ�.
	*	@param Friend����Ʈ�� add�� Friend.
	*/
	void AddFriendToFriendList(FriendType Friend);

	/**
	*	@brief ȸ���� Friend�׷츮��Ʈ�� Friend�� add���ش�.
	*/
	void AddFriendToFriendGroupList();

	//friendList���� �Ķ������ friend�� ������ ��ġ�ϴ� ģ���� ������ ����.
	int DeleteFriendFromFriendList(FriendType TempFriend);
	
	/**
	*	@brief	�Ķ������ �޼����� GenerateMessage�Լ��� ���������� AddMessageToChatList�Լ��� ȣ���Ͽ� �� �޼����� äƮ����Ʈ�� add���ش�.
	*	@pre	none.
	*	@param  GenerateMessage�Լ��� AddMessageToChatList�Լ��� �Ķ���Ϳ� ���� �޼���Ÿ���� message���۷���
	*/
	MessageType GetMessage(MessageType& message);


	/**
	*	@brief ȸ���� ������ �ִ� äƮ����Ʈ�� ���÷��� ���ش�.
	*/
	void DisplayChatListOnscreen()
	{
		MessageType m_Array[MAXSIZE];
		MessageType tempMessage;
		chatList.ResetList();
		
	for (int i = 0; i < chatList.GetLength(); i++)
	{
			chatList.GetNextItem(tempMessage);
			m_Array[i] = tempMessage;
			m_Array[i].DisplaySenderOnScreen();
			m_Array[i].DisplayReceiverOnScreen();
			m_Array[i].DisplayMessageOnScreen();
			m_Array[i].DisplayRealTimeOnScreen();
			m_Array[i].DisplayGroupNameOnScreen();
			cout << endl;
		}
	}

	//�Ķ���ͷ� ���� �׷��� �̸��� ���� �׷��� äƮ����Ʈ�� ���÷��� ���ش�.
	void DisplayGroupChatListOnscreen(string TempGroupName)
	{
		MessageType m_Array[MAXSIZE];
		MessageType tempMessage;
		chatList.ResetList();
		for (int i = 0; i < chatList.GetLength(); i++)
		{
			chatList.GetNextItem(tempMessage);
			m_Array[i] = tempMessage;
			if (m_Array[i].GetGroupNameInMessage() == TempGroupName)
			{
				if (i > 0)
				{
					if (m_Array[i].GetMessage() == m_Array[i - 1].GetMessage() && m_Array[i].GetSender() == m_Array[i - 1].GetSender() && m_Array[i].GetSendTime() == m_Array[i - 1].GetSendTime())
					{
					}
					else
					{
						cout << m_Array[i].GetSender() << " : " << m_Array[i].GetMessage() << " " << m_Array[i].GetSendTime() << endl;
					}
				}
				else
				{
					cout << m_Array[i].GetSender() << " : " << m_Array[i].GetMessage() << " " << m_Array[i].GetSendTime() << endl;
				}

			}
		}
	}

	//ȸ���� �������ִ� ģ������Ʈ ������ ������ش�.
	void DisplayFriendListOnScreen()
	{
		FriendType m_Array[MAXSIZE];
		FriendType tempFriend;
		friendList.ResetList();
		for (int i = 0; i < friendList.GetLength(); i++)
		{
			friendList.GetNextItem(tempFriend);
			m_Array[i] = tempFriend;
			m_Array[i].DisplayRecordd();
			cout << endl;
		}
	}

	//ȸ���� �������ִ� äƮ����Ʈ�� ����ش�.
	void MessageDelete()
	{
		chatList.MakeEmpty();
	}

	//ȸ���� ������ �ִ� ģ������Ʈ���� �Է¹��� ���̵� ã�Ƽ� ������ش�.
	void RetrieveFriendFrom(FriendType tempFriend)
	{
		string tempID;
		tempID = tempFriend.GetID();
		FriendType Fren;
		Fren = tempFriend;
		
	if (friendList.Get(Fren))
	{
		friendList.ResetList();
		for (int i = 0; i < friendList.GetLength(); i++)
		{
			friendList.GetNextItem(Fren);
			if (Fren.GetID() == tempID)
			{
				cout << "ã�ҽ��ϴ�. " << endl;
				Fren.DisplayRecordd();
			}
		}
	}
	else
	{
		cout << "ã�� ���߽��ϴ�. " << endl;
	}
	}


	//�ش� ģ���� ģ����Ͽ��� ã���� 1 ����, �ƴϸ� 0����
	int RetrieveFriendFrom2(FriendType tempFriend)
	{
		string tempID;
		tempID = tempFriend.GetID();
		FriendType Fren;
		Fren = tempFriend;

		if (friendList.Get(Fren))
		{
			friendList.ResetList();
			for (int i = 0; i < friendList.GetLength(); i++)
			{
				friendList.GetNextItem(Fren);
				if (Fren.GetID() == tempID)
				{
					return 1;
				}
			}
		}
		else
		{
			return 0;
		}
	}




	void PrintGroupList();// �׷츮��Ʈ������ ���

	//�׷����� ���� �޼����� �޾ƿ´�.
	void GetGroupMessage(MessageType& message,MessageType* Temp);
	
	//friendgrouplist�� �ּҰ��� �����´�.
	LinkedList<FriendGroup>* GetfriendGroupList()
	{
		return &friendGroupList;
	}
	
	//friendgroup te�� friendgroup�� add�Ѵ�.
	void addFriendGroupListByParam(FriendGroup te)
	{
		friendGroupList.Add(te);
	}
protected:

	string m_sName;		//< user name.
	string m_sAddress;	//< user PhoneAddress.
	string m_sBirth; 		//< user birthday MMDD.
	string m_sGender; 	//< user gender.
	string m_sStatusMemo;	//< user ProfileMessage.
	string m_Id; //< user ID.
	string m_Pw; // <user PW.
	string m_BGP; // <user BackGroundPhotography.
	LinkedList<FriendType> friendList; //ģ�� ���.
	LinkedList<FriendGroup> friendGroupList; // ģ�� �׷� ���.
	UnsortedLinkedList<MessageType>chatList; // ä�ø��.
	
};







#endif	// _ITEMTYPE_H
