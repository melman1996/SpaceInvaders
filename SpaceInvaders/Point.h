#pragma once
class Point
{
public:
	int x, y;
	Point(int, int);
	~Point();

	bool operator==(const Point &) const;
};

