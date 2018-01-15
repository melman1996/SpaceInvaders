#pragma once
#include "Point.h"

class Buffer
{
private:
	static std::vector<std::vector<char>> mBufferArray;
public:
	Buffer();
	~Buffer();
	
	static void setWindow(int, int);
	static void moveBuffer(int, int);
	static void moveBuffer(std::shared_ptr<Point>&);
	static void write(std::shared_ptr<Point>&, char);
	static void write(std::shared_ptr<Point>&, std::string);
	static char read(std::shared_ptr<Point>&);
};

