#include "../includes/menu.hpp"
#include "../includes/game.hpp"


Menu::Menu()
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	choice = 0;
	highlighted_item = 0;
	menu_items = {"Start game", "Information", "Exit"};
	getmaxyx(stdscr, y_max, x_max);
}


Menu::~Menu()
{
	
}

void	Menu::setup_menu()
{
	menu_win = newwin(6, x_max/2, y_max/2, 5);
	box(menu_win, 0, 0);
	refresh();
	wrefresh(menu_win);
	keypad(menu_win, true);
	noecho();
}

void	Menu::render_menu()
{
	for (int i = 0; i < 3; i++)
	{	
		if (i == highlighted_item)
			wattron(menu_win, A_REVERSE);
		mvwprintw(menu_win, i + 1, 1, "%s", menu_items[i].c_str());
		wattroff(menu_win, A_REVERSE);
	}
}
void	Menu::make_decision(int choice, Game &game)
{
	switch (choice)
	{
		case KEY_UP:
			highlighted_item--;
			if (highlighted_item == -1)
				highlighted_item = 0;
			break;
		case KEY_DOWN:
			highlighted_item++;
			if (highlighted_item == 3)
				highlighted_item = 2;
			break;		
		default:
			break;
	}
	if (choice == 10)//for Enter
	{
		if (highlighted_item == 0)
		{
			wclear(menu_win);
			erase();
			endwin();
			game.init_game();
			game.start_game();
	
		}
		if (highlighted_item == 1)
		{
			erase();
			printw("Dont judge me, it is my first time\n");
			while (true)
			{
				char esc = getch();
				if (esc == 27)//esc
				{
					erase();
					break;
				}
			}
			return;
			
		}

		if (highlighted_item == 2)
		{
			endwin();
			exit (0);
		}

		refresh();	
	}

}

void	Menu::init_menu()
{
	Game	game;
	while (true)
	{
		setup_menu();	
		render_menu();
		choice = wgetch(menu_win);
		make_decision(choice, game);
	}
}