#include "../includes/main.hpp"

Pacman::Pacman()
{
	x_cor = 0;
	y_cor = 0;
	default_direction = KEY_RIGHT;
}

Pacman::~Pacman()
{

}

void Pacman::set_xy(int y, int x)
{
	x_cor = x;
	y_cor = y;
}

void	Pacman::get_pac_cors(my_map map)
{
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == '<')
			{
				set_xy(i, j);
				break;
			}
		}
	}
}


int	Pacman::get_direction(t_board &board)
{
	int		direction;

	direction = wgetch(board.game_board);
	if (direction < 0)
		direction = default_direction;
	else
		default_direction = direction;
	return (direction);

}

bool	Pacman::go_direction(t_board &board,  unsigned int max_score)
{
	my_map	&map = board.map;
	int		direction = get_direction(board);

	get_pac_cors(board.map);
	switch (direction)
	{
		case KEY_RIGHT:
			go_to_dir(map[y_cor][x_cor], map[y_cor][x_cor + 1], '<', x_cor + 1, y_cor, board, max_score);
			break;
		case KEY_LEFT:
			go_to_dir(map[y_cor][x_cor], map[y_cor][x_cor - 1], '>', x_cor - 1, y_cor, board, max_score);
			break;
		case KEY_UP:
			go_to_dir(map[y_cor][x_cor], map[y_cor - 1][x_cor], 'v', x_cor, y_cor - 1, board, max_score);
			break;
		case KEY_DOWN:
			go_to_dir(map[y_cor][x_cor], map[y_cor + 1][x_cor], '^', x_cor, y_cor + 1, board, max_score);
			break;	
		case ESC :
			board.score = 0;
			return true;	
		default:
			break;
	}
	return false;
}

int	Pacman::go_to_dir(char &cur_location, char	&next_location, char player, int x, int y, t_board &board, unsigned int max_score)
{
	if (next_location == '#')
		return 0;
	if (next_location == '.')
	{
		board.score += 10;
		mvprintw(board.y_max/4 - 2 , board.x_max/4, "%d", board.score);
	}
	if (next_location == '@')
		finish_game(board, (char *)"GAME OVER!");
	cur_location = ' ';
	next_location = player;
	set_xy(y, x);
	usleep(80000);
	render_map(board);
	wrefresh(board.game_board);
	wrefresh(board.score_board);
	if (board.score == max_score * 10)
		finish_game(board, (char *)"YOU WON !!");
	return (1);
}


void Pacman::render_map(t_board &board)
{
	for (size_t i = 0; i < board.map.size(); i++)
		mvprintw(i + board.y_max/4, board.x_max/4, "%s", board.map[i].c_str());
	refresh();
}

void	Pacman::finish_game(t_board	&board, char *msg)
{
	wattron(stdscr, A_REVERSE);
	mvprintw(board.y_max/4 - 2 , board.x_max/2-10, "%s",  msg);
	wattroff(stdscr, A_REVERSE);
	refresh();
	sleep(2);
	endwin();
	exit(0);
}


