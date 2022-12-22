#pragma once
#include <iostream>
#include <vector>

using my_map = std::vector<std::string>;

typedef struct s_board
{
	int				x_max;
	int				y_max;
	my_map			map;
	WINDOW			*game_board;
	WINDOW			*score_board;
	unsigned int	score;
	unsigned int	max_score;
}	t_board;
