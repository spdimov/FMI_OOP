#pragma once
#include"Entity.h"
#include"Player.h"
class Mob :public Entity{
protected:
	int damage;
	int health;
public:
	Mob();
	Mob(int damage, int health, const char* name, Point2D* location);
	virtual bool isAlive() override;
	void attack(Player input);
	friend class Player;
};