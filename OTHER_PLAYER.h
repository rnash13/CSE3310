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
#include"PLAYER.h"

class OTHER_PLAYER : public PLAYER
{
	public:
		OTHER_PLAYER(std::string, Gtk::Box*);

		void assign_cards(std::vector<std::string> card_labels);
		void change_chip_amount(int amount);

	private:
		Gtk::Box* _player_box;
		Gtk::Label* _chip_amount_label;

		int _current_chip_amount;
		CARD* _player_cards[5];
};

#endif