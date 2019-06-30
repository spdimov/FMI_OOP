#pragma once
class Point2D {
protected:
	double x;
	double y;
public:
	Point2D(double x, double y);
	Point2D();
	virtual double getDistanceTo(const Point2D& point);
	friend class Entity;
};