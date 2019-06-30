#pragma once
#include"Player.h"
#include"Mob.h"
#include"NPC.h"
#include<vector>
#include"Entity.h"
#include"Point3D.h"
class Environment {
protected:
	std::vector<Entity*> entities;
public:
	Environment();
	void add(Entity* input);
	Entity* getAt(int index) const;
	void removeAt(int index);
	void generateEntities();
	void destroyEntities();
	Entity* getClosestAliveEntity(Player &player, Entity::Type type) const ;
};