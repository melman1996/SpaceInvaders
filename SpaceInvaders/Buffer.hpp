#pragma once
#include "stdafx.h"

namespace buffer {
	void write(int x, int y, char z) {
		moveBuffer(x, y);
		std::cout << z;
	}
	void write(int x, int y, std::string z) {
		moveBuffer(x, y);
		std::cout << z;
	}
}