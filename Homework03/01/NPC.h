#pragma once
#include"Entity.h"
class NPC :public Entity {
public:
	NPC();
	NPC(const char* name, Point2D* location);
	virtual bool isAlive() override;
};