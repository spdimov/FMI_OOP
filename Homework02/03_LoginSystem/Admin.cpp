#include "Admin.h"
#include<cstring>
Admin::Admin():PowerUser(){
}

Admin::Admin(const char* user, const char* pass, const char* tit, int reputation) : PowerUser(user, pass, tit,reputation) {
	this->reputation = reputation;
}

void Admin::changeThisUsername(const char* username){
	delete[] PowerUser::username;
	PowerUser::username = new char[strlen(username) + 1];
	strcpy(PowerUser::username, username);

}

void Admin::changeOtherUsername( User & user,const char* username){
	delete[] user.username;
	user.username = new char[strlen(username) + 1];
	strcpy(user.username, username);
}

char* Admin::getUsername() const {
	return PowerUser::username;
}