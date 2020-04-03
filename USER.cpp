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

#include"USER.h"


USER::USER(int player_number, std::string name, Gtk::Box* parent_box, Gtk::Orientation orientation, int spacing) :
PLAYER(player_number, name, parent_box, orientation, spacing)
{
	_user_game_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL));
	this->pack_start(*_user_game_box);
	_chip_box = new CHIP_BOX(_user_game_box);

	//TESTING
	_chip_box->add_chips(0, 0, 0);

	_player_cards_and_action_buttons_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
	_user_game_box->pack_start(*_player_cards_and_action_buttons_box);
	_player_cards_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL));
	_user_game_box->pack_start(*_player_cards_box);
	_player_actions_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL));
	_user_game_box->pack_start(*_player_actions_box);
}


USER::~USER()
{
	delete _chip_box;
}