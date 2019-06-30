#include "Point3D.h"

Point3D::Point3D():Point2D(){
	z = 0;
}

Point3D::Point3D(double x, double y, double z):Point2D(x,y){
	this->z = z;
}

double Point3D::getDistanceTo(const Point3D point){
	Point2D helpPoint1(point.x, point.y);
	Point2D helpPoint2(this->x, this->y);
	double distance2D=abs(helpPoint1.getDistanceTo(helpPoint2));
	return sqrt(pow(distance2D, 2) + pow(abs(point.z - this->z), 2));
}


