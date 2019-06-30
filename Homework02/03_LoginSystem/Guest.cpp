#include"Guest.h"
#include<cstring>
Guest::Guest() {
	IP = new char[2];
	strcpy(IP, "\0");
}
Guest::Guest(const char * ip){
	IP = new char[strlen(ip) + 1];
	strcpy(IP, ip);
}
Guest::Guest(const Guest & copy){
	IP = new char[strlen(copy.IP) + 1];
	strcpy(IP, copy.IP);
}
Guest & Guest::operator=(const Guest & copy){
	if (this != &copy) {
		delete[] IP;
		IP = new char[strlen(copy.IP) + 1];
		strcpy(IP, copy.IP);
	}
	return *this;
}
Guest::~Guest() {
	delete[] IP;
}