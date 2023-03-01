#include "student.h"
#include "professor.h"
#include <iostream>
using namespace std;

student::student(string name, string student_ID)
{
	this->name = name;
	this->student_ID = student_ID;
}

void student::showMenu()
{
	cout << "-----<MENU>-----" << endl;
	cout << "0. MENU보기 " << endl;
	cout << "1. 마이크 on/off" << endl;
	cout << "2. 카메라 on/off" << endl;
	cout << "3. 참가자 목록 열기" << endl;
	cout << "4. 채팅창 열기" << endl;
	cout << "5. 화면공유하기" << endl;
	cout << "6. 손 들기" << endl;
	cout << "7. 미팅종료하기" << endl;
}

void student::enterMeeting(int meeting_number)
{
	while (true)
	{
		int number;
		cout << "	미팅룸 넘버를 입력하세요 : ";
		cin >> number;
		if (number == meeting_number)
		{
			cout << "미팅룸에 입장합니다." << endl;
			break;
		}
		else
			cout << "번호가 틀립니다 ! " << endl;
	}
}

void student::exitMeeting()
{
	int answer;
	cout << "미팅을 나가겠습니까? (1. Yes, 2.No) ";
	cin >> answer;
	if (answer == 1)
		cout << "미팅을 나갑니다." << endl;
}

void student::setCamera(int &set)
{
	cout << "카메라 on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(카메라 on)---" << endl;
	else if (set == 2)
		cout << "---(카메라 off)---" << endl;
}
void student::setMike(int &set)
{
	cout << "마이크 on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(마이크 on)---" << endl;
	else if (set == 2)
		cout << "---(마이크 off)---" << endl;
}
void student::sharing(string &shared)
{
	cout << "공유할 화면 또는 어플리케이션을 선택하세요 : ";
	//선택한 화면 멤버변수에 저장
	cin >> shared;
	cout << "--<화면공유를 시작합니다 ("<<shared<<")>--" << endl;
}
void student::RaiseHands()
{
	string name = this->getName();
	cout << name <<"--(손 들기)" << endl;
}
void student::ShowChat()
{
	cout << "-----<채팅창>-----" << endl;
	chatting();
}

void student::ShowParticipants(string list[])
{
	int i = 0;
	cout << "-----<참가자 목록>-----" << endl;
	while (list[i].empty() != true)     //참가자 리스트에 이름이 들어있을때까지 출력
	{
		cout << list[i] << "\t" << endl;
		++i;
	}
}
void student::chatting()
{
	string chatToPerson;
	string chat;

	cout << "		To: ";
	getline(cin, chatToPerson);
	cout << "		message: ";
	getline(cin, chat);
}

