#include "professor.h"
#include <iostream>
#include <ctime>
using namespace std;

void professor::showMenu()
{
	cout << "-----<MENU>-----" << endl;
	cout << "0. MENU보기 " << endl;
	cout << "1. 마이크 on/off" << endl;
	cout << "2. 카메라 on/off" << endl;
	cout << "3. 참가자 목록 열기" << endl;
	cout << "4. 채팅창 열기" << endl;
	cout << "5. 화면공유하기" << endl;
	cout << "6. 발표자 지정" << endl;
	cout << "7. 미팅녹화하기" << endl;
	cout << "8. 미팅종료하기" << endl;
}
void professor::setMeetingNumber()
{
	int meetingNumber=0;
	srand((unsigned int)time(NULL));
	meetingNumber = rand();
	this->meetingNumber = meetingNumber;
}
void professor::openMeeting()
{
	int answer;
	while (true)
	{
		cout << "미팅을 시작하시겠습니까? (1. Yes, 2. No) ";
		cin >> answer;
		if (answer == 1)
		{
			cout << "----------<미팅 시작>------------" << endl;
			break;
		}
		else if (answer == 2)
			cout << "미팅 취소" << endl;
	}
}
void professor::showParticipant(string list[])
{
	int i = 0;
	cout << "-----<참가자 목록>-----" << endl;
	while(list[i].empty()!=true)     //참가자 리스트에 이름이 들어있을때까지 출력
	{
		cout << list[i] << "\t" << endl;
		++i;
	} 
}
void professor::showChat()
{
	cout << "-----<채팅창>-----" << endl;
	chatting();
}
void professor::Sharing(string &shared)
{
	cout << "공유할 화면 또는 어플리케이션을 선택하세요 : ";
	cin >> shared;    //선택한 화면 멤버변수에 저장
	cout << "--<화면공유를 시작합니다 ("<<shared<<")>--" << endl;
}
void professor::setCamera(int &set)
{
	cout << "카메라 on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(카메라 on)---" << endl;
	else if (set == 2)
		cout << "---(카메라 off)---" << endl;
}
void professor::setMike(int &set)
{
	cout << "마이크 on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(마이크 on)---" << endl;
	else if (set == 2)
		cout << "---(마이크 off)---" << endl;
}
void professor::setPresenter(string name)
{
	cout << name <<"님을 발표자로 지정합니다. " << endl;
}
void professor::chatting()
{
	string chatToPerson;
	string chat;

	cout << "		To: ";		
	getline(cin, chatToPerson);
	cout << "		message: ";
	getline(cin, chat);

}

void professor::recordMeeting()
{
	cout << "--화면녹화를 시작합니다--" << endl;
}
void professor::exitMeeting()
{
	int answer;
	cout << "미팅을 나가겠습니까? (1. Yes, 2.No) ";
	cin >> answer;
	if (answer == 1)
		cout << "미팅을 나갑니다." << endl;
}
