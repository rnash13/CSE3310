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


CARD::CARD(std::string name, Gtk::Box* box, bool shrink) : 
_name{name}
{
	_parent_box = box;
	image(_name, shrink);
}


CARD::CARD(std::string name, Gtk::Box* box, int crop_to_value, bool shrink) : 
_name{name}
{
	_parent_box = box;
	image(_name, crop_to_value, shrink);
}


CARD::CARD(std::string name, Gtk::Box* box, int width, int height, bool shrink) : 
_name{name}
{
	_parent_box = box;
	image(_name, width, height, shrink);
}


CARD::~CARD()
{
	_parent_box->remove(*_image);
}


Gtk::Image* CARD::image()
{
	return _image;
}


void CARD::image(std::string name, bool shrink)
{
	std::string image_name = CARDS_IMG_PATH+CARD_NAMES_AND_IMAGES[name];
	Glib::RefPtr<Gdk::Pixbuf> tmp = Gdk::Pixbuf::create_from_file(image_name, 125, 200, false);
	_image = Gtk::manage(new Gtk::Image{tmp});
	if(shrink) _parent_box->pack_start(*_image, Gtk::PACK_SHRINK);
	else _parent_box->pack_start(*_image);
}


void CARD::image(std::string name, int crop_to_value, bool shrink)
{
	std::string image_name = CARDS_IMG_PATH+CARD_NAMES_AND_IMAGES[name];
	Glib::RefPtr<Gdk::Pixbuf> tmp = Gdk::Pixbuf::create_from_file(image_name, 125, 200, false);
	tmp = Gdk::Pixbuf::create_subpixbuf(tmp, 0, 0, crop_to_value, 200);
	_image = Gtk::manage(new Gtk::Image{tmp});
	if(shrink) _parent_box->pack_start(*_image, Gtk::PACK_SHRINK);
	else _parent_box->pack_start(*_image);
}


void CARD::image(std::string name, int width, int height, bool shrink)
{
	std::string image_name = CARDS_IMG_PATH+CARD_NAMES_AND_IMAGES[name];
	Glib::RefPtr<Gdk::Pixbuf> tmp = Gdk::Pixbuf::create_from_file(image_name, width, height, false);
	_image = Gtk::manage(new Gtk::Image{tmp});
	if(shrink) _parent_box->pack_start(*_image, Gtk::PACK_SHRINK);
	else _parent_box->pack_start(*_image);
}


std::string CARD::name()
{
	return _name;
}

void CARD::name(std::string name)
{
	_name = name;
}