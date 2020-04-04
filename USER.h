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


#ifndef _USER_
#define _USER_

#include<gtkmm.h>

#include"CARD.h"
#include"CHIP_BOX.h"
#include"CARD_PLAYER.h"

class USER : public CARD_PLAYER
{
	public:
		USER(int, std::string, Gtk::Box*, Gtk::Orientation=Gtk::ORIENTATION_VERTICAL, int=0);
		~USER();

		// ————————————— GAME FUNCTIONS —————————————
		void remove_cards(std::vector<std::string>);


		// ———————————— DISPLAY FUNCTIONS —————————————
		void hide_user_actions();
		void show_user_actions();

		// ———————————— BUTTONS FUNCTIONS ————————————
		void fold();
		void check();

	private:
		// ———————————————— GUI —————————————————
		Gtk::Box* _player_actions_box;
		Gtk::Button* _bet_button;
		Gtk::Button* _check_button;
		Gtk::Button* _fold_button;
		Gtk::Button* _trade_button;
		// button bet
		// button check
		// button fold
		// trade
};

#endif