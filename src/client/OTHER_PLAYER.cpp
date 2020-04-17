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

#include"OTHER_PLAYER.h"

#include<iostream>

OTHER_PLAYER::OTHER_PLAYER(	int player_number, std::string name,
                            Gtk::Box* parent_box, Gtk::Orientation orientation,
                            int spacing
                          ) : CARD_PLAYER(player_number, name, parent_box, orientation, spacing) {
    _chip_box = new CHIP_BOX(_cards_and_chip_box);
}


OTHER_PLAYER::~OTHER_PLAYER() {
    delete _chip_box;
}


void OTHER_PLAYER::display_card_backs() {
    remove_all_cards();
    for(int x = 0; x < 4; x++) _cards[x] = new CARDDISPLAY("Back", _card_box, 25, true);
    _cards[4] = new CARDDISPLAY("Back", _card_box, true);

}
