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
		void	init_screen_and_setup();
		void 	init_score_board(t_board &board);
		void	init_box_and_map(t_board &board);
		void	init_game();
		void	start_game();
		void	render_map(t_board &board);
};