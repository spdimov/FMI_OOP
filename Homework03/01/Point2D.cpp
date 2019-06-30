#include "Point2D.h"
#include<cmath>
Point2D::Point2D(double x, double y){
	this->x = x;
	this->y = y;
}
Point2D::Point2D(){
	x = 0;
	y = 0;
}
double Point2D::getDistanceTo(const Point2D & point){
	return sqrt(pow(abs(point.x-this->x),2)+ pow(abs(point.y - this->y),2));
}
