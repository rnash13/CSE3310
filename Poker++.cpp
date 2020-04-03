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
#include<iostream>
#include<map>

#include"DISPLAY.h"

std::map<std::string, std::string> create_cards()
{
	// card name, card image name
	std::map<std::string, std::string> cards =
	{
		{"Ace Of Spades", "AceOfSpades.jpg"}, {"2 Of Spades", "2OfSpades.jpg"},
		{"3 Of Spades", "3OfSpades.jpg"}, {"4 Of Spades", "4OfSpades.jpg"},
		{"5 Of Spades", "5OfSpades.jpg"}, {"6 Of Spades", "6OfSpades.jpg"},
		{"7 Of Spades", "7OfSpades.jpg"}, {"8 Of Spades", "8OfSpades.jpg"},
		{"9 Of Spades", "9OfSpades.jpg"}, {"10 Of Spades", "10OfSpades.jpg"},
		{"Jack Of Spades", "JackOfSpades.jpg"}, {"Queen Of Spades", "QueenOfSpades.jpg"},
		{"King Of Spades", "KingOfSpades.jpg"},
		{"Ace Of Clubs", "AceOfClubs.jpg"}, {"2 Of Clubs", "2OfClubs.jpg"},
		{"3 Of Clubs", "3OfClubs.jpg"}, {"4 Of Clubs", "4OfClubs.jpg"},
		{"5 Of Clubs", "5OfClubs.jpg"}, {"6 Of Clubs", "6OfClubs.jpg"},
		{"7 Of Clubs", "7OfClubs.jpg"}, {"8 Of Clubs", "8OfClubs.jpg"},
		{"9 Of Clubs", "9OfClubs.jpg"}, {"10 Of Clubs", "10OfClubs.jpg"},
		{"Jack Of Clubs", "JackOfClubs.jpg"}, {"Queen Of Clubs", "QueenOfClubs.jpg"},
		{"King Of Clubs", "KingOfClubs.jpg"},
		{"Ace Of Hearts", "AceOfHearts.jpg"}, {"2 Of Hearts", "2OfHearts.jpg"},
		{"3 Of Hearts", "3OfHearts.jpg"}, {"4 Of Hearts", "4OfHearts.jpg"},
		{"5 Of Hearts", "5OfHearts.jpg"}, {"6 Of Hearts", "6OfHearts.jpg"},
		{"7 Of Hearts", "7OfHearts.jpg"}, {"8 Of Hearts", "8OfHearts.jpg"},
		{"9 Of Hearts", "9OfHearts.jpg"}, {"10 Of Hearts", "10OfHearts.jpg"},
		{"Jack Of Hearts", "JackOfHearts.jpg"}, {"Queen Of Hearts", "QueenOfHearts.jpg"},
		{"King Of Hearts", "KingOfHearts.jpg"},
		{"Ace Of Diamonds", "AceOfDiamonds.jpg"}, {"2 Of Diamonds", "2OfDiamonds.jpg"},
		{"3 Of Diamonds", "3OfDiamonds.jpg"}, {"4 Of Diamonds", "4OfDiamonds.jpg"},
		{"5 Of Diamonds", "5OfDiamonds.jpg"}, {"6 Of Diamonds", "6OfDiamonds.jpg"},
		{"7 Of Diamonds", "7OfDiamonds.jpg"}, {"8 Of Diamonds", "8OfDiamonds.jpg"},
		{"9 Of Diamonds", "9OfDiamonds.jpg"}, {"10 Of Diamonds", "10OfDiamonds.jpg"},
		{"Jack Of Diamonds", "JackOfDiamonds.jpg"}, {"Queen Of Diamonds", "QueenOfDiamonds.jpg"},
		{"King Of Diamonds", "KingOfDiamonds.jpg"}
	};
}


int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "Poker++");
	DISPLAY main_window(4);

	app->run(main_window);
	
	return 0;
}
