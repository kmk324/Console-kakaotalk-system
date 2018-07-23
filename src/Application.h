#pragma once
#pragma once
#ifndef _APPLICATION_H
#define _APPLICATION_H


#include <iostream>
using namespace std;

#include "ItemType.h"


#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		
		m_nCurCommand = 0;
		LogonStateE = false;
		Today = currentToday();
	}

	

	/**
	*	destructor.
	*/
	~Application()
	{

	}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	string currentToday();
	string GetToday();


	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int InsertItem();

	/**
	*	@brief	Delete record into list.
	*	@pre	list should be not empty.
	*	@post	record is deleted into the list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int DeleteItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAll();

	/**
	*	@brief	Make empty list.
	*	@pre	none.
	*	@post	Make empty list in this member.
	*/
	int MakeEmpty();

	/**
	*	@brief	Retrieve item in the list.
	*	@pre	none.
	*	@post	none.
	*	@return	1 if the target item is exist in the list, otherwise 0.
	*/
	int RetrieveItem();

	/**
	*	@brief	Change item's value in the list.
	*	@pre	none.
	*	@post	target item's value is changed.
	*	@return	1 if succeeded changing item's value, otherwise 0.
	*/
	int Update();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	아이디와 패스워드를 입력하여 로그인한다. 일치하는 항목이있으면 LogonStateE변수를 true로 변환해준다.
	*	@post	일치하는 항목이 있으면 LogonStateE를 true로 반환시켜준다.
	*/
	void Login();

	/**
	*	@brief	로그온상태이면 LogonStateE를 False로 변환시켜준다.
	*	@post	로그온상태이면 LogonStateE를 False로 변환시켜준다.
	*/
	void Logout();

	/*
	*	@brief	로그인한 회원이 메세지를 생성해서 본인의 채트리스트에 넣고, 현재 메시지큐에 인큐한다.
	*	@post	생성한 메세지를 messageQ에 Enqueue한다.
	*/
	void GetMessageFromClient();

	/*
	*	@breif	현재 메시지큐에서 디큐하고 수신할 아이디를 찾아 그아이디의 채트리스트에 넣는다
	*	@post	수신할 아이디가 있으면 messageQ에서 Dequeue한 메세지를 수신할 아이디의 채트리스트에 add한다./없으면 "그런 아이디는 없습니다." 출력.
	*/
	void SendMessageToClient();

	/*
	*	@brief	client 단에서 사용할 멤버함수 목록들을 출력하고 커맨드를 받아서 해당하는 함수를 호출한다.
	*	@pre	LogonStateE가 True이어야 한다.
	*	@post	커맨드가 0이 아니면 while문을 계속 반복한다. 0이면 클라이언트 함수에서 나옴.
	*/
	void Client();

	/*
	*	@brief server 단에서 사용할 멤버함수 목록들을 출력하고 커맨드를 받아서 해당하는 함수를 호출한다.
	*	@pre none.
	*	@post 커맨드가 0이 아니면 while문을 계속 반복한다. 0이면 클라이언트 함수에서 나옴.
	*/
	void Server();

	/**
	*	@brief CurrentMember(현재 로그인한 회원)의 채트리스트를 Display해준다.
	*	@pre CurrentMember should be set.
	*	@post none
	*/
	void PrintChatList();

	/**
	*	@brief	서버단에서 실행할 수 있는 함수들의 목록을 출력해주고 커맨드를 받아온다.
	*	@pre	none
	*	@post	받아온 커맨드를 리턴한다.
	*/
	int GetCommandInServer();


	/**
	*	@brief	클라이언트 단에서 실행할 수 있는 함수들의 목록을 출력해주고 커맨드를 받아온다.
	*	@pre	none
	*	@post	받아온 커맨드를 리턴한다.
	*/
	int GetCommandInClient();
	/**
	*	@brief 채팅리스트에 있는 메세지함을 비운다.
	*	@post 채팅리스트의 length를 0으로 만든다.
	*/
	void DeleteMessage();

	/**
	*	@brief CurrentMember의 친구리스트에 입력받은 친구정보를 추가.
	*	@post 친구리스트에 친구가 추가된다.
	*/
	void AddFriend();

	/**
	*	@brief CurrentMember의 친구리스트에 입력받은 친구정보를 삭제.
	*	@post 친구리스트에 친구가 삭제된다// 삭제되면 1리턴 아니면 0리턴.
	*/
	int DeleteFriend();

	/**
	*	@brief CurrentMember의 친구리스트에 있는 친구정보들을 출력
	*/
	void DisplayAllFriendList();

	/**
	*	@brief CurrentMember의 친구리스트에서 입력받은 친구정보를 출력.
	*/
	void RetrieveFriend();
	
	/**
	*	@brief CurrentMember의 그룹메세지를 클라이언트로부터 입력받아 서버로 보낸다.
	*/
	void GetGroupMessageFromClient();

	/**
	*	@brief CurrentMember의 프렌드그룹리스트에 프렌드그룹을 추가한다.
	*/
	void AddFriendToFriendGroup();
	
	/**
	*	@brief CurrentMember의 프렌드그룹리스트 정보를 출력.
	*/
	void PrintFriendGroupList();
	
	/**
	*	@brief 회원리스트에서 오늘이 생일인 회원의 정보를 출력.
	*/
	void TodayBirthdayMem();

	/**
	*	@brief CurrentMember의 그룹채팅 정보를 출력한다.
	*/
	void PrintGroupChatlist();

	/**
	*	@brief CurrentMember의 친구를 추천.
	*/
	void RecommendFriend();

private:
	ifstream m_InFile;		//< input file descriptor.
	ofstream m_OutFile;		//< output file descriptor.
	BST<ItemType>m_List;	//< Linked-list for ItemType.
	int m_nCurCommand;	//< current command number
	ItemType* CurrentMember; //< 현재 로그인된 멤버를 가리키는 포인터.
	CircularQueueType<MessageType> messageQ; //< 서버에 메세지를 임시저장할 메세지큐.
	bool LogonStateE; //< 로그인 상태이면 True 아니면 False.
	string Today; // 오늘 생일 회원을 확인할 MMDD를 받아올 변수
	MessageType ForCopy;//메세지 복사 및 전달을 위한 변수.
	BST<ItemType>BirthMList; //생일인 멤버를 담을 BST.
};

#endif