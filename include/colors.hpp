#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

enum colors {
	black = 0,
	red = 1,
	green = 2,
	yellow = 3,
	blue = 4,
	magenta = 5,
	cyan = 6,
	white = 7
};

std::string fg(int color);

std::string bg(int color);

std::string reset_prompt();

#endif