#include "PowerUser.h"

PowerUser::PowerUser():User(){
	reputation = 0;
}

PowerUser::PowerUser(const char* user, const char* pass, const char* tit,int reputation):User(user,pass,tit){
	this->reputation = reputation;
}

void PowerUser::getRep(PowerUser& puser) {
	if (this != &puser)
		this->reputation++;
}


