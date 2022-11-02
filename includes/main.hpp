#pragma once
#include <iostream>
#include <ncurses.h>
#include <string>
#include "map.hpp"
#include "pac.hpp"

void	render_map(t_board &board);

// using my_map = std::vector<std::string>;

// typedef struct s_board
// {
// 	int		y_max;
// 	int		x_max;
// 	my_map	map;
// 	WINDOW	*game_board;

// }	t_board;
