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
	cout << "0. MENU���� " << endl;
	cout << "1. ����ũ on/off" << endl;
	cout << "2. ī�޶� on/off" << endl;
	cout << "3. ������ ��� ����" << endl;
	cout << "4. ä��â ����" << endl;
	cout << "5. ȭ������ϱ�" << endl;
	cout << "6. �� ���" << endl;
	cout << "7. ���������ϱ�" << endl;
}

void student::enterMeeting(int meeting_number)
{
	while (true)
	{
		int number;
		cout << "	���÷� �ѹ��� �Է��ϼ��� : ";
		cin >> number;
		if (number == meeting_number)
		{
			cout << "���÷뿡 �����մϴ�." << endl;
			break;
		}
		else
			cout << "��ȣ�� Ʋ���ϴ� ! " << endl;
	}
}

void student::exitMeeting()
{
	int answer;
	cout << "������ �����ڽ��ϱ�? (1. Yes, 2.No) ";
	cin >> answer;
	if (answer == 1)
		cout << "������ �����ϴ�." << endl;
}

void student::setCamera(int &set)
{
	cout << "ī�޶� on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(ī�޶� on)---" << endl;
	else if (set == 2)
		cout << "---(ī�޶� off)---" << endl;
}
void student::setMike(int &set)
{
	cout << "����ũ on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(����ũ on)---" << endl;
	else if (set == 2)
		cout << "---(����ũ off)---" << endl;
}
void student::sharing(string &shared)
{
	cout << "������ ȭ�� �Ǵ� ���ø����̼��� �����ϼ��� : ";
	//������ ȭ�� ��������� ����
	cin >> shared;
	cout << "--<ȭ������� �����մϴ� ("<<shared<<")>--" << endl;
}
void student::RaiseHands()
{
	string name = this->getName();
	cout << name <<"--(�� ���)" << endl;
}
void student::ShowChat()
{
	cout << "-----<ä��â>-----" << endl;
	chatting();
}

void student::ShowParticipants(string list[])
{
	int i = 0;
	cout << "-----<������ ���>-----" << endl;
	while (list[i].empty() != true)     //������ ����Ʈ�� �̸��� ������������� ���
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

