#include "program.h"
#include "professor.h"
#include "student.h"
#include <iostream>
using namespace std;

int program::setStance() //강의제공자/수강자 선택 함수
{
	int stance;

	cout << "당신은 누구인가요 (1. 제공자, 2. 수강자 , 프로그램 종료:0): "; //제공자/수강자 구분
	cin >> stance;
	cin.ignore();
	return stance;
}
void program::StartProgram()  //전체 프로그램 운영 함수
{
	int stance;
	int number;
	string name;
	string student_ID;
	professor* Professor=NULL;
	student* Student;
	int menu;
	string Participants[100]; //참가자들의 이름을 저장할 배열 100개 선언
	int i = 0; //배열 인덱스
	int MikeState; //현재 마이크 상태
	int CameraState;  //현재 카메라 상태
	string SharedMonitor;  //현재 공유된 화면
	
	while (true)
	{
		
		stance = setStance();  //강의 제공자/수강자 입력
		
		cout << "------log in------" << endl;

		if (stance == 1) //제공자인 경우 professor 객체 생성
		{
			cout << "ID(이름): ";
			getline(cin, name);

			Professor = new professor(name); //매개변수 생성자 호출하여 professor 객체 동적할당

			Participants[i] = Professor->getName(); //참가자 목록에 이름 저장 
			++i; //participants 배열 인덱스 증가

			Professor->setMeetingNumber(); //professor 미팅넘버 생성
			cout << endl << "---log in Success | meeting Room Number : " << Professor->getMeetingNumber() << "---" << endl << endl;
			Professor->openMeeting(); //미팅 시작 

			while (true)
			{
				Professor->showMenu();
				cout << endl << "menu : ";
				cin >> menu;
				cin.ignore();

				if (menu == 1)
					Professor->setMike(MikeState);
				if (menu == 2)
					Professor->setCamera(CameraState);
				if (menu == 3)
					Professor->showParticipant(Participants);
				if (menu == 4)
					Professor->showChat();
				if (menu == 5)
					Professor->Sharing(SharedMonitor);
				if (menu == 6)
					Professor->setPresenter(Participants[i]);
				if (menu == 7)
					Professor->recordMeeting();
				if (menu == 8)
				{
					Professor->exitMeeting();
					break; 
				}
			}
		}
		else if (stance == 2)  //강의수강자 선택시 Student 객체 생성
		{
			cout << "이름 : ";
			getline(cin, name);
			cout << "학번 : ";
			cin >> student_ID;
			Student = new student(name, student_ID); //매개변수 생성자 호출

			Participants[i] = Student->getName();
			++i;  //참가자 목록에 이름 저장후 participants 배열 인덱스 증가

			cout << "---log in Success---" << endl << endl;  //log in 완료

			if (Professor == NULL)  //교수(강의제공자)가 미팅룸 생성전
			{
				cout << "	미팅룸이 아직 개설되지 않았습니다." << endl;
				cout << "	교수가 미팅을 시작할때 까지 기다리세요." << endl << endl;
				cout << "프로그램을 종료합니다." << endl;
			}
			else  //교수(강의제공자)가 미팅룸 생성이후
			{
				number = Professor->getMeetingNumber();  //강의 제공자의 미팅룸 번호
				Student->enterMeeting(number);
			}
			Student->showMenu();

			while (true)
			{
				cout << endl << "menu : ";
				cin >> menu;
				cin.ignore();

				if (menu == 1)
					Student->setMike(MikeState);
				if (menu == 2)
					Student->setCamera(CameraState);
				if (menu == 3)
					Student->ShowParticipants(Participants);
				if (menu == 4)
					Student->ShowChat();
				if (menu == 5)
					Student->sharing(SharedMonitor);
				if (menu == 6)
					Student->RaiseHands();
				if (menu == 7)
				{
					Student->exitMeeting();
					break; 
				}
				
			}
		
		}
		if (stance == 0)
			break;
	}
}
		
		

