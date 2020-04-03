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

#include"CHIP.h"


CHIP::CHIP(int stack_size, Gtk::Box* chip_box) :
_stack_size{stack_size}, _chip_box{chip_box}
{
	// add Gtk stuff to _chip_box
	Glib::RefPtr<Gdk::Pixbuf> tmp = Gdk::Pixbuf::create_from_file("./test_white_chip.jpg", 75, 75, false);
	_image = Gtk::manage(new Gtk::Image{tmp});
	_chip_box->pack_start(*_image);
}


CHIP::~CHIP()
{
	// remove Gtk stuff from parent
}