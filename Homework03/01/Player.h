#pragma once
#include"Entity.h"
class Player :public Entity {
protected:
	int damage;
	int health;
public:
	Player();
	Player(int damage, int health, const char* name,Point2D* location);
	virtual bool isAlive() override;
	void attack(Entity* input);
	friend class Mob;
};