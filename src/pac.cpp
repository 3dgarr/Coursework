#include "../includes/main.hpp"

Pacman::Pacman()
{
	x_cor = 0;
	y_cor = 0;
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

int	is_key(int direction)
{
	return (direction == KEY_RIGHT || direction == KEY_DOWN || direction == KEY_LEFT || direction == KEY_UP);
}

void	Pacman::go_direction(t_board &board)
{
	int direction;

	get_pac_cors(board.map);
	direction = wgetch(board.game_board);
	my_map &map = board.map;
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
		mvprintw(board.y_max/4 - 3 , board.x_max/4, "%d", board.score);
	}
	cur_location = ' ';
	next_location = player;
	set_xy(y, x);
	usleep(20000);
	render_map(board);
	wrefresh(board.game_board);
	wrefresh(board.score_board);
	return 1;
}

