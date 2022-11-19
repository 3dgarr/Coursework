#pragma once

#include <unistd.h>

using my_map = std::vector<std::string>;

typedef struct s_board
{
	int				x_max;
	int				y_max;
	my_map			map;
	WINDOW			*game_board;
	WINDOW			*score_board;
	unsigned int	score;

}	t_board;

class Pacman
{
	private:
		int		y_cor;
		int		x_cor;
		int		go_to_dir(char &cur_location, char	&next_location, char player, int x, int y, t_board &board);
		void	set_xy(int y,  int x);
	public:
		Pacman(int y, int x);
		Pacman();
		void	get_pac_cors(my_map map);
		void	go_direction(t_board &board);
		int		get_x() const;
		int		get_y() const;
		~Pacman();
};

