#include "Vip.h"
#include<cstring>
VIP::VIP() : User() {}

VIP::VIP(const char * user, const char * pass, const char * tit, int reputation):User(user, pass, tit) {}
void VIP::changeTitle(const char* title) {
	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);

}

