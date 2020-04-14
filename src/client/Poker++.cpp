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

#include"DISPLAY.h"
#include"GLOBAL.h"



int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.poker");
	DISPLAY main_window(4);

	app->run(main_window);
	
	return 0;
}
