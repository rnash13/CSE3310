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

#include"PLAYER.h"

PLAYER::PLAYER(std::string name, Gtk::Box* player_box) :
_name{name}, _player_box{player_box}
{
	_name_label = Gtk::manage(new Gtk::Label(Glib::ustring(name)));
	_player_box->pack_start(*_name_label, Gtk::PACK_SHRINK, 50);
}

Gtk::Label* PLAYER::name_label()
{
	return _name_label;
}

Gtk::Box* PLAYER::player_box()
{
	return _player_box;
}
