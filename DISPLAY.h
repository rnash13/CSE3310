// 1000845009	Mathew Zinke

/***********************************************************************************************************
*
*	created by: MPZinke
*	on ..
*
*	DESCRIPTION:
*	BUGS:
*	FUTURE:
*
***********************************************************************************************************/


#ifndef _CLIENT_GUI_DISPLAY_
#define _CLIENT_GUI_DISPLAY_

#include<gtkmm.h>

#include"PLAYER.h"
#include"OTHER_PLAYER.h"
#include"CARD.h"

class DISPLAY: public Gtk::Window
{
	public:
		DISPLAY(int player_number);
		~DISPLAY();

		void add_cards_to_player(std::vector<std::string> card_names);
		void clear_all_cards_from_player();
		void remove_cards_from_player(std::vector<std::string> card_names);

		// ————————————— OBJECT CREATION —————————————
		void assign_players_to_all_players_array();
		void assign_player_to_all_players_array(std::string, int);

	private:
		int _total_players = 1;
		PLAYER* all_players[6] = {};


		Gdk::RGBA* COLOR_RED = new Gdk::RGBA("#DD0000");
		Gdk::RGBA* COLOR_GREEN = new Gdk::RGBA("#009900");
		Gdk::RGBA* COLOR_BLUE = new Gdk::RGBA("#000099");
		Gdk::RGBA* COLOR_WHITE = new Gdk::RGBA("#FFFFFF");
		Gdk::RGBA* COLOR_BLACK = new Gdk::RGBA("#000000");

		Gtk::Box* main_box;

		// ———————————— OTHER PLAYERS & POT ————————————

		// —————— GUI ——————
		// ———— TOP ROW ————
		Gtk::Box* top_row_box;
		// —— CELLS ——
		Gtk::Box* top_left_box;
		Gtk::Box* top_center_box;
		Gtk::Box* top_right_box;

		// ———— MIDDLE ROW ————
		Gtk::Box* middle_row;
		// —— CELLS ——
		Gtk::Box* middle_left_box;
		Gtk::Box* pot_box;
		Gtk::Box* middle_right_box;

		// ————  ————
		Gtk::Label* pot_label;

		// ———————————————— PLAYER ————————————————	
		int _player_number;

		// ———— BOTTOM ROW ————
		Gtk::Box* bottom_row_box;
		// —— CELLS ——
		Gtk::Box* player_chips_box;
		Gtk::Box* player_cards_and_action_buttons_box;
		Gtk::Box* player_cards_box;
		Gtk::Box* player_actions_box;

		// Gtk::Box* user_display;
		// Gtk::Box* chips_box;
		// Gtk::Box* cards_and_chips_box;
		// Gtk::Box* card_box;
		// CARD player_cards[5];
		// Gtk::Box* option_box;
};

#endif