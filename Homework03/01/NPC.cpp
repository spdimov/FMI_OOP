#include "NPC.h"
#include<cstring>
NPC::NPC() {
	id = generateID();
	type = Type::NPC;
	name = new char[1];
	strcpy(name, "");
	location = new Point2D();
}

NPC::NPC(const char * name, Point2D * location){
	id = generateID();
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->location = new Point2D(*location);
}

bool NPC::isAlive(){
	return true;
}
