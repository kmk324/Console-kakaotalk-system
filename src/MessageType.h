#pragma once
#pragma once
#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
using namespace std;
// 메세지의 정보 클래스.
class MessageType
{
public:
	

	MessageType()//기본 생성자
	{
		Message = "";
		RealTime = currentDateTime(); // 현재시간을 메세지타입 변수 RealTime에 할당해준다.
		GroupNameInMessage = "1:1채팅";
	}
	~MessageType()// 기본소멸자
	{

	}

	//멤버함수 설정을 위한함수.
	void SetGroupNameInMessage(string tempGroupNameInMessage)
	{
		GroupNameInMessage = tempGroupNameInMessage;
	}
	
	//멤버함수 설정을 위한함수.
	void SetMessage(string tempMesageContents)
	{
		Message = tempMesageContents;
	}

	//파라미터로 Sender를 받아서 세팅.
	void SetSender(string tempSender) 
	{
		Sender = tempSender;
	}

	//멤버함수 설정을 위한함수.
	void SetReceiver(string tempReceiver)
	{
		Receiver = tempReceiver;
	}

	void SetSenderFromKB() //키보드로부터 센더를 입력받아서 세팅.
	{
		cout << "\tSender : ";
		cin >> Sender;
	}
	void SetReceiverFromKB()// 키도브로부터 Receiver를 입력받아서 세팅.
	{
		cout << "\tReceiver : ";
		cin >> Receiver;
	}
	void SetMessageFromKB() //키보드로부터 메세지를 입력받아서 세팅.
	{
		cout << "\tMessage : ";
		cin.clear();
		cin.ignore(100, '\n'); //이전 함수에서 엔터가 딸려온다.이 줄이 없으면 Message를 받아올 수 없다.
		getline(cin, Message);
	}

	string GetMessage() // 메세지 참조용 함수.
	{
		return Message;
	}

	string GetSender() // 센더변수 참조용 함수.
	{
		return Sender;
	}

	string GetReciever() //Receiver 참조용 함수.
	{
		return Receiver;
	}

	string GetGroupNameInMessage() //GroupNameInMessage멤버변수에 접근을 위한 함수.
	{
		return GroupNameInMessage;
	}

	string GetSendTime() //RealTime멤버변수에 접근을 위한 변수.
	{
		return RealTime;
	}

	void DisplayMessageOnScreen() //메세지를 스크린에 출력하는 함수,
	{
		cout << "Message : ";
		cout << Message;
		cout << endl;
	}

	void DisplaySenderOnScreen() //센더를 스크린에 출력하는 함수.
	{
		cout << "Sender : ";
		cout << Sender;
		cout << endl;
	}

	void DisplayReceiverOnScreen() //리시버를 스크린에 출력하는 함수.
	{
		cout << "Receiver : ";
		cout << Receiver;
		cout << endl;
	}
	void DisplayRealTimeOnScreen() //전송시간을 출력해주는 함수
	{
		cout << "전송시간 : ";
		cout << RealTime;
		cout << endl;
	}
	
	void DisplayGroupNameOnScreen() //그룹이름을 출력해주는 함수
	{
		cout << "그룹이름 : ";
		cout << GroupNameInMessage;
		cout << endl;
	}

	MessageType &operator=(MessageType &ref) //링크드리스트사용을 위한 연산자 오버로딩.
	{
		Message = ref.GetMessage();
		Sender = ref.GetSender();
		Receiver = ref.GetReciever();
		RealTime = ref.RealTime;
		GroupNameInMessage = ref.GroupNameInMessage;
		return *this;
	}

	// 메세지의 생성 시간을 리턴해주는 함수.
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
	
	string GroupNameInMessage; //메세지의 그룹을 구분하는 변수.
	string Message; //메세지를 저장하는 변수.
	string Sender; // 센더를 저장하는 변수.
	string Receiver; //리시버를 저장하는 변수.
	string RealTime; //메세지 전송시간을 담는 변수.
	//int SequenceNumber; // 메세지의 순서.
};

