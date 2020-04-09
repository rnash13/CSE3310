
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

#ifndef _CARD_
#define _CARD_

#include<gtkmm.h>

#include"GLOBAL.h"


class CARD
{
	public:
		CARD(std::string, Gtk::Box*, bool=false);
		CARD(std::string, Gtk::Box*, int, bool=false);
		CARD(std::string, Gtk::Box*, int, int, bool=false);
		~CARD();

		Gtk::Image* image();
		void image(std::string, bool);
		void image(std::string, int, bool);
		void image(std::string, int, int, bool);

		std::string name();
		void name(std::string);

	private:
		std::string _name;
		Gtk::Image* _image;
		Gtk::Box* _parent_box;
};

#endif
