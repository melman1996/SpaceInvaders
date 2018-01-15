#include "stdafx.h"
#include "Buffer.h"

std::vector<std::vector<char>> Buffer::mBufferArray = {};

Buffer::Buffer()
{
}


Buffer::~Buffer()
{
}

void Buffer::setWindow(int x, int y)
{
	_COORD coord;
	coord.X = x;
	coord.Y = y;

	for (int i = 0; i < x; i++) {
		std::vector<char> tmp;
		for (int j = 0; j < y; j++)
			tmp.push_back(' ');
		mBufferArray.push_back(tmp);
	}

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = x - 1;
	Rect.Right = y - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void Buffer::moveBuffer(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Buffer::moveBuffer(std::shared_ptr<Point> & point)
{
	COORD coord;
	coord.X = point->x;
	coord.Y = point->y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Buffer::write(std::shared_ptr<Point> & point, char z)
{
	moveBuffer(point);
	std::cout << z;
	mBufferArray[point->x][point->y] = z;
}

void Buffer::write(std::shared_ptr<Point> & point, std::string z)
{
	moveBuffer(point);
	std::cout << z;
	for (char character : z) {
		mBufferArray[point->x][point->y] = character;
	}
}

char Buffer::read(std::shared_ptr<Point> & point)
{
	return mBufferArray[point->x][point->y];
}
