#pragma once
#include "board.hpp"

class Pacman
{
	private:
		int		y_cor;
		int		x_cor;
		int		default_direction;
		int		go_to_dir(char &cur_location, char	&next_location, char player, int x, int y, t_board &board);
		void	set_xy(int y,  int x);
	public:
		Pacman(int y, int x);
		Pacman();
		void	get_pac_cors(my_map map);
		bool	go_direction(t_board &board);
		int		get_direction(t_board &board);
		int		get_x() const;
		int		get_y() const;
		void	set_direction(int key_code);
		void	render_map(t_board &board);

		~Pacman();
};

