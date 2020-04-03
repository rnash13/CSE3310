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

#include"CARD.h"
#include"OTHER_PLAYER.h"
#include"PLAYER.h"
#include"USER.h"

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
		void assign_player_to_all_players_array(int, std::string);

	private:
		int _total_players = 1;
		PLAYER* all_players[6] = {};

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
		USER* user;
		Gtk::Box* bottom_row_box;
		

		// Gtk::Box* user_display;
		// Gtk::Box* chips_box;
		// Gtk::Box* cards_and_chips_box;
		// Gtk::Box* card_box;
		// CARD player_cards[5];
		// Gtk::Box* option_box;
};

#endif