#pragma once
#include"Vip.h"
#include"PowerUser.h"

class Admin: public VIP, public PowerUser{
public:
	Admin();
	Admin(const char*  user, const char*  pass, const char*  tit, int reputation);
	void changeThisUsername(const char* username);
	void changeOtherUsername( User& user, const char* username);
	char* getUsername() const;


};