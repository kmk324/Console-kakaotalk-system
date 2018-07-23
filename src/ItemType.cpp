
#include "ItemType.h"
#include <string>

// Set user id from keyboard.
void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> m_Id;
}


// Set user name from keyboard.
void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}


// Set user address from keyboard.
void ItemType::SetAddressFromKB()
{
	cout << "\tPhoneAddress : ";
	cin >> m_sAddress;
}
// Set user Birth from Keyboard.
void ItemType::SetBirthFromKB()
{
	cout << "\tBirth : ";
	cin >> m_sBirth;
}
// Set user Gender from Keyboard.
void ItemType::SetGenderFromKB()
{
	cout << "\tGender : ";
	cin >> m_sGender;
}
// Set user StatusMemo from Keyboard.
void ItemType::SetStatusMemoFromKB()
{
	cout << "\tStatusMemo : ";
	cin >> m_sStatusMemo;
}
//	Set user Pw from Keyboard.
void ItemType::SetPwFromKB() // lab03���� �䱸�ϴ� Readpw�Լ�.
{
	cout << "\tPw : ";
	cin >> m_Pw;
}

// Set user BGP from Keyboard.
void ItemType::SetBGPFromKB()
{
	cout << "\tBGP : ";
	cin >> m_BGP;
}


// Set user record from keyboard.
void ItemType::SetRecordFromKB() // lab03���� �䱸�ϴ� readMemberInfo�Լ�.
{
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
	SetBirthFromKB();
	SetGenderFromKB();
	SetStatusMemoFromKB();
	SetPwFromKB();
	SetBGPFromKB();
}


// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sAddress;
	fin >> m_sBirth;
	fin >> m_sGender;
	fin >> m_sStatusMemo;
	fin >> m_Pw;
	fin >> m_BGP;

	return 1;
};


// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Id << " ";
	fout << m_sName << " ";
	fout << m_sAddress << " ";
	fout << m_sBirth << " ";
	fout << m_sGender << " ";
	fout << m_sStatusMemo << " ";
	fout << m_Pw << " ";
	fout << m_BGP;

	return 1;
}


// Compare two itemtypes.
RelationType ItemType::CompareByID(const ItemType &data)
{
	if (this->m_Id > data.m_Id)
		return GREATER;
	else if (this->m_Id < data.m_Id)
		return LESS;
	else
		return EQUAL;
}

// operator << set.
/*
ItemType &operator <<(ostream &os, ItemType &ref)
{
	cout << endl;
	ref.DisplayRecordOnScreen();

	return ref;
}
*/



// Compare two item types by item id.
bool ItemType::operator>(ItemType item)
{
	return (this->GetId()>item.GetId());
}	//return 1 if this.id > data.id, 0 if not.

