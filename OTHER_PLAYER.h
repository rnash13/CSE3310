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


#ifndef _OTHER_PLAYER_
#define _OTHER_PLAYER_

#include<gtkmm.h>

#include"CARD.h"
#include"CHIP_BOX.h"
#include"PLAYER.h"

class OTHER_PLAYER : public PLAYER
{
	public:
		OTHER_PLAYER(int, std::string, Gtk::Box*, Gtk::Orientation=Gtk::ORIENTATION_VERTICAL, int=0);
		~OTHER_PLAYER();

		void assign_cards(std::vector<std::string> card_labels);
		void change_chip_amount(int amount);

	private:
		Gtk::Label* _chip_amount_label;

		// CARD_BOX* _card_box;  // managed by this
		CARD* _player_cards[5];
		int _current_chip_amount;
		CHIP_BOX* _chip_box;
};

#endif