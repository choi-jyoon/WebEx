#pragma once
#include <string>
#include "professor.h"
using namespace std;

class student
{
	string name;
	string student_ID;
public:
	student() { ; } //기본생성자
	student(string name, string student_ID); //매개변수 생성자
	string getName() { return name; }
	string getStudent_ID() { return student_ID; }
	void enterMeeting(int meeting_number);
	void exitMeeting();
	void chatting();
	void RaiseHands();
	void setMike(int &set);
	void setCamera(int &set);
	void ShowParticipants(string list[]);
	void ShowChat();
	void sharing(string &shared);
	void showMenu();
};

