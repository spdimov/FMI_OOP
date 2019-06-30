#pragma once
#include"User.h"
class VIP: public User {
public:
	VIP();
	VIP(const char*  user, const char*  pass, const char*  tit, int reputation);
	void changeTitle(const char* title);
};