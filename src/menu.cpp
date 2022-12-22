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
	menu_win = newwin(6, x_max/2 - 70, y_max/2 - 3, x_max/2-30);
}


Menu::~Menu()
{
	
}

void	Menu::setup_menu()
{
	erase();
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
void	Menu::make_decision(int choice)
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
	if (choice == ENTER)
	{
		if (highlighted_item == 0)
		{
			Game	game;
			erase();
			game.start_game();
	
		}
		if (highlighted_item == 1)
		{
			init_information();
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

void	Menu::init_information()
{
	int	esc;
	erase();
	
	information = newwin(13, x_max/4 , y_max/2 - 7, 60);
	box(information, 0, 0);
	refresh();
	mvprintw(y_max / 2 - 6, 75, "INSTRUCTIONS");
	mvprintw(y_max / 2 - 4, 65, "Arrow up    -> pac goes up");
	mvprintw(y_max / 2 - 3, 65, "Arrow down  -> pac goes down");
	mvprintw(y_max / 2 - 2, 65, "Arrow left  -> pac goes left");
	mvprintw(y_max / 2 - 1, 65, "Arrow right -> pac goes right");
	mvprintw(y_max / 2    , 65, "ESC         -> back to menu");
	mvprintw(y_max / 2 + 1, 61, "__________________________________________________");
	mvprintw(y_max / 2 + 3, 65, "This game is created by Edgar Ghazaryan");
	mvprintw(y_max / 2 + 4, 65, "Synopsys Armenia: 2022");
	wrefresh(information);
	refresh();
	while (true)
	{
		esc = wgetch(information);
		if (esc == ESC)//esc
		{
			erase();
			wrefresh(information);
			refresh();
			return;	
		}
	}
}

void	Menu::init_menu()
{
	while (true)
	{
		setup_menu();	
		render_menu();
		choice = wgetch(menu_win);
		make_decision(choice);
	}
}