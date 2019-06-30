#include<iostream>
#include"Point2D.h"
#include"Entity.h"
#include"Player.h"
#include"NPC.h"
#include"Environment.h"
using namespace std;
int main() {
	Point2D p1(1,2);
	Point3D p2(1, 3, 3);
	Player Player1(1,2,"Player1",&p1);
	Mob mob(3, 2, "Da", &p2);
	NPC npc("Dda", &p2);
	Environment env;
	//env.generateEntities(); n
	env.add(&npc);

	Player1.attack(env.getClosestAliveEntity(Player1, Entity::Type::NPC));


	return 0;
}