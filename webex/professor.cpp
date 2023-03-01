#include "professor.h"
#include <iostream>
#include <ctime>
using namespace std;

void professor::showMenu()
{
	cout << "-----<MENU>-----" << endl;
	cout << "0. MENU���� " << endl;
	cout << "1. ����ũ on/off" << endl;
	cout << "2. ī�޶� on/off" << endl;
	cout << "3. ������ ��� ����" << endl;
	cout << "4. ä��â ����" << endl;
	cout << "5. ȭ������ϱ�" << endl;
	cout << "6. ��ǥ�� ����" << endl;
	cout << "7. ���ó�ȭ�ϱ�" << endl;
	cout << "8. ���������ϱ�" << endl;
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
		cout << "������ �����Ͻðڽ��ϱ�? (1. Yes, 2. No) ";
		cin >> answer;
		if (answer == 1)
		{
			cout << "----------<���� ����>------------" << endl;
			break;
		}
		else if (answer == 2)
			cout << "���� ���" << endl;
	}
}
void professor::showParticipant(string list[])
{
	int i = 0;
	cout << "-----<������ ���>-----" << endl;
	while(list[i].empty()!=true)     //������ ����Ʈ�� �̸��� ������������� ���
	{
		cout << list[i] << "\t" << endl;
		++i;
	} 
}
void professor::showChat()
{
	cout << "-----<ä��â>-----" << endl;
	chatting();
}
void professor::Sharing(string &shared)
{
	cout << "������ ȭ�� �Ǵ� ���ø����̼��� �����ϼ��� : ";
	cin >> shared;    //������ ȭ�� ��������� ����
	cout << "--<ȭ������� �����մϴ� ("<<shared<<")>--" << endl;
}
void professor::setCamera(int &set)
{
	cout << "ī�޶� on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(ī�޶� on)---" << endl;
	else if (set == 2)
		cout << "---(ī�޶� off)---" << endl;
}
void professor::setMike(int &set)
{
	cout << "����ũ on/off (1. on, 2. off) : ";
	cin >> set;
	if (set == 1)
		cout << "---(����ũ on)---" << endl;
	else if (set == 2)
		cout << "---(����ũ off)---" << endl;
}
void professor::setPresenter(string name)
{
	cout << name <<"���� ��ǥ�ڷ� �����մϴ�. " << endl;
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
	cout << "--ȭ���ȭ�� �����մϴ�--" << endl;
}
void professor::exitMeeting()
{
	int answer;
	cout << "������ �����ڽ��ϱ�? (1. Yes, 2.No) ";
	cin >> answer;
	if (answer == 1)
		cout << "������ �����ϴ�." << endl;
}
