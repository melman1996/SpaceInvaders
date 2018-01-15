#include "stdafx.h"
#include "Point.h"


Point::Point(int coordx, int coordy) : x(coordx), y(coordy)
{
}

Point::~Point()
{
}

bool Point::operator==(const Point & point) const
{
	return (x == point.x && y == point.y);
}
