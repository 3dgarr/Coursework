#pragma once

#include "main.hpp"
#include "board.hpp"
#include "pac.hpp"


class Game
{
	private:
		Pacman		pac;
		t_board		board;
	public:
		Game();
		~Game();
		void	render_map(t_board &board);
		void	init_screen_and_setup();
		void 	init_score_board(t_board &board);
		void	init_box_and_map(t_board &board);
		void	init_game();
		t_board	get_board();
		void	start_game();
};