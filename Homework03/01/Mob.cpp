#include "Mob.h"
#include<cstring>
Mob::Mob(){
	id = generateID();
	type = Type::Mob;
	damage = 0;
	health = 0;
	this->name = new char[1];
	strcpy(this->name, "");
	this->location = new Point2D();

}

Mob::Mob(int damage, int health, const char * name, Point2D* location){
	id = generateID();
	type = Type::Mob;
	this->damage = damage;
	this->health = health;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->location = new Point2D(*location);
}

bool Mob::isAlive()
{
	return health>0;
}

void Mob::attack(Player input){
	if (this->location->getDistanceTo(*(input.location)) > 5) {
		input.health -= 5;

	}
}
