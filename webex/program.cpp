#include "program.h"
#include "professor.h"
#include "student.h"
#include <iostream>
using namespace std;

int program::setStance() //����������/������ ���� �Լ�
{
	int stance;

	cout << "����� �����ΰ��� (1. ������, 2. ������ , ���α׷� ����:0): "; //������/������ ����
	cin >> stance;
	cin.ignore();
	return stance;
}
void program::StartProgram()  //��ü ���α׷� � �Լ�
{
	int stance;
	int number;
	string name;
	string student_ID;
	professor* Professor=NULL;
	student* Student;
	int menu;
	string Participants[100]; //�����ڵ��� �̸��� ������ �迭 100�� ����
	int i = 0; //�迭 �ε���
	int MikeState; //���� ����ũ ����
	int CameraState;  //���� ī�޶� ����
	string SharedMonitor;  //���� ������ ȭ��
	
	while (true)
	{
		
		stance = setStance();  //���� ������/������ �Է�
		
		cout << "------log in------" << endl;

		if (stance == 1) //�������� ��� professor ��ü ����
		{
			cout << "ID(�̸�): ";
			getline(cin, name);

			Professor = new professor(name); //�Ű����� ������ ȣ���Ͽ� professor ��ü �����Ҵ�

			Participants[i] = Professor->getName(); //������ ��Ͽ� �̸� ���� 
			++i; //participants �迭 �ε��� ����

			Professor->setMeetingNumber(); //professor ���óѹ� ����
			cout << endl << "---log in Success | meeting Room Number : " << Professor->getMeetingNumber() << "---" << endl << endl;
			Professor->openMeeting(); //���� ���� 

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
		else if (stance == 2)  //���Ǽ����� ���ý� Student ��ü ����
		{
			cout << "�̸� : ";
			getline(cin, name);
			cout << "�й� : ";
			cin >> student_ID;
			Student = new student(name, student_ID); //�Ű����� ������ ȣ��

			Participants[i] = Student->getName();
			++i;  //������ ��Ͽ� �̸� ������ participants �迭 �ε��� ����

			cout << "---log in Success---" << endl << endl;  //log in �Ϸ�

			if (Professor == NULL)  //����(����������)�� ���÷� ������
			{
				cout << "	���÷��� ���� �������� �ʾҽ��ϴ�." << endl;
				cout << "	������ ������ �����Ҷ� ���� ��ٸ�����." << endl << endl;
				cout << "���α׷��� �����մϴ�." << endl;
			}
			else  //����(����������)�� ���÷� ��������
			{
				number = Professor->getMeetingNumber();  //���� �������� ���÷� ��ȣ
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
		
		

