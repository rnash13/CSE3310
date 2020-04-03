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

#include"CARD.h"


CARD::CARD(std::string name, Gtk::Box* box) : 
_name{name}
{
	_box = box;

	std::string image_name = IMG_PATH+CARD_NAMES_AND_IMAGES[name];
	Glib::RefPtr<Gdk::Pixbuf> tmp = Gdk::Pixbuf::create_from_file(image_name, 125, 200, false);
	_image = Gtk::manage(new Gtk::Image{tmp});
	_box->pack_start(*_image);
}


CARD::~CARD()
{
	_box->remove(*_image);
}


Gtk::Image* CARD::image()
{
	return _image;
}


void CARD::image(std::string name)
{
	std::string image_name = IMG_PATH+CARD_NAMES_AND_IMAGES[name];
	Glib::RefPtr<Gdk::Pixbuf> tmp = Gdk::Pixbuf::create_from_file(image_name, 125, 200, false);
	_image = Gtk::manage(new Gtk::Image{tmp});
	_box->pack_start(*_image);
}


void CARD::image(std::string name, Gtk::Box* box)
{
	_box = box;

	std::string image_name = IMG_PATH+CARD_NAMES_AND_IMAGES[name];
	Glib::RefPtr<Gdk::Pixbuf> tmp = Gdk::Pixbuf::create_from_file(image_name, 125, 200, false);
	_image = Gtk::manage(new Gtk::Image{tmp});
	_box->pack_start(*_image);
}


std::string CARD::name()
{
	return _name;
}

void CARD::name(std::string name)
{
	_name = name;
}