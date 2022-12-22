#pragma once
#include "board.hpp"

constexpr	int	ESC = 27;
class Pacman
{
	private:
		int				y_cor;
		int				x_cor;
		int				default_direction;
		int				go_to_dir(char &cur_location, char	&next_location, char player, int x, int y, t_board &board, unsigned int max_score);
		void			set_xy(int y,  int x);
	public:
		Pacman();
		bool			go_direction(t_board &board, unsigned int max_score);
		void			render_map(t_board &board);
		void			get_pac_cors(my_map map);
		int				get_direction(t_board &board);
		void			finish_game(t_board	&board, std::string msg);
		~Pacman();
};