bool ItemType::operator<(ItemType item)
{
	return (this->GetId()<item.GetId());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool ItemType::operator==(ItemType item)
{
	return (this->GetId() == item.GetId());
}	//return 1 if this.id == data.id, 0 if not.


	// �Ķ���� �޼����� ���ù��� �޼����� �����Ѵ�.
void ItemType::GenerateMessage(MessageType& message)
{
	message.SetReceiverFromKB();
	message.SetMessageFromKB();
}



//�Ķ������ �޼���Ÿ�Ժ��� message�� ȸ���� äƮ����Ʈ�� add���ش�.
void ItemType::AddMessageToChatList(MessageType message)
{
	chatList.Add(message);
}
void ItemType::AddFriendToFriendList(FriendType Friend)
{
	friendList.Add(Friend);
}

void ItemType::PrintGroupList()
{
	FriendGroup temp;
	friendGroupList.ResetList();
	for (int i = 0; i< friendGroupList.GetLength(); i++)
	{	
		friendGroupList.GetNextItem(temp);
		temp.PrintGroupFriendList();
	}
}

//ģ���׷쿡 ģ���߰�.
void ItemType::AddFriendToFriendGroupList()
{
	string TempGroupName;// �߰��� ģ�� �׷��� �̸�;
	cout << "�߰��� ģ�� �׷��� �̸��� �Է��ϼ��� : ";
	cin >> TempGroupName;
	FriendGroup* fg = new FriendGroup(TempGroupName);
	//ģ�� ��� ���.
	cout << "���� �׷쿡 �߰� ������ ������� ģ������Ʈ�� �Ʒ��� �����ϴ�. " << endl;
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
	//ģ�� ��� ���.

	while (1)
	{
		cout << "ģ���� �߰��ϴ� ���Դϴ�. �߰��� ���̵��Է��ϼ���. �׸� �ν÷��� 0�� �Է�.";
		string TempAddFriendID;
		cin >> TempAddFriendID;
		tempFriend.SetID(TempAddFriendID);
		if (friendList.Get(tempFriend) == 1)//1�̸� ã�� ����
		{
			fg->getGroupFriendList()->Add(tempFriend);
		}
		else
		{
			cout << "�׷� ģ���� �����ϴ�.";
		}
		if (TempAddFriendID == "0")
		{
			friendGroupList.Add(*fg);//�׷츮��Ʈ�� �߰�.
			delete fg; // �޸�����
			break;
		}
	}

}

//friendList���� �Ķ������ friend�� ������ ��ġ�ϴ� ģ���� ������ ����.
int ItemType::DeleteFriendFromFriendList(FriendType tempFriend)
{
	FriendType Fren;
	Fren = tempFriend;
	if (friendList.Get(Fren)) //frend����Ʈ�� ��ġ�ϴ� ���̵� �ִ��� Ȯ��.
	{
		friendList.Delete(Fren);
		return 1;
	}
		return 0;
}


// �Ķ������ �޼����� GenerateMessage�Լ��� ���������� AddMessageToChatList�Լ��� ȣ���Ͽ� �� �޼����� äƮ����Ʈ�� add���ش�.
MessageType ItemType::GetMessage(MessageType& message)
{
	GenerateMessage(message);
	AddMessageToChatList(message);
	return message;
}

//�α����� ȸ�����κ��� �׷�޼����� �����Ͽ� ������ ������.
void ItemType::GetGroupMessage(MessageType& message,MessageType * temp)
{
	//temp= new MessageType[MAXSIZE];
	string tempGroupname;
	PrintGroupList(); //�׷� ����Ʈ ���
	
	cout << "���� �׷��� �̸��� �Է��ϼ���" << endl;
	cin >> tempGroupname;
	FriendGroup Temp;
	friendGroupList.ResetList();
	for (int i = 0; i < friendGroupList.GetLength(); i++)
	{
		friendGroupList.GetNextItem(Temp);
		if (Temp.GetGroupname() == tempGroupname)
		{
			UnsortedLinkedList<FriendType>* TempGroupFriendList;
			TempGroupFriendList = Temp.getGroupFriendList(); // �ش��ϴ� �׷���� �׷�ģ������Ʈ�� �ҷ���.
			FriendType TempFriend;
			string TempFriendID;
			string MessageContents;
			int Count = 0;
			cout << "�׸� �Է��Ͻ÷��� -1�� �Է�" << endl;
			while (1)
			{
				cout << "Message : ";
				cin >> MessageContents;
				message.SetMessage(MessageContents);
				
				//message.SetMessageFromKB();
					if (message.GetMessage() == "-1")
					{
						break;
					}
			
				TempGroupFriendList->ResetList();
				for (int i = Count; i < Count+TempGroupFriendList->GetLength(); i++)
				{
					TempGroupFriendList->GetNextItem(TempFriend);
					TempFriendID = TempFriend.GetID();
					message.SetReceiver(TempFriendID);
					message.SetGroupNameInMessage(tempGroupname);
					AddMessageToChatList(message);
					temp[i] = message;
				}
				Count = Count+ 3;
			}
		}
		else
		{ }
	}
}
