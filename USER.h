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

#include"CHIP_BOX.h"
#include"PLAYER.h"

class USER : public PLAYER
{
	public:
		USER(int, std::string, Gtk::Box*, Gtk::Orientation=Gtk::ORIENTATION_VERTICAL, int=0);
		~USER();

	private:
		Gtk::Box* _user_game_box;

		CHIP_BOX* _chip_box;

		Gtk::Box* _player_cards_and_action_buttons_box;
		Gtk::Box* _player_cards_box;
		Gtk::Box* _player_actions_box;
};

#endif