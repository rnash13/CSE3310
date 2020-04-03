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

OTHER_PLAYER::OTHER_PLAYER(int player_number, std::string name, Gtk::Box* parent_box, Gtk::Orientation orientation, int spacing) :
PLAYER(player_number, name, parent_box, orientation, spacing)
{
	_chip_box = new CHIP_BOX(this);
}


OTHER_PLAYER::~OTHER_PLAYER()
{
	delete _chip_box;
}
