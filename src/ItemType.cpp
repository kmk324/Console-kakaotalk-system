
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
void ItemType::SetPwFromKB() // lab03에서 요구하는 Readpw함수.
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
void ItemType::SetRecordFromKB() // lab03에서 요구하는 readMemberInfo함수.
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


	// 파라미터 메세지의 리시버와 메세지를 셋팅한다.
void ItemType::GenerateMessage(MessageType& message)
{
	message.SetReceiverFromKB();
	message.SetMessageFromKB();
}



//파라미터의 메세지타입변수 message를 회원의 채트리스트에 add해준다.
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

//친구그룹에 친구추가.
void ItemType::AddFriendToFriendGroupList()
{
	string TempGroupName;// 추가할 친구 그룹의 이름;
	cout << "추가할 친구 그룹의 이름을 입력하세요 : ";
	cin >> TempGroupName;
	FriendGroup* fg = new FriendGroup(TempGroupName);
	//친구 목록 출력.
	cout << "현재 그룹에 추가 가능한 사용자의 친구리스트는 아래와 같습니다. " << endl;
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
	//친구 목록 출력.

	while (1)
	{
		cout << "친구를 추가하는 중입니다. 추가할 아이디를입력하세요. 그만 두시려면 0을 입력.";
		string TempAddFriendID;
		cin >> TempAddFriendID;
		tempFriend.SetID(TempAddFriendID);
		if (friendList.Get(tempFriend) == 1)//1이면 찾음 ㄱㄱ
		{
			fg->getGroupFriendList()->Add(tempFriend);
		}
		else
		{
			cout << "그런 친구는 없습니다.";
		}
		if (TempAddFriendID == "0")
		{
			friendGroupList.Add(*fg);//그룹리스트에 추가.
			delete fg; // 메모리해제
			break;
		}
	}

}

//friendList에서 파라미터의 friend의 정보와 일치하는 친구가 있으면 삭제.
int ItemType::DeleteFriendFromFriendList(FriendType tempFriend)
{
	FriendType Fren;
	Fren = tempFriend;
	if (friendList.Get(Fren)) //frend리스트에 일치하는 아이디가 있는지 확인.
	{
		friendList.Delete(Fren);
		return 1;
	}
		return 0;
}


// 파라미터의 메세지를 GenerateMessage함수로 세팅해준후 AddMessageToChatList함수를 호출하여 그 메세지를 채트리스트에 add해준다.
MessageType ItemType::GetMessage(MessageType& message)
{
	GenerateMessage(message);
	AddMessageToChatList(message);
	return message;
}

//로그인한 회원으로부터 그룹메세지를 생성하여 서버에 보낸다.
void ItemType::GetGroupMessage(MessageType& message,MessageType * temp)
{
	//temp= new MessageType[MAXSIZE];
	string tempGroupname;
	PrintGroupList(); //그룹 리스트 출력
	
	cout << "보낼 그룹의 이름을 입력하세요" << endl;
	cin >> tempGroupname;
	FriendGroup Temp;
	friendGroupList.ResetList();
	for (int i = 0; i < friendGroupList.GetLength(); i++)
	{
		friendGroupList.GetNextItem(Temp);
		if (Temp.GetGroupname() == tempGroupname)
		{
			UnsortedLinkedList<FriendType>* TempGroupFriendList;
			TempGroupFriendList = Temp.getGroupFriendList(); // 해당하는 그룹명의 그룹친구리스트를 불러옴.
			FriendType TempFriend;
			string TempFriendID;
			string MessageContents;
			int Count = 0;
			cout << "그만 입력하시려면 -1을 입력" << endl;
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
