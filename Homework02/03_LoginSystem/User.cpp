#include"User.h"
#include<cstring>
void User::cryptPass(char* password){
	int i = 0;
	while (password[i] != '\0') {
		password[i]+=38;
		i++;
	}
}
User::User(){
	
	username = new char[1];
	strcpy(username, "\0");

	title = new char[1];
	strcpy(title, "\0");

	password = new char[1];
	strcpy(password, "\0");
}

User::User(const char * user,   const char * pass, const char * tit){
	username = new char[strlen(user)+1];
	strcpy(username, user);

	title = new char[strlen(user)+1];
	strcpy(title, title);

	password = new char[strlen(pass) + 1];
	strcpy(password, pass);

	cryptPass(password);
}

User::User(const User & copy){
	username = new char[strlen(copy.username) + 1];
	strcpy(username, copy.username);
	password = new char[strlen(copy.password) + 1];
	strcpy(password, copy.password);
	title = new char[strlen(copy.title) + 1];
	strcpy(title, copy.title);
}

User & User::operator=(const User & copy){
	if (this != &copy) {
		delete[] username;
		delete[] password;
		delete[] title;
		username = new char[strlen(copy.username) + 1];
		strcpy(username, copy.username);
		password = new char[strlen(copy.password) + 1];
		strcpy(password, copy.password);
		title = new char[strlen(copy.title) + 1];
		strcpy(title, copy.title);
	}
	return *this;
}

User::~User(){
	delete[] password;
	delete[] username;
	delete[] title;
}

void User::changePass( char * oldPass, const char * newPass){
	this->cryptPass(oldPass);
if (strcmp(oldPass,password) == 0) {
	delete[] password;
	password = new char[strlen(newPass) + 1];
	strcpy(password, newPass);
}
}

