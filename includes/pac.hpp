#pragma once

#include <unistd.h>

using my_map = std::vector<std::string>;

typedef struct s_board
{
	int		y_max;
	int		x_max;
	my_map	map;
	WINDOW	*game_board;

}	t_board;

class Pacman
{
	private:
		int		y_cor;
		int		x_cor;
		int		go_to_dir(char &cur_location, char	&next_location, char player, int x, int y);
		void	set_xy(int y,  int x);
	public:
		Pacman(int y, int x);
		Pacman();
		void	get_pac_cors(my_map map);
		void	go_direction(t_board &board, int direction);
		int		get_x() const;
		int		get_y() const;
		~Pacman();
};

