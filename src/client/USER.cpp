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

#include"USER.h"


USER::USER(int player_number, std::string name, Gtk::Box* parent_box, Gtk::Orientation orientation, int spacing) :
    CARD_PLAYER(player_number, name, parent_box, orientation, spacing) {
    _chip_box = new CHIP_BOX(_cards_and_chip_box);

    _player_actions_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    _cards_and_chip_box->pack_start(*_player_actions_box);


    _bet_button = Gtk::manage(new Gtk::Button("bet"));
    _player_actions_box->pack_start(*_bet_button);

    _check_button = Gtk::manage(new Gtk::Button("check"));
    _check_button->signal_clicked().connect(sigc::mem_fun(*this, &USER::check));
    _player_actions_box->pack_start(*_check_button);


    _fold_button = Gtk::manage(new Gtk::Button("fold"));
    _fold_button->signal_clicked().connect(sigc::mem_fun(*this, &USER::fold));
    _player_actions_box->pack_start(*_fold_button);

    _trade_button = Gtk::manage(new Gtk::Button("trade"));
    _player_actions_box->pack_start(*_trade_button);
}


USER::~USER() {
    delete _chip_box;
}


void USER::remove_cards(std::vector<std::string> cards_to_remove) {
    // delete card object
    for(int x = 0; x < cards_to_remove.size(); x++) {
        for(int y = 0; y < 5; y++) {
            if(_cards[x] && _cards[x]->name() == cards_to_remove[x]) {
                delete _cards[x];
                _cards[x] = NULL;
            }
        }
    }

    // shift cards to beginning
    for(int x = 0; x < 5; x++) {
        if(!_cards[x]) {
            for(int y = x+1; y < 5; y++) {
                if(_cards[y]) {
                    _cards[x] = _cards[y];
                    _cards[y] = NULL;
                    break;
                }
            }
        }
    }
}


// —————————————— BUTTON FUNCTIONS ———————————————

void USER::hide_user_actions() {
    _bet_button->hide();
    _check_button->hide();
    _fold_button->hide();
    _trade_button->hide();
}

void USER::show_user_actions() {
    _bet_button->show();
    _check_button->show();
    _fold_button->show();
    _trade_button->show();
}


void USER::check() {
    hide_user_actions();
}


void USER::fold() {
    remove_all_cards();
    hide_user_actions();
}