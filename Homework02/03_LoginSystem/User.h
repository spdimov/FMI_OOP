#pragma once
#include"Guest.h"
class User : public Guest {
public:
	 char* username;
	 char* password;
	 char* title;
	 void cryptPass(char* password);
public:
	User();
	User(const char* user,   const char* pass, const char* tit);
	User(const User& copy);
	User& operator=(const User& copy);
	 ~User();
	 friend class Admin;
	void changePass( char* oldPass,const char* newPass);
};