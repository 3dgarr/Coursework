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

int	Pacman::get_x() const
{
	return (x_cor);
}

int	Pacman::get_y() const
{
	return (y_cor);
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

void	Pacman::go_direction(t_board &board)
{
	my_map	&map = board.map;
	int		direction = get_direction(board);

	get_pac_cors(board.map);
	switch (direction)
	{
		case KEY_RIGHT:
			go_to_dir(map[y_cor][x_cor], map[y_cor][x_cor + 1], '<', x_cor + 1, y_cor, board);
			break;
		case KEY_LEFT:
			go_to_dir(map[y_cor][x_cor], map[y_cor][x_cor - 1], '>', x_cor - 1, y_cor, board);
			break;
		case KEY_UP:
			go_to_dir(map[y_cor][x_cor], map[y_cor - 1][x_cor], 'v', x_cor, y_cor - 1, board);
			break;
		case KEY_DOWN:
			go_to_dir(map[y_cor][x_cor], map[y_cor + 1][x_cor], '^', x_cor, y_cor + 1, board);
			break;		
		default:
			break;
	}
}

int	Pacman::go_to_dir(char &cur_location, char	&next_location, char player, int x, int y, t_board &board)
{
	if (next_location == '#')
		return 0;
	if (next_location == '.')
	{
		board.score += 10;
		mvprintw(board.y_max/4 - 2 , board.x_max/4, "%d", board.score);
	}
	cur_location = ' ';
	next_location = player;
	set_xy(y, x);
	usleep(80000);
	render_map(board);
	wrefresh(board.game_board);
	wrefresh(board.score_board);
	return 1;
}


void Pacman::render_map(t_board &board)
{
	for (size_t i = 0; i < board.map.size(); i++)
		mvprintw(i + board.y_max/4, board.x_max/4, "%s", board.map[i].c_str());
	refresh();
}
