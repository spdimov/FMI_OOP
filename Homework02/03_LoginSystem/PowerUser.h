#include"User.h"
#pragma once
class PowerUser : public User {
protected:
	int reputation;
public:
	PowerUser();
	PowerUser(const char*  user,const char*  pass,const char*  tit,int reputation);
	void getRep( PowerUser& user);
};