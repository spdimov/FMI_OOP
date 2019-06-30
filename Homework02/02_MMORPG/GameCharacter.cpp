#include"GameCharacter.h"
#include<cstring>
GameCharacter::GameCharacter(){
	name = new char[1];
	strcpy(name, "\0");
}
GameCharacter::GameCharacter(const char * name, int hp, int mp, int ap, int dp){
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	HP = hp;
	MP = mp;
	AP = ap;
	DP = dp;
}

GameCharacter::GameCharacter(const GameCharacter & copy){
	this->name = new char[strlen(copy.name) + 1];
	strcpy(this->name, copy.name);
	HP = copy.HP;
	MP = copy.MP;
	AP = copy.AP;
	DP = copy.DP;
}

GameCharacter & GameCharacter::operator=(const GameCharacter & copy) {
	if (this != &copy) {
		delete[] name;
		this->name = new char[strlen(copy.name) + 1];
		strcpy(this->name, copy.name);
		HP = copy.HP;
		MP = copy.MP;
		AP = copy.AP;
		DP = copy.DP;
	}
	return *this;
}

GameCharacter::~GameCharacter(){
	delete[] name;
}

void GameCharacter::getAttacked(int opponentAP){
	if (opponentAP > DP) {
		DP -= opponentAP;
	}
}
