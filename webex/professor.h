#pragma once
#include <string>
#include "student.h"
using namespace std;

class professor
{
	string name;
	int meetingNumber=0;
public:
	professor() { ; } //�⺻������
	professor(string name) { this->name = name; } //�Ű����� ������
	void setMeetingNumber();
	int getMeetingNumber() { return meetingNumber; }
	string getName() { return name; }
	void openMeeting();
	void setMike(int &set);
	void setCamera(int &set);
	void Sharing(string &shared);
	void showParticipant(string list[]);
	void recordMeeting();
	void showChat();
	void chatting();
	void setPresenter(string name);
	void exitMeeting();
	void showMenu();
};

