#pragma once
#include"Point2D.h"
#include"Point3D.h"

class Entity {
public:
	enum class Type {
		Player,
		NPC,
		Mob
	};
public:
	int id;
	char* name;
	Point2D* location;
	Type type;
	int generateID();
public:
	virtual bool isAlive()=0;
	double getDistanceTo2D(const Entity& entity);
	double getDistanceTo(const Entity& entity);
	void moveTo(Point2D* ptr);
	void moveTo(const Entity& entity);
	~Entity();
	friend class Environment;
};