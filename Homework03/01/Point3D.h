#pragma once
#include"Point2D.h"
#include<cmath>
class Point3D : public Point2D {
protected:
	double z;
public:
	Point3D();
	Point3D(double x, double y, double z);
	virtual double getDistanceTo(const Point3D point);
	friend class Entity;
};