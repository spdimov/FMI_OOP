#pragma once 
class GameCharacter{
protected:
	char* name;
	int HP;//Health
	int MP;//Magic
	int AP;//Attack
	int DP;//Defence
public:
	GameCharacter();
	GameCharacter(const char* name, int hp, int mp, int ap, int dp);
	GameCharacter(const GameCharacter& copy);
	GameCharacter& operator=(const GameCharacter& copy);
	~GameCharacter();
	void getAttacked(int opponentAP);
};