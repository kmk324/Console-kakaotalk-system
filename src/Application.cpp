#include "Application.h"
#include <string>

// server �ܿ��� ����� ����Լ� ��ϵ��� ����ϰ� Ŀ�ǵ带 �޾Ƽ� �ش��ϴ� �Լ��� ȣ���Ѵ�.
void Application::Server()
{
	while (1)
	{
		m_nCurCommand = GetCommandInServer();
		switch (m_nCurCommand)
		{
		case 1:SendMessageToClient(); //������ �ִ� �޼���ť���� dequeue���ָ� Receiver���� ����
			break;
		case 2: RetrieveItem(); //�Է¹��� ȸ�� ���̵� ���� ȸ������ �˻�.
			break;
		case 3: DisplayAll(); // ������ ��ϵ� ��� ȸ������ ���.
			break;
		case 7: Update(); // ȸ�� ������ �����Ѵ�.
			break;
		case 8: MakeEmpty(); // ������ ��ϵ� ��� ȸ�� ������ �����Ѵ�.
			break;
		case 9: DeleteItem(); // �Է¹��� ȸ�� ���̵� ���� �˻��� ȸ���� ������ �����Ѵ�.
			break;
		case 10: TodayBirthdayMem(); //������ ������ ȸ���� ������ ����Ѵ�.
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}

//client �ܿ��� ����� ����Լ� ��ϵ��� ����ϰ� Ŀ�ǵ带 �޾Ƽ� �ش��ϴ� �Լ��� ȣ���Ѵ�.
void Application::Client()
{
	if (LogonStateE == true)
	{
		while (1)
		{
			m_nCurCommand = GetCommandInClient();

			switch (m_nCurCommand)
			{
			case 1: GetMessageFromClient(); // CurrentMember�� �ڵ������� sender�� �������ָ� Ŭ���̾�Ʈ���� �޼����� ������.
				break;
			case 2: PrintChatList(); // CurrentMember�� �޼����� ����Ѵ�.
				break;
			case 3: AddFriend(); // CurrentMember�� ģ������Ʈ�� ���ο� ģ�� �߰�.
				break;
			case 4: DeleteFriend(); // CurrentMember�� ģ������Ʈ���� �Էµ� ID�� �ش��ϴ� ģ���� ã�Ƽ�����.
				break;
			case 5: DisplayAllFriendList(); //CurrentMember�� ģ������Ʈ�� �ִ� ��� ģ������ ������ ������ش�.
				break;
			case 6: RetrieveFriend(); // CurrentMember�� ģ������Ʈ�� �ִ� ȸ���� �Է¹��� ���̵� ���� ã�Ƽ� ������ ������ش�.
				break;
			case 7:DeleteMessage(); // �޼������� ����.
				break;
			case 8: AddFriendToFriendGroup(); //ģ���׷��� �߰��Ѵ�. ģ����Ͽ� �ִ� ģ���� �����Ͽ� ģ���׷쿡 ���ϰ� ��.
				break;
			case 9:	PrintFriendGroupList(); // ģ���׷���� ������ ����Ѵ�.
				break;
			case 10: GetGroupMessageFromClient(); // Ŭ���̾�Ʈ�κ��� �׷� �޼����� �޴´�.
				break;
			case 11: PrintGroupChatlist(); //ģ�� �׷����� Ű����� �Է¹޾Ƽ� �׷�ä�ø���� ����Ѵ�.
				break;
			case 12: RecommendFriend(); //ģ�� ��õ
				break;
			case 0:	// quit
				return;
			default:
				cout << "\tIllegal sellection...\n";
				break;
			}
		}
	}
	else
	{
		cout << "�α��� �� ����� �� �ִ� ����Դϴ�." << endl;
	}
}

// Program driver.
void Application::Run()
{
	while (1)
	{
		
		m_nCurCommand = GetCommand();


switch (m_nCurCommand)
		{
		case 1:		// ȸ������
			InsertItem();
			break;
		case 2:		// �α���
			Login();
			break;
		case 3:		// �α׾ƿ�
			Logout();
			break;
		case 4:		// server
			Server();
			break;
		case 5:		// client ��ɾ�
			Client();
			break;
		case 6:		// get data from data file
			ReadDataFromFile();
			break;
		case 7:		// put data to data file
			//WriteDataToFile();
			break;
		case 0:	// quit
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}
// �����ܿ��� ������ �� �ִ� �Լ����� ����� ������ְ� Ŀ�ǵ带 �޾ƿ´�.
int Application::GetCommandInServer()
{
	cout << "���� ��¥ : " << GetToday();
	int command;
	cout << endl;
	cout << "\t---Server -- Command ----- " << endl;
	cout << "\t   1 : �������ö�� �޼������ �Ѹ���" << endl;
	cout << "\t   2 : ���̵� ���� ȸ������ �˻�" << endl;
	cout << "\t   3 : ��ϵ� ��� ȸ�� ���� ���" << endl;
	cout << "\t   7 : ��ϵ� ȸ�� ���� ����" << endl;
	cout << "\t   8 : ��ϵ� ��� ���� ���� �ʱ�ȭ" << endl;
	cout << "\t   9 : ȸ�� Ż�� " << endl;
	cout << "\t   10: ���� ������ ȸ�� "<< endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}
// Ŭ���̾�Ʈ �ܿ��� ������ �� �ִ� �Լ����� ����� ������ְ� Ŀ�ǵ带 �޾ƿ´�.
int Application::GetCommandInClient()
{
	

	int command;
	cout << endl << endl;
	cout << CurrentMember->GetId()<<"�� �α�����...." << endl;
	cout << "\t---Client -- Command ----- " << endl;
	cout << "\t   1 : �α��ε� ȸ�����κ��� 1:1ä�� �޼��� ���� �� ������ ������" << endl;
	cout << "\t   2 : �α��ε� ȸ���� �޼��� ����Ʈ Ȯ��" << endl;
	cout << "\t   3 : �α��ε� ȸ���� ģ������Ʈ �߰� " << endl;
	cout << "\t   4 : �α��ε� ȸ���� ģ������Ʈ ���� " << endl;
	cout << "\t   5 : �α��ε� ȸ���� ģ������Ʈ ��� " << endl;
	cout << "\t   6 : �α��ε� ȸ���� ���̵�� ģ���˻�" << endl;
	cout << "\t   7 : �α��ε� ȸ���� �޼����� ����" << endl;
	cout << "\t   8 : �α��ε� ȸ���� ģ���׷츮��Ʈ �߰�" << endl;
	cout << "\t   9 : �α��ε� ȸ���� ģ���׷츮��Ʈ ���" << endl;
	cout << "\t   10: �α��ε� ȸ�����κ��� �׷�ä�� ���� �� ������ ������" << endl;
	cout << "\t   11: �α��ε� ȸ���� �׷�ä�� Ȯ���ϱ�" << endl;
	cout << "\t   12: �α��ε� ȸ���� ģ�� ��õ" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}



// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---�ʱ� -- Command ----- " << endl;
	cout << "\t   1 : ȸ������" << endl;
	cout << "\t   2 : �α���" << endl;
	cout << "\t   3 : �α׾ƿ�" << endl;
	cout << "\t   4 : Server " << endl;
	cout << "\t   5 : Client " << endl;
	cout << "\t   6 : Get from file" << endl;
	cout << "\t   7 : Put to file" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}



// Add new record into list.
int Application::InsertItem()
{
	ItemType item;

	cout << "-------------ȸ������------------- " << endl;
	item.SetRecordFromKB();	//�߰��� ������ �Է��Ѵ�.
	m_List.InsertItem(item);	//����Ʈ�� �׸��� �߰��Ѵ�.
	DisplayAll();	//����Ʈ�� ȭ�鿡 ����Ѵ�.
	if (item.GetBirth() == Today)
	{
		BirthMList.InsertItem(item);
	}
	return 1;
}

//Delete record into list.
int Application::DeleteItem()
{
	ItemType item;
	bool Found = false;
	cout << "Delete item : ";
	item.SetIdFromKB();	//������ �׸��� id�� �Է�
	m_List.RetrieveItem(item, Found);
	if (Found)
	{
		m_List.DeleteItem(item);
		cout << "Deleted " << item.GetId() << " Successfully." << endl;
		return 1;
	}	//������ �����ϸ� ���� �޽����� ���
	else
	{
		cout << item.GetId() << " is not found." << endl;
		return 0;
	}	//�ش� �׸��� ã�� �� ������ ã�� ���ߴٴ� �޽����� ���
}


// Display all records in the list on screen.
void Application::DisplayAll()
{

	if (m_List.IsEmpty())
	{
		cout << "��ϵ� ����� �����ϴ�." << endl;
	}
	else
	{
		cout << "\n\t���� ����ڸ���Ʈ" << endl;
		m_List.PrintTree(cout);	// list�� ��� �����͸� ȭ�鿡 ���
	}					
	
}

//Make empty list.
int Application::MakeEmpty()
{
	m_List.MakeEmpty();
	cout << "List is now empty.";
	return 0;
}


// Retrieve item in the list.
int Application::RetrieveItem()
{
	ItemType item;
	bool Found = false;
	cout << "Enter a item's ID for search : ";
	item.SetIdFromKB();	//ã�� �׸��� id�� �Է�
	m_List.RetrieveItem(item, Found);
	if (Found)
	{
		cout << item.GetId() << "�� �ش��ϴ� ������ ã�ҽ��ϴ�." << endl;
		item.DisplayRecordOnScreen();
		return 1;
	}
	else
	{
		cout << "�ش��ϴ� ������ ã�� �� �������ϴ�." << endl;
		return 0;
	}

}

//Change item's value in the list.


int Application::Update()
{
	ItemType item;
	bool Found = false;
	cout << "������Ʈ �� ���̵� �Է��ϼ��� : ";
	item.SetIdFromKB();	//������ ������ �׸��� id�� �Է�
	m_List.RetrieveItem(item, Found);
	if (Found != true)
	{
		cout << "�ش��ϴ� ��ϵ� ���̵� �����ϴ�." << endl;
		return 0;
	}	//�ش� �׸��� ����Ʈ�� ������ ã�� ���ߴٴ� �޽��� ���
	else
	{
		//�Է¹��� ������ ����Ʈ�� �ݿ�
		m_List.DeleteItem(item);
		item.SetIdFromKB();
		item.SetNameFromKB();
		item.SetAddressFromKB();
		item.SetBGPFromKB();
		item.SetBirthFromKB();
		item.SetGenderFromKB();
		item.SetPwFromKB();
		item.SetStatusMemoFromKB();//������ ���� �Է�
		m_List.InsertItem(item);
		cout << "���� �Ϸ�" << endl;
	}
	return 1;
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
	{
		return 0;
	}
	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.InsertItem(data);
		if (data.GetBirth() == Today)
		{
			BirthMList.InsertItem(data);
		}
	}

	m_InFile.close();	// file close

						// ���� list ���
	DisplayAll();

	return 1;
}
//���� �ʿ��Ҷ� ����;
/*
// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
ItemType data;	// ����� �ӽ� ����

char filename[FILENAMESIZE];
cout << "\n\tEnter Output file Name : ";
cin >> filename;

// file open, open error�� �߻��ϸ� 0�� ����
if (!OpenOutFile(filename))
return 0;

// list �����͸� �ʱ�ȭ


// list�� ���̸� ���Ϲ޾� ����
int length = m_List.LengthIs();
ItemType *PTR;
// iteration�� �̿��Ͽ� ��� item ���
for (int i = 0; i<length; i++)
{
PTR = m_List.GetRootPointer();
data.WriteDataToFile(m_OutFile);
if (i != length - 1)
m_OutFile << endl;
}

m_OutFile.close();	// file close

return 1;
}
*/
// ���̵�� �н����带 �Է��Ͽ� �α����Ѵ�. ��ġ�ϴ� �׸��������� LogonStateE������ true�� ��ȯ���ش�.
//re
void Application::Login() {
	
	if (LogonStateE != true)
	{
		cout << "------------�α���------------- " << endl;

		ItemType tempitem;//�ӽÿ� ������
		string LoginID, LoginPW;//�ӽÿ� ����
		bool Found = false;
		cout << "ID : ";
		cin >> LoginID;//id �޾ƿ���
		cout << "PW :";
		cin >> LoginPW;//��й�ȣ �޾ƿ���


		tempitem.SetId(LoginID);//�ӽÿ� ��ü�� ID�� �ֱ�
		m_List.RetrieveItem(tempitem, Found);
		if (Found)//ȸ�� ��ũ�� ����Ʈ�� �ش� Id���� ���� �ִ� ��尡 �ִ��� �˻�
		{
			if (tempitem.GetPw() == LoginPW && tempitem.GetId() == LoginID)
			{//�Է� ���� ��й�ȣ ���� ID���� ���� �ִ� ��ü�� ������  
				bool Found = false;
				CurrentMember = m_List.RetrieveItem(tempitem, Found);//���� �α����� ȸ���� �����ϴ� ��������� �ش� ����� �����͸� �����ϴ� �ּҰ� ����
				cout << tempitem.GetId();
				cout << "�� �α��� �Ǿ����ϴ�." << endl;
				LogonStateE = true;
				return;
			}
			else
			{
				cout << "��й�ȣ�� �߸� �Է��߽��ϴ�" << endl;
				return;
			}
		}
		else
		{//�ش� ID���� ���� �ִ� ���� ã�� ����
			cout << "�ش� ID�� ���� ȸ���� �����ϴ�." << endl;
			return;
		}
	}
	else
	{
		cout << "�α׾ƿ��� ���� �Ͻʽÿ�." << endl;
	}
}
// �α׿»����̸� LogonStateE�� False�� ��ȯ�����ش�.
void Application::Logout()
{
	cout << "-------------�α׾ƿ�------------- " << endl;

	if (LogonStateE == true)
	{
		cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
		LogonStateE = false;
	}
	else
	{
		cout << "�α��ε� ȸ���� ������ �����ϴ�." << endl;
	}
}

// �α����� ȸ���� �޼����� �����ؼ� ������ äƮ����Ʈ�� �ְ�, ���� �޽���ť�� ��ť�Ѵ�.
void Application::GetMessageFromClient()
{
	MessageType message;
	string tempID;
	tempID = CurrentMember->GetId();
	message.SetSender(tempID);
	CurrentMember->GetMessage(message);
	messageQ.EnQueue(message);
	
}//�α����� ȸ���� �޼����� �����ؼ� ������ äƮ����Ʈ�� �ְ�, ���� �޽���ť�� ��ť�Ѵ�.

//�����κ��� �׷�ä�ø޼����� �޴´�.
void Application::GetGroupMessageFromClient()
{
	MessageType* Temp=new MessageType[100];
	MessageType message;
	string tempID;
	tempID = CurrentMember->GetId();
	message.SetSender(tempID);
			CurrentMember->GetGroupMessage(message, Temp); // ������ äƮ����Ʈ�� �׷�޼����� �־��ְ� �׷�޼����迭����.
			int i = 0;
			while (Temp[i].GetSender() == CurrentMember->GetId())
			{
				messageQ.EnQueue(Temp[i]);
				i++;
			}

	
}

//���� �޽���ť���� ��ť�ϰ� ������ ���̵� ã�� �׾��̵��� äƮ����Ʈ�� �ִ´�.
//�޼����� �׷������ ������ Receiver�� �ش��ϴ� �׷��� �������ִ��� Ȯ���ϰ�, ���������� �ʴٸ�
//�ش�׷��� recevier����� ������׷츮��Ʈ�� add���ش�.
void Application::SendMessageToClient()
{
	MessageType TempMessage;
	ItemType tempitem;
	string RecieverID;
	string SenderID;
	
	if (messageQ.IsEmpty())
	{
		cout << "������ ���� �޽����� �ö�� ���� �ʽ��ϴ�." << endl;
	}

	while (!messageQ.IsEmpty()) //while�ιٲٱ�.
	{
		//cout << "������ ����� ���̵� �Է��ϼ���.";
		//cin >> RecieverID;
		//tempitem.SetId(RecieverID);
		bool Found = false;
		FriendGroup ForCopy;
		messageQ.DeQueue(TempMessage);
		if (TempMessage.GetGroupNameInMessage() != "1:1ä��")
		{//receiver�� ģ�� �׷� �߰��ϱ� ���� �ڵ� ( �����κ��� �̹� �޼����� ģ���׷����� ��������)
			bool FoundSender = false;
			SenderID = TempMessage.GetSender();
			tempitem.SetId(SenderID);
			ItemType* ForFriendGroupAdd;
			ForFriendGroupAdd = nullptr;
			ForFriendGroupAdd = m_List.RetrieveItem(tempitem, FoundSender); //�����ͺ����� �������� ����.
			//������ �����ѵ�.//
			LinkedList<FriendGroup>* TempFriendGroupList;
			TempFriendGroupList = ForFriendGroupAdd->GetfriendGroupList();
			//�������������;
			FriendGroup TempFriendGroup;
			UnsortedLinkedList<FriendType>* TempFriendList;
			TempFriendGroupList->ResetList();
			for (int i = 0; i < TempFriendGroupList->GetLength(); i++)
			{
				TempFriendGroupList->GetNextItem(TempFriendGroup); //���⹮��. �ذ�
				if (TempFriendGroup.GetGroupname() == TempMessage.GetGroupNameInMessage())
				{
					TempFriendList = TempFriendGroup.getGroupFriendList(); //�� �׷��� ģ������Ʈ�� ������
					FriendGroup TempCopy(TempMessage.GetGroupNameInMessage(), *TempFriendList);//sender���� �̹� �޼����� ������׷� ����.
					ForCopy = TempCopy;
				}
			}
		}
			//receiver�� ģ�� �׷� �߰��ϱ� ���� �ڵ�( �����κ��� �̹� �޼����� ģ���׷����� ��������)
		RecieverID = TempMessage.GetReciever(); 
		tempitem.SetId(RecieverID);
		ItemType* memberPtr;
		memberPtr = nullptr;
		memberPtr = m_List.RetrieveItem(tempitem, Found);
		if (Found==true) 
		{
			cout << "�������� ";
			cout << RecieverID << " ����";
			cout << endl;
			TempMessage.DisplayMessageOnScreen();
			cout << "���ۼ���! " << endl<<endl;
			memberPtr->AddMessageToChatList(TempMessage);
			//////////////////////�� ���ù��� �̹� �޼����� �׷쿡 ���� ������ ������ �߰�.////
			if (TempMessage.GetGroupNameInMessage() != "1:1ä��")
			{
				bool FoundGroupNameInReciever=false;
				LinkedList<FriendGroup>*TempTemp;
				TempTemp=memberPtr->GetfriendGroupList();
				TempTemp->ResetList();
				FriendGroup reTemp;
				for (int i = 0; i < TempTemp->GetLength(); i++)
				{
					TempTemp->GetNextItem(reTemp);
					if (reTemp.GetGroupname() == TempMessage.GetGroupNameInMessage())
					{
						FoundGroupNameInReciever=true; //ū while���� �ƴ϶� for���� �ɸ��� �Ű���? -->yes
					}
				}
				if (FoundGroupNameInReciever == false)
				{
					memberPtr->addFriendGroupListByParam(ForCopy);
				}
			}
			//////////////////////�� ���ù��� �̹� �޼����� �׷쿡 ���� ������ ������ �߰�.////
		}
		else
		{
			cout << "�׷� ���̵�� �����ϴ�." << endl;
		}
	}
	
}

//�α����� ����� �׷�ä�� ����Ʈ������ ���.
void Application::PrintGroupChatlist()
{
	string tempgroupname;
	cout << "���� �α����� ������ �׷� ����Ʈ�Դϴ�." << endl;
	CurrentMember->PrintGroupList();
	cout << "Ȯ���Ͻ� �׷�ä�ù���� �Է��ϼ���" << endl;
	cin >> tempgroupname;
	CurrentMember->DisplayGroupChatListOnscreen(tempgroupname);
}

// CurrentMember(���� �α����� ȸ��)�� äƮ����Ʈ�� Display���ش�.
void Application::PrintChatList()
{
	
	CurrentMember->DisplayChatListOnscreen();
}

//������ mmdd�� ����.
string Application :: currentToday()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%m%d", &tstruct);
	return buf;
}
//������ ������ ȸ������ ���
void Application::TodayBirthdayMem()
{
	cout << "���� ������ ȸ���� ����Ʈ �Դϴ�." << endl;
	string S;
	BirthMList.PrintTree(cout);
	
}

// CurrentMember�� ģ�� ����Ʈ�� ���ο�ģ�������� �Է¹ް� �߰�.
void Application::AddFriend()
{
	FriendType temp;
	ItemType Temp;
	string S;

	bool Found = false;
	cout << "�߰��� ģ���� ���̵� �Է� : ";
	cin >> S;
	temp.SetID(S);
	//cout << "ģ�� �г��� ����  ";
	//temp.SetNameFromKB();

	Temp.SetId(S);
	m_List.RetrieveItem(Temp, Found);
	
	if (Found) // �ش� ���̵� ���� ������ �������Ʈ�� �ִٸ� �߰�.
	{
		if (CurrentMember->RetrieveFriendFrom2(temp)==1)
		{
			cout << "�̹� ģ����Ͽ� �ִ� ���̵��Դϴ�." << endl;
		}
		else
		{ 
		temp.SetName(Temp.GetName());
		CurrentMember->AddFriendToFriendList(temp);
		cout << "ģ���� �߰��߽��ϴ�." << endl;
		}
	}
	else
	{
		cout << "�ش� ���̵� �������Ʈ�� �����ϴ�." << endl;
	}
}

int Application::DeleteFriend()
{
	FriendType item;

	cout << "Delete item : ";
	item.SetIdFromKB();	//������ �׸��� id�� �Է�
	// ���ø����̼ǿ��� ���� ģ������� �����Ѵ�.
		if (CurrentMember->DeleteFriendFromFriendList(item)==1)
		{cout << "Deleted " << item.GetID() << " Successfully." << endl;
		return 1;
	}	//������ �����ϸ� ���� �޽����� ���
	else
	{
		cout << item.GetID() << " is not found." << endl;
		return 0;
	}
}
// CurrentMember�� ģ������� ���
void Application::DisplayAllFriendList()
{
	 CurrentMember->DisplayFriendListOnScreen();
}

// CurrentMember�� ģ����Ͽ��� �Է¹��� ���̵� ����.
void Application::DeleteMessage()
{
	CurrentMember->MessageDelete();
}

// CurrentMember�� ģ����Ͽ��� �Է¹��� ���̵��� ģ���� �ִ��� ã��, ���� ���.
void Application::RetrieveFriend()
{
	FriendType Fren;
	cout << "Enter a Friend's ID for Serach: ";
	Fren.SetIdFromKB();
	CurrentMember->RetrieveFriendFrom(Fren);
		
}
//���� �α����� ����� ������׷츮��Ʈ�� ������׷��� �߰��Ѵ�.
void Application::AddFriendToFriendGroup()
{
	CurrentMember->AddFriendToFriendGroupList();
}
//���� �α����� ����� ������׷츮��Ʈ�� ������ ����Ѵ�.
void Application::PrintFriendGroupList()
{
	CurrentMember->PrintGroupList();
}

	
// ���ó�¥�� �޾ƿ´� MMDD
string Application::GetToday()
{
	return Today;
}

//���� ������ ȸ���� �α����� ȸ���� ģ���� �ƴϸ� ģ���� ��õ.
void Application::RecommendFriend()
{
	cout << "ȸ������ ģ���� ��õ�մϴ�." << endl;
	ItemType TempItem;
	FriendType TempFriend;
	TempItem = BirthMList.GetRootPointer();//
	TempFriend.SetID(TempItem.GetId());
	TempFriend.SetName(TempItem.GetName());
	int FriendOrNot;
	FriendOrNot = CurrentMember->RetrieveFriendFrom2(TempFriend);
	// ã���� 1 �� ã���� 0

	if (FriendOrNot == 0)
	{
		TempItem.DisplayRecordOnScreen();
	}
	else
	{
	}
}