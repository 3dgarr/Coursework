#include "../includes/main.hpp"

void	render_map(t_board &board)
{
	for (size_t i = 0; i < board.map.size(); i++)
	{
		mvprintw(i + board.y_max/4, board.x_max/4, board.map[i].c_str());

	}
	refresh();
}

void	init_screen_and_setup()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	// nodelay(stdscr, TRUE);
}

void	init_box_and_map(t_board &board)
{
	board.map = get_map();
	getmaxyx(stdscr, board.y_max, board.x_max);
	board.game_board = newwin(board.map.size() + 2, board.map[1].length() + 2, board.y_max/4 - 1, board.x_max/4 - 1);
	box(board.game_board, 0, 0);
	refresh();
	keypad(board.game_board, true);
	wrefresh(board.game_board);
}

void	get_direction(t_board board, int	&direction)
{
	direction = wgetch(board.game_board);
}


int main()
{	
	Pacman		pac;
	t_board		board;
	int			direction;	

	init_screen_and_setup();
	init_box_and_map(board);
	while (1)
	{
		render_map(board); 
		pac.get_pac_cors(board.map);
		get_direction(board, direction);
		pac.go_direction(board, direction);
		refresh();
		wrefresh(board.game_board);
	}

	endwin();

	return (0);
}