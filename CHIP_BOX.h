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


#ifndef _CHIP_BOX_
#define _CHIP_BOX_

#include<gtkmm.h>

#include"CHIP.h"
#include"GLOBAL.h"

class CHIP_BOX : public Gtk::Box
{
	public:
		CHIP_BOX(Gtk::Box*, Gtk::Orientation=Gtk::ORIENTATION_VERTICAL, int=0);
		CHIP_BOX(int, Gtk::Box*, Gtk::Orientation=Gtk::ORIENTATION_VERTICAL, int=0);
		~CHIP_BOX();

		int current_value();

		void add_chips(int, int, int);
		void remove_chips(int);

		int white_chip_count();
		int red_chip_count();
		int blue_chip_count();

		Gtk::Box* parent_box();

	private:
		int _current_chip_value=DEFAULT_CHIP_AMOUNT;

		std::vector<CHIP*> _white_chips;
		std::vector<CHIP*> _red_chips;
		std::vector<CHIP*> _blue_chips;

		// Gtk stuff
		Gtk::Box* _parent_box;

		Gtk::Label* _chip_amount_label;
		Gtk::Box* _chip_stacks_box;  // holds chips horizontally
};

#endif