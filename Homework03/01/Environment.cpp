#include "Environment.h"

Environment::Environment(){
	entities.reserve(10);
}

void Environment::add(Entity*  input){
	entities.push_back(input);
}

Entity * Environment::getAt(int index) const {

	return entities[index];
}

void Environment::removeAt(int index){
	entities.erase(entities.begin() + index);
}

void Environment::generateEntities(){
	Point3D p1(1, 2, 3);
	Point2D p2(4, 3);
	Point3D p3(4, 1, 5);
	Mob mob1(10,2,"Mob1",&p1);
	NPC npc1("Npc1",&p2);
	
	this->add(&mob1);
	this->add(&npc1);

}

void Environment::destroyEntities(){
	entities.clear();
}

Entity * Environment::getClosestAliveEntity(Player &player, Entity::Type type) const {
	int size = entities.size();
	int minDistance = INT16_MAX;
	Entity* toReturn=nullptr;
	for (int i = 0; i < size; i++) {
		if (type == Entity::Type::Player) {
			Player* cast = dynamic_cast<Player*>(entities[i]);
				if (player.getDistanceTo(*cast) < minDistance && cast->isAlive() && cast!=nullptr ) {
					toReturn = entities[i];
					minDistance = player.getDistanceTo(*cast);
				}
		}
		else if (type == Entity::Type::NPC) {
			NPC* cast = dynamic_cast<NPC*>(entities[i]);
			if (player.getDistanceTo(*cast) < minDistance && cast->isAlive() && cast != nullptr) {
				toReturn = entities[i];
				minDistance = player.getDistanceTo(*cast);
			}
		}
		else if(type==Entity::Type::Mob){
			Mob* cast = dynamic_cast<Mob*>(entities[i]);
			if (player.getDistanceTo(*cast) < minDistance && cast->isAlive() && cast != nullptr) {
				toReturn = entities[i];
				minDistance = player.getDistanceTo(*cast);
			}
		}
	}
	return toReturn;
}
