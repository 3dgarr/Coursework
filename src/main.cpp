#include <thread>
#include "../includes/main.hpp"
#include "../includes/game.hpp"

// void	render_map(t_board &board)
// {
// 	for (size_t i = 0; i < board.map.size(); i++)
// 		mvprintw(i + board.y_max/4, board.x_max/4, "%s", board.map[i].c_str());
// 	refresh();
// }

// void	init_screen_and_setup()
// {
// 	initscr();
// 	cbreak();
// 	noecho();
// 	curs_set(0);
// 	nodelay(stdscr, TRUE);
// }

// void init_score_board(t_board &board)
// {
// 	board.score_board =  newwin(5, 20, board.y_max/4-5 , board.x_max/4 -1);
// 	box(board.score_board, 0, 0);
// 	wrefresh(board.score_board);
// 	mvprintw(board.y_max/4-5 , board.x_max/4 -1 ,"SCORE");
// 	mvprintw(board.y_max/4-3 , board.x_max/4, "%d", board.score);
// 	wrefresh(board.score_board);

// 	refresh();
// }

// void	init_box_and_map(t_board &board)
// {
// 	board.map = get_map();
// 	getmaxyx(stdscr, board.y_max, board.x_max);
// 	board.game_board = newwin(board.map.size() + 2, board.map[1].length() + 2, board.y_max/4 - 1, board.x_max/4 - 1);
// 	box(board.game_board, 0, 0);
// 	refresh();
// 	keypad(board.game_board, true);
// 	wrefresh(board.game_board);
// 	init_score_board(board);
// 	nodelay(board.game_board, TRUE);
// }

int main()
{	
	Game		game;
	// Pacman		pac;
	// t_board		board;
	


	// init_screen_and_setup();
	// init_box_and_map(board);
	game.init_game();
	game.start_game();
	return (0);
}