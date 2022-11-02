#include <iostream>
#include <ncurses.h>
#include <string>
using namespace std;

int main()
{	
	initscr();
	cbreak();
	noecho();

	int	y_max, x_max;

	getmaxyx(stdscr, y_max, x_max);

	WINDOW *menu_win = newwin(6, x_max/2, y_max/2, 5);
	box(menu_win, 0, 0);
	refresh();
	wrefresh(menu_win);
	keypad(menu_win, true);

	string	menu_items[3] = {"Start game", "Information", "Exit"};
	int	choice;
	int	highlighted_item = 0;
	
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{	
			if (i == highlighted_item)
				wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, i + 1, 1, menu_items[i].c_str());
			wattroff(menu_win, A_REVERSE);
		}
		choice = wgetch(menu_win);
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
			printw("Your choice is %s\n", menu_items[highlighted_item].c_str());
			refresh();	
		}

	}
	

	getch();
	endwin();

	return (0);
}