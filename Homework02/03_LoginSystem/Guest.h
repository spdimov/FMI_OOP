#pragma once
class Guest {
protected:
	char* IP;
public:
	Guest();
	Guest(const char* ip);
	Guest(const Guest& copy);
	Guest& operator=(const Guest& copy);
	~Guest();
};