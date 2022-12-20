#pragma once
#include <string>
#include "./main.hpp"
#include "./game.hpp"


class Menu
{
	private:
		int							x_max;
		int							y_max;
		WINDOW						*menu_win;
		WINDOW						*information;
		std::vector<std::string>	menu_items;
		int							choice;
		int							highlighted_item;

	public:
		Menu();
		~Menu();
		void	init_menu();
		void	init_information();
		void	setup_menu();
		void	render_menu();
		void	make_decision(int choice, Game &game);


};

