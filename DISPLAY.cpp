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

#include"DISPLAY.h"

DISPLAY::DISPLAY(int player_number) :
_player_number{player_number}
{
	main_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*main_box);

	set_default_size(1000, 600);
	set_title("Poker++");
	set_position(Gtk::WIN_POS_CENTER);

	main_box->override_background_color(*COLOR_GREEN);


	// ———————————— OTHER PLAYERS & POT ————————————	
	// ———— TOP ROW ————
	top_row_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	main_box->pack_start(*top_row_box);
	// —— CELLS ——
	top_left_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	top_row_box->pack_start(*top_left_box );
	top_center_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	top_row_box->pack_start(*top_center_box);
	top_right_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	top_row_box->pack_start(*top_right_box);

	// ———— MIDDLE ROW ————
	middle_row = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	main_box->pack_start(*middle_row);
	// —— CELLS ——
	middle_left_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	middle_row->pack_start(*middle_left_box);
	pot_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
	middle_row->pack_start(*pot_box);
	pot = new CHIP_BOX(pot_box);
	middle_right_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 50));
	middle_row->pack_start(*middle_right_box);

	// ———— SETUP PRE-EXISTING PLAYERS AND DEALER ————
	assign_players_to_all_players_array();
	// dealer
	all_players[0]->override_background_color(*COLOR_RED);
	all_players[0]->name_label()->override_color(*COLOR_WHITE);

	// ———————————————— PLAYER ————————————————
	// ———— BOTTOM ROW ————
	bottom_row_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	main_box->pack_start(*bottom_row_box);
	user = new USER(_player_number, "ME :)", bottom_row_box);

	main_box->show_all();
}


DISPLAY::~DISPLAY()
{
	for(int x = 0; x < 6; x++) if(all_players[x]) delete all_players[x];
}


// new player joined game after display created; create dependencies & add to players array
void DISPLAY::assign_player_to_all_players_array(int player_number, std::string player_name)
{
	_total_players++;

	// holds box pointers in order
	Gtk::Box* box_array[5] =	{
									middle_left_box, top_left_box, top_center_box,
									top_right_box, middle_right_box
								};
	Gtk::Box* desire_box = box_array[player_number - _player_number];
	all_players[player_number] = new OTHER_PLAYER(player_number, player_name, desire_box);
}


// for easy iteration store boxes in order {dealer, player 1, player 2, player...}
void DISPLAY::assign_players_to_all_players_array()
{
	_total_players = _player_number;

	std::string test_names[5] = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5"};
	// holds box pointers in order
	Gtk::Box* box_array[5] =	{
									middle_left_box, top_left_box, top_center_box,
									top_right_box, middle_right_box
								};

	// assign dealer as a PLAYER
	all_players[0] = new PLAYER(0, "DEALER", box_array[5 - _player_number]);
	// copy in order the pointers of the boxes
	for(int x = 6 - _player_number, y = 1; x < 5; x++, y++)
	{
		all_players[y] = new OTHER_PLAYER(y, test_names[y-1], box_array[x]);
	}
	all_players[_player_number] = NULL;  // constant so NULL put in for good measure

	// create Labels for empty spaces
}


// void DISPLAY::clear_all_cards_from_player()
// {
// 	for(int x = 0; x < 5; x++)
// 	{
// 		delete player_cards[x].image;
// 		player_cards[x].image = NULL;
// 	}
// }


// void DISPLAY::remove_cards_from_player(std::vector<std::string> card_names)
// {
// 	// remove undesired card by name & set pointer to NULL
// 	for(int x = 0; x < 5; x++)
// 	{
// 		for(int y = 0; y < card_names.size(); y++)
// 		{
// 			if(player_cards[x].name == card_names[y])
// 			{
// 				delete player_cards[x].image;
// 				player_cards[x].image = NULL;
// 			}
// 		}
// 	}

// 	// reorder remaining cards
// 	for(int x = 0; x < 5; x++)
// 	{
// 		if(!player_cards[x].image)
// 		{
// 			for(int y = x+1; y < 5; y++)
// 			{
// 				if(player_cards[y].image)
// 				{
// 					player_cards[x].image = player_cards[y].image;
// 					player_cards[y].image = NULL;
// 					break;
// 				}
// 			}
// 		}
// 	}
// }


// void DISPLAY::add_cards_to_player(std::vector<std::string> card_image_names)
// {
// 	for(int x = 5 - card_image_names.size(); x < 5; x++)
// 	{
// 		player_cards[x].image = Gtk::manage(new Gtk::Image{card_image_names[x - card_image_names.size()]});
// 		card_box->pack_start(*player_cards[x].image);
// 	}
// }