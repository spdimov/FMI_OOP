#include "Entity.h"

int Entity::generateID()
{
	static int UniqueID=0;
	return UniqueID++;
}

bool Entity::isAlive()
{
	return true;
}

double Entity::getDistanceTo2D(const Entity & entity)
{
	return location->getDistanceTo(*(entity.location));
}

double Entity::getDistanceTo(const Entity & input) {
	Point3D* castThisTo3D = dynamic_cast<Point3D*>(this->location);
	Point3D* castInputTo3D = dynamic_cast<Point3D*>(input.location);
	if (castInputTo3D != nullptr && castThisTo3D != nullptr) {
		return castThisTo3D->getDistanceTo(*castInputTo3D);
	}
	else {
		return this->location->getDistanceTo(*input.location);
	}


	
}

void Entity::moveTo(Point2D * ptr){
	Point2D* castThisTo2D = dynamic_cast<Point2D*>(this->location);
	Point2D* castInputTo2D = dynamic_cast<Point2D*>(ptr);
	Point3D* castInputTo3D = dynamic_cast<Point3D*>(ptr);
	Point3D* castThisTo3D = dynamic_cast<Point3D*>(this->location);
	if (castInputTo3D != nullptr &&castThisTo3D != nullptr) {
		castThisTo3D->x = castInputTo3D->x;
		castThisTo3D->y = castInputTo3D->y;
		castThisTo3D->z = castInputTo3D->z;
	}
	else {
		castThisTo2D->x = castInputTo2D->x;
		castThisTo2D->y = castInputTo2D->y;
	}
}

void Entity::moveTo(const Entity & entity){
	Point2D* castThisTo2D = dynamic_cast<Point2D*>(this->location);
	Point2D* castInputTo2D = dynamic_cast<Point2D*>(entity.location);
	Point3D* castInputTo3D = dynamic_cast<Point3D*>(entity.location);
	Point3D* castThisTo3D = dynamic_cast<Point3D*>(this->location);
	if (castInputTo3D != nullptr &&castThisTo3D != nullptr) {
		castThisTo3D->x = castInputTo3D->x;
		castThisTo3D->y = castInputTo3D->y;
		castThisTo3D->z = castInputTo3D->z;
	}
	else {
		castThisTo2D->x = castInputTo2D->x;
		castThisTo2D->y = castInputTo2D->y;
	}

}
Entity::~Entity() {
	delete[] name;
	delete location;




}

