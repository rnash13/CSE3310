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

PLAYER::PLAYER(int player_number, std::string name, Gtk::Box* parent_box, Gtk::Orientation orientation, int spacing) :
Gtk::Box(orientation, spacing)
{
	_player_number = player_number;
	_name = name;
	_parent_box = parent_box;

	_parent_box->pack_start(*this);

	_name_label = Gtk::manage(new Gtk::Label(Glib::ustring(name)));
	this->pack_start(*_name_label);
}

PLAYER::~PLAYER()
{
	this->remove(*_name_label);
}


Gtk::Label* PLAYER::name_label()
{
	return _name_label;
}


void PLAYER::name_label(std::string name)
{
	this->remove(*_name_label);
	_name_label = Gtk::manage(new Gtk::Label(Glib::ustring(name)));
	this->pack_start(*_name_label);
}
