#include "Application.h"
#include <string>

// server 단에서 사용할 멤버함수 목록들을 출력하고 커맨드를 받아서 해당하는 함수를 호출한다.
void Application::Server()
{
	while (1)
	{
		m_nCurCommand = GetCommandInServer();
		switch (m_nCurCommand)
		{
		case 1:SendMessageToClient(); //서버에 있는 메세지큐에서 dequeue해주며 Receiver에게 전달
			break;
		case 2: RetrieveItem(); //입력받은 회원 아이디를 토대로 회원정보 검색.
			break;
		case 3: DisplayAll(); // 서버에 등록된 모든 회원정보 출력.
			break;
		case 7: Update(); // 회원 정보를 갱신한다.
			break;
		case 8: MakeEmpty(); // 서버에 등록된 모든 회원 정보를 삭제한다.
			break;
		case 9: DeleteItem(); // 입력받은 회원 아이디를 토대로 검색된 회원의 정보를 삭제한다.
			break;
		case 10: TodayBirthdayMem(); //오늘이 생일인 회원의 정보를 출력한다.
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}

//client 단에서 사용할 멤버함수 목록들을 출력하고 커맨드를 받아서 해당하는 함수를 호출한다.
void Application::Client()
{
	if (LogonStateE == true)
	{
		while (1)
		{
			m_nCurCommand = GetCommandInClient();

			switch (m_nCurCommand)
			{
			case 1: GetMessageFromClient(); // CurrentMember를 자동적으로 sender로 설정해주며 클라이언트에게 메세지를 보낸다.
				break;
			case 2: PrintChatList(); // CurrentMember의 메세지를 출력한다.
				break;
			case 3: AddFriend(); // CurrentMember의 친구리스트에 새로운 친구 추가.
				break;
			case 4: DeleteFriend(); // CurrentMember의 친구리스트에서 입력된 ID에 해당하는 친구를 찾아서삭제.
				break;
			case 5: DisplayAllFriendList(); //CurrentMember의 친구리스트에 있는 모든 친구들의 정보를 출력해준다.
				break;
			case 6: RetrieveFriend(); // CurrentMember의 친구리스트에 있는 회원중 입력받은 아이디를 통해 찾아서 정보를 출력해준다.
				break;
			case 7:DeleteMessage(); // 메세지함을 비운다.
				break;
			case 8: AddFriendToFriendGroup(); //친구그룹을 추가한다. 친구목록에 있는 친구중 선택하여 친구그룹에 속하게 함.
				break;
			case 9:	PrintFriendGroupList(); // 친구그룹들의 정보를 출력한다.
				break;
			case 10: GetGroupMessageFromClient(); // 클라이언트로부터 그룹 메세지를 받는다.
				break;
			case 11: PrintGroupChatlist(); //친구 그룹목록을 키보드로 입력받아서 그룹채팅목록을 출력한다.
				break;
			case 12: RecommendFriend(); //친구 추천
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
		cout << "로그인 후 사용할 수 있는 기능입니다." << endl;
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
		case 1:		// 회원가입
			InsertItem();
			break;
		case 2:		// 로그인
			Login();
			break;
		case 3:		// 로그아웃
			Logout();
			break;
		case 4:		// server
			Server();
			break;
		case 5:		// client 명령어
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
// 서버단에서 실행할 수 있는 함수들의 목록을 출력해주고 커맨드를 받아온다.
int Application::GetCommandInServer()
{
	cout << "오늘 날짜 : " << GetToday();
	int command;
	cout << endl;
	cout << "\t---Server -- Command ----- " << endl;
	cout << "\t   1 : 서버에올라온 메세지목록 뿌리기" << endl;
	cout << "\t   2 : 아이디를 통해 회원정보 검색" << endl;
	cout << "\t   3 : 등록된 모든 회원 정보 출력" << endl;
	cout << "\t   7 : 등록된 회원 정보 수정" << endl;
	cout << "\t   8 : 등록된 모든 가입 정보 초기화" << endl;
	cout << "\t   9 : 회원 탈퇴 " << endl;
	cout << "\t   10: 오늘 생일인 회원 "<< endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}
// 클라이언트 단에서 실행할 수 있는 함수들의 목록을 출력해주고 커맨드를 받아온다.
int Application::GetCommandInClient()
{
	

	int command;
	cout << endl << endl;
	cout << CurrentMember->GetId()<<"로 로그인중...." << endl;
	cout << "\t---Client -- Command ----- " << endl;
	cout << "\t   1 : 로그인된 회원으로부터 1:1채팅 메세지 생성 후 서버에 보내기" << endl;
	cout << "\t   2 : 로그인된 회원의 메세지 리스트 확인" << endl;
	cout << "\t   3 : 로그인된 회원의 친구리스트 추가 " << endl;
	cout << "\t   4 : 로그인된 회원의 친구리스트 삭제 " << endl;
	cout << "\t   5 : 로그인된 회원의 친구리스트 출력 " << endl;
	cout << "\t   6 : 로그인된 회원의 아이디로 친구검색" << endl;
	cout << "\t   7 : 로그인된 회원의 메세지함 비우기" << endl;
	cout << "\t   8 : 로그인된 회원의 친구그룹리스트 추가" << endl;
	cout << "\t   9 : 로그인된 회원의 친구그룹리스트 출력" << endl;
	cout << "\t   10: 로그인된 회원으로부터 그룹채팅 생성 후 서버에 보내기" << endl;
	cout << "\t   11: 로그인된 회원의 그룹채팅 확인하기" << endl;
	cout << "\t   12: 로그인된 회원의 친구 추천" << endl;
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
	cout << "\t---초기 -- Command ----- " << endl;
	cout << "\t   1 : 회원가입" << endl;
	cout << "\t   2 : 로그인" << endl;
	cout << "\t   3 : 로그아웃" << endl;
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

	cout << "-------------회원가입------------- " << endl;
	item.SetRecordFromKB();	//추가할 정보를 입력한다.
	m_List.InsertItem(item);	//리스트에 항목을 추가한다.
	DisplayAll();	//리스트를 화면에 출력한다.
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
	item.SetIdFromKB();	//삭제할 항목의 id를 입력
	m_List.RetrieveItem(item, Found);
	if (Found)
	{
		m_List.DeleteItem(item);
		cout << "Deleted " << item.GetId() << " Successfully." << endl;
		return 1;
	}	//삭제에 성공하면 성공 메시지를 출력
	else
	{
		cout << item.GetId() << " is not found." << endl;
		return 0;
	}	//해당 항목을 찾을 수 없으면 찾지 못했다는 메시지를 출력
}


// Display all records in the list on screen.
void Application::DisplayAll()
{

	if (m_List.IsEmpty())
	{
		cout << "등록된 멤버가 없습니다." << endl;
	}
	else
	{
		cout << "\n\t현재 사용자리스트" << endl;
		m_List.PrintTree(cout);	// list의 모든 데이터를 화면에 출력
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
	item.SetIdFromKB();	//찾을 항목의 id를 입력
	m_List.RetrieveItem(item, Found);
	if (Found)
	{
		cout << item.GetId() << "에 해당하는 정보를 찾았습니다." << endl;
		item.DisplayRecordOnScreen();
		return 1;
	}
	else
	{
		cout << "해당하는 정보를 찾을 수 없었습니다." << endl;
		return 0;
	}

}

//Change item's value in the list.


int Application::Update()
{
	ItemType item;
	bool Found = false;
	cout << "업데이트 할 아이디를 입력하세요 : ";
	item.SetIdFromKB();	//정보를 수정할 항목의 id를 입력
	m_List.RetrieveItem(item, Found);
	if (Found != true)
	{
		cout << "해당하는 등록된 아이디가 없습니다." << endl;
		return 0;
	}	//해당 항목이 리스트에 없으면 찾지 못했다는 메시지 출력
	else
	{
		//입력받은 값들을 리스트에 반영
		m_List.DeleteItem(item);
		item.SetIdFromKB();
		item.SetNameFromKB();
		item.SetAddressFromKB();
		item.SetBGPFromKB();
		item.SetBirthFromKB();
		item.SetGenderFromKB();
		item.SetPwFromKB();
		item.SetStatusMemoFromKB();//나머지 정보 입력
		m_List.InsertItem(item);
		cout << "수정 완료" << endl;
	}
	return 1;
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
	{
		return 0;
	}
	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.InsertItem(data);
		if (data.GetBirth() == Today)
		{
			BirthMList.InsertItem(data);
		}
	}

	m_InFile.close();	// file close

						// 현재 list 출력
	DisplayAll();

	return 1;
}
//쓰기 필요할때 수정;
/*
// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
ItemType data;	// 쓰기용 임시 변수

char filename[FILENAMESIZE];
cout << "\n\tEnter Output file Name : ";
cin >> filename;

// file open, open error가 발생하면 0을 리턴
if (!OpenOutFile(filename))
return 0;

// list 포인터를 초기화


// list의 길이를 리턴받아 저장
int length = m_List.LengthIs();
ItemType *PTR;
// iteration을 이용하여 모든 item 출력
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
// 아이디와 패스워드를 입력하여 로그인한다. 일치하는 항목이있으면 LogonStateE변수를 true로 변환해준다.
//re
void Application::Login() {
	
	if (LogonStateE != true)
	{
		cout << "------------로그인------------- " << endl;

		ItemType tempitem;//임시용 데이터
		string LoginID, LoginPW;//임시용 변수
		bool Found = false;
		cout << "ID : ";
		cin >> LoginID;//id 받아오기
		cout << "PW :";
		cin >> LoginPW;//비밀번호 받아오기


		tempitem.SetId(LoginID);//임시용 객체에 ID값 넣기
		m_List.RetrieveItem(tempitem, Found);
		if (Found)//회원 링크드 리스트에 해당 Id값을 갖고 있는 노드가 있는지 검색
		{
			if (tempitem.GetPw() == LoginPW && tempitem.GetId() == LoginID)
			{//입력 받은 비밀번호 값과 ID값을 갖고 있는 객체가 있으면  
				bool Found = false;
				CurrentMember = m_List.RetrieveItem(tempitem, Found);//현재 로그인한 회원을 저장하는 멤버변수에 해당 노드의 데이터를 참조하는 주소값 전달
				cout << tempitem.GetId();
				cout << "로 로그인 되었습니다." << endl;
				LogonStateE = true;
				return;
			}
			else
			{
				cout << "비밀번호를 잘못 입력했습니다" << endl;
				return;
			}
		}
		else
		{//해당 ID값을 갖고 있는 고객을 찾지 못함
			cout << "해당 ID를 가진 회원이 없습니다." << endl;
			return;
		}
	}
	else
	{
		cout << "로그아웃을 먼저 하십시오." << endl;
	}
}
// 로그온상태이면 LogonStateE를 False로 변환시켜준다.
void Application::Logout()
{
	cout << "-------------로그아웃------------- " << endl;

	if (LogonStateE == true)
	{
		cout << "로그아웃 되었습니다." << endl;
		LogonStateE = false;
	}
	else
	{
		cout << "로그인된 회원의 정보가 없습니다." << endl;
	}
}

// 로그인한 회원이 메세지를 생성해서 본인의 채트리스트에 넣고, 현재 메시지큐에 인큐한다.
void Application::GetMessageFromClient()
{
	MessageType message;
	string tempID;
	tempID = CurrentMember->GetId();
	message.SetSender(tempID);
	CurrentMember->GetMessage(message);
	messageQ.EnQueue(message);
	
}//로그인한 회원이 메세지를 생성해서 본인의 채트리스트에 넣고, 현재 메시지큐에 인큐한다.

//유저로부터 그룹채팅메세지를 받는다.
void Application::GetGroupMessageFromClient()
{
	MessageType* Temp=new MessageType[100];
	MessageType message;
	string tempID;
	tempID = CurrentMember->GetId();
	message.SetSender(tempID);
			CurrentMember->GetGroupMessage(message, Temp); // 유저의 채트리스트에 그룹메세지를 넣어주고 그룹메세지배열리턴.
			int i = 0;
			while (Temp[i].GetSender() == CurrentMember->GetId())
			{
				messageQ.EnQueue(Temp[i]);
				i++;
			}

	
}

//현재 메시지큐에서 디큐하고 수신할 아이디를 찾아 그아이디의 채트리스트에 넣는다.
//메세지가 그룹단위로 왔을시 Receiver가 해당하는 그룹을 가지고있는지 확인하고, 가지고있지 않다면
//해당그룹을 recevier멤버의 프렌드그룹리스트에 add해준다.
void Application::SendMessageToClient()
{
	MessageType TempMessage;
	ItemType tempitem;
	string RecieverID;
	string SenderID;
	
	if (messageQ.IsEmpty())
	{
		cout << "서버에 보낼 메시지가 올라와 있지 않습니다." << endl;
	}

	while (!messageQ.IsEmpty()) //while로바꾸기.
	{
		//cout << "수신할 사람의 아이디를 입력하세요.";
		//cin >> RecieverID;
		//tempitem.SetId(RecieverID);
		bool Found = false;
		FriendGroup ForCopy;
		messageQ.DeQueue(TempMessage);
		if (TempMessage.GetGroupNameInMessage() != "1:1채팅")
		{//receiver에 친구 그룹 추가하기 위한 코드 ( 센더로부터 이번 메세지의 친구그룹정보 가져오기)
			bool FoundSender = false;
			SenderID = TempMessage.GetSender();
			tempitem.SetId(SenderID);
			ItemType* ForFriendGroupAdd;
			ForFriendGroupAdd = nullptr;
			ForFriendGroupAdd = m_List.RetrieveItem(tempitem, FoundSender); //포인터변수에 센더정보 대입.
			//여까진 괜춘한듯.//
			LinkedList<FriendGroup>* TempFriendGroupList;
			TempFriendGroupList = ForFriendGroupAdd->GetfriendGroupList();
			//여기까지도갠춘;
			FriendGroup TempFriendGroup;
			UnsortedLinkedList<FriendType>* TempFriendList;
			TempFriendGroupList->ResetList();
			for (int i = 0; i < TempFriendGroupList->GetLength(); i++)
			{
				TempFriendGroupList->GetNextItem(TempFriendGroup); //여기문제. 해결
				if (TempFriendGroup.GetGroupname() == TempMessage.GetGroupNameInMessage())
				{
					TempFriendList = TempFriendGroup.getGroupFriendList(); //그 그룹의 친구리스트를 가져옴
					FriendGroup TempCopy(TempMessage.GetGroupNameInMessage(), *TempFriendList);//sender에서 이번 메세지의 프렌드그룹 생성.
					ForCopy = TempCopy;
				}
			}
		}
			//receiver에 친구 그룹 추가하기 위한 코드( 센더로부터 이번 메세지의 친구그룹정보 가져오기)
		RecieverID = TempMessage.GetReciever(); 
		tempitem.SetId(RecieverID);
		ItemType* memberPtr;
		memberPtr = nullptr;
		memberPtr = m_List.RetrieveItem(tempitem, Found);
		if (Found==true) 
		{
			cout << "서버에서 ";
			cout << RecieverID << " 에게";
			cout << endl;
			TempMessage.DisplayMessageOnScreen();
			cout << "전송성공! " << endl<<endl;
			memberPtr->AddMessageToChatList(TempMessage);
			//////////////////////이 리시버에 이번 메세지의 그룹에 대한 정보가 없으면 추가.////
			if (TempMessage.GetGroupNameInMessage() != "1:1채팅")
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
						FoundGroupNameInReciever=true; //큰 while문이 아니라 for문에 걸리는 거겠지? -->yes
					}
				}
				if (FoundGroupNameInReciever == false)
				{
					memberPtr->addFriendGroupListByParam(ForCopy);
				}
			}
			//////////////////////이 리시버에 이번 메세지의 그룹에 대한 정보가 없으면 추가.////
		}
		else
		{
			cout << "그런 아이디는 없습니다." << endl;
		}
	}
	
}

//로그인한 멤버의 그룹채팅 리스트정보를 출력.
void Application::PrintGroupChatlist()
{
	string tempgroupname;
	cout << "현재 로그인한 유저의 그룹 리스트입니다." << endl;
	CurrentMember->PrintGroupList();
	cout << "확인하실 그룹채팅방명을 입력하세요" << endl;
	cin >> tempgroupname;
	CurrentMember->DisplayGroupChatListOnscreen(tempgroupname);
}

// CurrentMember(현재 로그인한 회원)의 채트리스트를 Display해준다.
void Application::PrintChatList()
{
	
	CurrentMember->DisplayChatListOnscreen();
}

//오늘의 mmdd를 리턴.
string Application :: currentToday()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%m%d", &tstruct);
	return buf;
}
//오늘이 생일인 회원정보 출력
void Application::TodayBirthdayMem()
{
	cout << "오늘 생일인 회원의 리스트 입니다." << endl;
	string S;
	BirthMList.PrintTree(cout);
	
}

// CurrentMember의 친구 리스트에 새로운친구정보를 입력받고 추가.
void Application::AddFriend()
{
	FriendType temp;
	ItemType Temp;
	string S;

	bool Found = false;
	cout << "추가할 친구의 아이디를 입력 : ";
	cin >> S;
	temp.SetID(S);
	//cout << "친구 닉네임 설정  ";
	//temp.SetNameFromKB();

	Temp.SetId(S);
	m_List.RetrieveItem(Temp, Found);
	
	if (Found) // 해당 아이디를 가진 유저가 멤버리스트에 있다면 추가.
	{
		if (CurrentMember->RetrieveFriendFrom2(temp)==1)
		{
			cout << "이미 친구목록에 있는 아이디입니다." << endl;
		}
		else
		{ 
		temp.SetName(Temp.GetName());
		CurrentMember->AddFriendToFriendList(temp);
		cout << "친구를 추가했습니다." << endl;
		}
	}
	else
	{
		cout << "해당 아이디가 멤버리스트에 없습니다." << endl;
	}
}

int Application::DeleteFriend()
{
	FriendType item;

	cout << "Delete item : ";
	item.SetIdFromKB();	//삭제할 항목의 id를 입력
	// 어플리케이션에서 지울 친구목록을 설정한다.
		if (CurrentMember->DeleteFriendFromFriendList(item)==1)
		{cout << "Deleted " << item.GetID() << " Successfully." << endl;
		return 1;
	}	//삭제에 성공하면 성공 메시지를 출력
	else
	{
		cout << item.GetID() << " is not found." << endl;
		return 0;
	}
}
// CurrentMember의 친구목록을 출력
void Application::DisplayAllFriendList()
{
	 CurrentMember->DisplayFriendListOnScreen();
}

// CurrentMember의 친구목록에서 입력받은 아이디 삭제.
void Application::DeleteMessage()
{
	CurrentMember->MessageDelete();
}

// CurrentMember의 친구목록에서 입력받은 아이디의 친구가 있는지 찾고, 정보 출력.
void Application::RetrieveFriend()
{
	FriendType Fren;
	cout << "Enter a Friend's ID for Serach: ";
	Fren.SetIdFromKB();
	CurrentMember->RetrieveFriendFrom(Fren);
		
}
//현재 로그인한 멤버의 프렌드그룹리스트에 프렌드그룹을 추가한다.
void Application::AddFriendToFriendGroup()
{
	CurrentMember->AddFriendToFriendGroupList();
}
//현재 로그인한 멤버의 프렌드그룹리스트의 정보를 출력한다.
void Application::PrintFriendGroupList()
{
	CurrentMember->PrintGroupList();
}

	
// 오늘날짜를 받아온다 MMDD
string Application::GetToday()
{
	return Today;
}

//오늘 생일인 회원이 로그인한 회원의 친구가 아니면 친구로 추천.
void Application::RecommendFriend()
{
	cout << "회원님의 친구를 추천합니다." << endl;
	ItemType TempItem;
	FriendType TempFriend;
	TempItem = BirthMList.GetRootPointer();//
	TempFriend.SetID(TempItem.GetId());
	TempFriend.SetName(TempItem.GetName());
	int FriendOrNot;
	FriendOrNot = CurrentMember->RetrieveFriendFrom2(TempFriend);
	// 찾으면 1 못 찾으면 0

	if (FriendOrNot == 0)
	{
		TempItem.DisplayRecordOnScreen();
	}
	else
	{
	}
}