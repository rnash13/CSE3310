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

class PLAYER : public Gtk::Box
{
	public:
		PLAYER(int, std::string, Gtk::Box*, Gtk::Orientation=Gtk::ORIENTATION_VERTICAL, int=0);
		~PLAYER();

		Gtk::Label* name_label();
		void name_label(std::string);

		virtual void display_card_backs() {}

	private:
		int _player_number;
		std::string _name;

		Gtk::Label* _name_label;
		Gtk::Box* _parent_box;
};

#endif
