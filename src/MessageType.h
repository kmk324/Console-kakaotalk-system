#pragma once
#pragma once
#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
using namespace std;
// �޼����� ���� Ŭ����.
class MessageType
{
public:
	

	MessageType()//�⺻ ������
	{
		Message = "";
		RealTime = currentDateTime(); // ����ð��� �޼���Ÿ�� ���� RealTime�� �Ҵ����ش�.
		GroupNameInMessage = "1:1ä��";
	}
	~MessageType()// �⺻�Ҹ���
	{

	}

	//����Լ� ������ �����Լ�.
	void SetGroupNameInMessage(string tempGroupNameInMessage)
	{
		GroupNameInMessage = tempGroupNameInMessage;
	}
	
	//����Լ� ������ �����Լ�.
	void SetMessage(string tempMesageContents)
	{
		Message = tempMesageContents;
	}

	//�Ķ���ͷ� Sender�� �޾Ƽ� ����.
	void SetSender(string tempSender) 
	{
		Sender = tempSender;
	}

	//����Լ� ������ �����Լ�.
	void SetReceiver(string tempReceiver)
	{
		Receiver = tempReceiver;
	}

	void SetSenderFromKB() //Ű����κ��� ������ �Է¹޾Ƽ� ����.
	{
		cout << "\tSender : ";
		cin >> Sender;
	}
	void SetReceiverFromKB()// Ű����κ��� Receiver�� �Է¹޾Ƽ� ����.
	{
		cout << "\tReceiver : ";
		cin >> Receiver;
	}
	void SetMessageFromKB() //Ű����κ��� �޼����� �Է¹޾Ƽ� ����.
	{
		cout << "\tMessage : ";
		cin.clear();
		cin.ignore(100, '\n'); //���� �Լ����� ���Ͱ� �����´�.�� ���� ������ Message�� �޾ƿ� �� ����.
		getline(cin, Message);
	}

	string GetMessage() // �޼��� ������ �Լ�.
	{
		return Message;
	}

	string GetSender() // �������� ������ �Լ�.
	{
		return Sender;
	}

	string GetReciever() //Receiver ������ �Լ�.
	{
		return Receiver;
	}

	string GetGroupNameInMessage() //GroupNameInMessage��������� ������ ���� �Լ�.
	{
		return GroupNameInMessage;
	}

	string GetSendTime() //RealTime��������� ������ ���� ����.
	{
		return RealTime;
	}

	void DisplayMessageOnScreen() //�޼����� ��ũ���� ����ϴ� �Լ�,
	{
		cout << "Message : ";
		cout << Message;
		cout << endl;
	}

	void DisplaySenderOnScreen() //������ ��ũ���� ����ϴ� �Լ�.
	{
		cout << "Sender : ";
		cout << Sender;
		cout << endl;
	}

	void DisplayReceiverOnScreen() //���ù��� ��ũ���� ����ϴ� �Լ�.
	{
		cout << "Receiver : ";
		cout << Receiver;
		cout << endl;
	}
	void DisplayRealTimeOnScreen() //���۽ð��� ������ִ� �Լ�
	{
		cout << "���۽ð� : ";
		cout << RealTime;
		cout << endl;
	}
	
	void DisplayGroupNameOnScreen() //�׷��̸��� ������ִ� �Լ�
	{
		cout << "�׷��̸� : ";
		cout << GroupNameInMessage;
		cout << endl;
	}

	MessageType &operator=(MessageType &ref) //��ũ�帮��Ʈ����� ���� ������ �����ε�.
	{
		Message = ref.GetMessage();
		Sender = ref.GetSender();
		Receiver = ref.GetReciever();
		RealTime = ref.RealTime;
		GroupNameInMessage = ref.GroupNameInMessage;
		return *this;
	}

	// �޼����� ���� �ð��� �������ִ� �Լ�.
	string currentDateTime()
	{
		time_t now = time(0);
		struct tm tstruct;
		char buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%m/%d %H:%M", &tstruct);
		return buf;
	}

	//friend MessageType operator<< (ostream &,MessageType&ref);
private:
	
	string GroupNameInMessage; //�޼����� �׷��� �����ϴ� ����.
	string Message; //�޼����� �����ϴ� ����.
	string Sender; // ������ �����ϴ� ����.
	string Receiver; //���ù��� �����ϴ� ����.
	string RealTime; //�޼��� ���۽ð��� ��� ����.
	//int SequenceNumber; // �޼����� ����.
};

