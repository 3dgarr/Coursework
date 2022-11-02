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

void	Pacman::go_direction(t_board &board, int direction)
{
	my_map &map = board.map;
	/*ste petqa while(1)*/
		switch (direction)
		{
			case KEY_RIGHT:
				while (go_to_dir(map[y_cor][x_cor], map[y_cor][x_cor + 1], '<', x_cor + 1, y_cor))
				{
					usleep(10 * 2000);
					render_map(board);
					wrefresh(board.game_board);
				}
				break;
			case KEY_LEFT:
				while (go_to_dir(map[y_cor][x_cor], map[y_cor][x_cor - 1], '>', x_cor - 1, y_cor))
				{
					usleep(10 * 2000);
					render_map(board);
					wrefresh(board.game_board);
				}
				break;
			case KEY_UP:
				while (go_to_dir(map[y_cor][x_cor], map[y_cor - 1][x_cor], 'v', x_cor, y_cor - 1))
				{
					usleep(10 * 2000);
					render_map(board);
					wrefresh(board.game_board);
				}
				break;
			case KEY_DOWN:
				while (go_to_dir(map[y_cor][x_cor], map[y_cor + 1][x_cor], '^', x_cor, y_cor + 1))
				{
					usleep(10 * 2000);
					render_map(board);
					wrefresh(board.game_board);
				}
				break;		
			default:
				break;
		}
}

int	Pacman::go_to_dir(char &cur_location, char	&next_location, char player, int x, int y)
{
	if (next_location == '#')
		return 0;
	cur_location = ' ';
	next_location = player;
	set_xy(y, x);
	return 1;
}

