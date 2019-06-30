#include "Player.h"
#include"Entity.h"
#include<cstring>
#include"Mob.h"
Player::Player() {
	id = generateID();
	type = Type::Player;
	damage = 0;
	health = 0;
	this->name = new char[1];
	strcpy(this->name, "");
	this->location = new Point2D();
}

Player::Player(int damage, int health, const char* name, Point2D* location) {
	id = generateID();
	type = Type::Player;
	this->damage = damage;
	this->health = health;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->location = new Point2D(*location);
}

bool Player::isAlive()
{
	return health > 0;
}

void Player::attack(Entity * input) {
	Player* castToPlayer = dynamic_cast<Player*>(input);
	Mob* castToMob = dynamic_cast<Mob*>(input);
	if (castToPlayer != nullptr) {
		if (this->location->getDistanceTo(*(input->location)) < 5) {
			castToPlayer->health -= this->damage;
		}
	}
	else if (castToMob != nullptr) {
		if (this->location->getDistanceTo(*(input->location)) < 5) {
			castToMob->health -= this->damage;
		}
	}
}
