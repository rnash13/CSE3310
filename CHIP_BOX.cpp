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

#include"CHIP_BOX.h"


CHIP_BOX::CHIP_BOX(Gtk::Box* parent_box, Gtk::Orientation orientation, int spacing) :
Gtk::Box(orientation, spacing)
{
	_parent_box = parent_box;
	_parent_box->pack_start(*this);

	_chip_amount_label = Gtk::manage(new Gtk::Label(Glib::ustring(std::to_string(_current_chip_value))));
	this->pack_start(*_chip_amount_label);

	_chip_stacks_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL));
	this->pack_start(*_chip_stacks_box);
}


CHIP_BOX::CHIP_BOX(int start_chips, Gtk::Box* parent_box, Gtk::Orientation orientation, int spacing) :
Gtk::Box(orientation, spacing)
{
	_current_chip_value = start_chips;

	_parent_box = parent_box;
	_parent_box->pack_start(*this);

	_chip_amount_label = Gtk::manage(new Gtk::Label(Glib::ustring(std::to_string(_current_chip_value))));
	this->pack_start(*_chip_amount_label);

	_chip_stacks_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL));
	this->pack_start(*_chip_stacks_box);
}


CHIP_BOX::~CHIP_BOX()
{
	//TODO: change so it uses delete
	for(int x = _white_chips.size() - 1; x > -1; x--) _white_chips.erase(_white_chips.begin() + x);
	for(int x = _red_chips.size() - 1; x > -1; x--) _red_chips.erase(_red_chips.begin() + x);
	for(int x = _blue_chips.size() - 1; x > -1; x--) _blue_chips.erase(_blue_chips.begin() + x);

	_parent_box->remove(*this);
}




int CHIP_BOX::current_value()
{
	return _current_chip_value;
}


void CHIP_BOX::add_chips(int white, int red, int blue)
{
	//TESTING: replace with stacks of chips
	_white_chips.push_back(new CHIP(1, _chip_stacks_box));
}


void CHIP_BOX::remove_chips(int amount)
{

}


int CHIP_BOX::white_chip_count()
{
	return _white_chips.size();
}


int CHIP_BOX::red_chip_count()
{
	return _red_chips.size();

}


int CHIP_BOX::blue_chip_count()
{
	return _blue_chips.size();
}


Gtk::Box* CHIP_BOX::parent_box()
{
	return _parent_box;
}