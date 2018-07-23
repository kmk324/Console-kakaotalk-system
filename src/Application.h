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
	*	@brief	���̵�� �н����带 �Է��Ͽ� �α����Ѵ�. ��ġ�ϴ� �׸��������� LogonStateE������ true�� ��ȯ���ش�.
	*	@post	��ġ�ϴ� �׸��� ������ LogonStateE�� true�� ��ȯ�����ش�.
	*/
	void Login();

	/**
	*	@brief	�α׿»����̸� LogonStateE�� False�� ��ȯ�����ش�.
	*	@post	�α׿»����̸� LogonStateE�� False�� ��ȯ�����ش�.
	*/
	void Logout();

	/*
	*	@brief	�α����� ȸ���� �޼����� �����ؼ� ������ äƮ����Ʈ�� �ְ�, ���� �޽���ť�� ��ť�Ѵ�.
	*	@post	������ �޼����� messageQ�� Enqueue�Ѵ�.
	*/
	void GetMessageFromClient();

	/*
	*	@breif	���� �޽���ť���� ��ť�ϰ� ������ ���̵� ã�� �׾��̵��� äƮ����Ʈ�� �ִ´�
	*	@post	������ ���̵� ������ messageQ���� Dequeue�� �޼����� ������ ���̵��� äƮ����Ʈ�� add�Ѵ�./������ "�׷� ���̵�� �����ϴ�." ���.
	*/
	void SendMessageToClient();

	/*
	*	@brief	client �ܿ��� ����� ����Լ� ��ϵ��� ����ϰ� Ŀ�ǵ带 �޾Ƽ� �ش��ϴ� �Լ��� ȣ���Ѵ�.
	*	@pre	LogonStateE�� True�̾�� �Ѵ�.
	*	@post	Ŀ�ǵ尡 0�� �ƴϸ� while���� ��� �ݺ��Ѵ�. 0�̸� Ŭ���̾�Ʈ �Լ����� ����.
	*/
	void Client();

	/*
	*	@brief server �ܿ��� ����� ����Լ� ��ϵ��� ����ϰ� Ŀ�ǵ带 �޾Ƽ� �ش��ϴ� �Լ��� ȣ���Ѵ�.
	*	@pre none.
	*	@post Ŀ�ǵ尡 0�� �ƴϸ� while���� ��� �ݺ��Ѵ�. 0�̸� Ŭ���̾�Ʈ �Լ����� ����.
	*/
	void Server();

	/**
	*	@brief CurrentMember(���� �α����� ȸ��)�� äƮ����Ʈ�� Display���ش�.
	*	@pre CurrentMember should be set.
	*	@post none
	*/
	void PrintChatList();

	/**
	*	@brief	�����ܿ��� ������ �� �ִ� �Լ����� ����� ������ְ� Ŀ�ǵ带 �޾ƿ´�.
	*	@pre	none
	*	@post	�޾ƿ� Ŀ�ǵ带 �����Ѵ�.
	*/
	int GetCommandInServer();


	/**
	*	@brief	Ŭ���̾�Ʈ �ܿ��� ������ �� �ִ� �Լ����� ����� ������ְ� Ŀ�ǵ带 �޾ƿ´�.
	*	@pre	none
	*	@post	�޾ƿ� Ŀ�ǵ带 �����Ѵ�.
	*/
	int GetCommandInClient();
	/**
	*	@brief ä�ø���Ʈ�� �ִ� �޼������� ����.
	*	@post ä�ø���Ʈ�� length�� 0���� �����.
	*/
	void DeleteMessage();

	/**
	*	@brief CurrentMember�� ģ������Ʈ�� �Է¹��� ģ�������� �߰�.
	*	@post ģ������Ʈ�� ģ���� �߰��ȴ�.
	*/
	void AddFriend();

	/**
	*	@brief CurrentMember�� ģ������Ʈ�� �Է¹��� ģ�������� ����.
	*	@post ģ������Ʈ�� ģ���� �����ȴ�// �����Ǹ� 1���� �ƴϸ� 0����.
	*/
	int DeleteFriend();

	/**
	*	@brief CurrentMember�� ģ������Ʈ�� �ִ� ģ���������� ���
	*/
	void DisplayAllFriendList();

	/**
	*	@brief CurrentMember�� ģ������Ʈ���� �Է¹��� ģ�������� ���.
	*/
	void RetrieveFriend();
	
	/**
	*	@brief CurrentMember�� �׷�޼����� Ŭ���̾�Ʈ�κ��� �Է¹޾� ������ ������.
	*/
	void GetGroupMessageFromClient();

	/**
	*	@brief CurrentMember�� ������׷츮��Ʈ�� ������׷��� �߰��Ѵ�.
	*/
	void AddFriendToFriendGroup();
	
	/**
	*	@brief CurrentMember�� ������׷츮��Ʈ ������ ���.
	*/
	void PrintFriendGroupList();
	
	/**
	*	@brief ȸ������Ʈ���� ������ ������ ȸ���� ������ ���.
	*/
	void TodayBirthdayMem();

	/**
	*	@brief CurrentMember�� �׷�ä�� ������ ����Ѵ�.
	*/
	void PrintGroupChatlist();

	/**
	*	@brief CurrentMember�� ģ���� ��õ.
	*/
	void RecommendFriend();

private:
	ifstream m_InFile;		//< input file descriptor.
	ofstream m_OutFile;		//< output file descriptor.
	BST<ItemType>m_List;	//< Linked-list for ItemType.
	int m_nCurCommand;	//< current command number
	ItemType* CurrentMember; //< ���� �α��ε� ����� ����Ű�� ������.
	CircularQueueType<MessageType> messageQ; //< ������ �޼����� �ӽ������� �޼���ť.
	bool LogonStateE; //< �α��� �����̸� True �ƴϸ� False.
	string Today; // ���� ���� ȸ���� Ȯ���� MMDD�� �޾ƿ� ����
	MessageType ForCopy;//�޼��� ���� �� ������ ���� ����.
	BST<ItemType>BirthMList; //������ ����� ���� BST.
};

#endif