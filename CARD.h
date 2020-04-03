
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
		CARD(std::string, Gtk::Box*);
		~CARD();

		Gtk::Image* image();
		void image(std::string);
		void image(std::string name, Gtk::Box*);


		std::string name();
		void name(std::string);

	private:
		std::string _name;
		Gtk::Image* _image;
		Gtk::Box* _box;
};

#endif