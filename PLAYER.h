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


#ifndef _PLAYER_
#define _PLAYER_

#include<gtkmm.h>

class PLAYER
{
	public:
		PLAYER(std::string, Gtk::Box*);

		Gtk::Label* name_label();
		void name_label(Gtk::Label*);

		Gtk::Box* player_box();
		void player_box(Gtk::Box*);

	private:
		std::string _name;

		Gtk::Label* _name_label;
		Gtk::Box* _player_box;
};

#endif