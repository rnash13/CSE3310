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


#ifndef _CHIP_
#define _CHIP_

#include<gtkmm.h>

class CHIP
{
	public:
		CHIP(int, Gtk::Box*);
		~CHIP();

	private:
		Gtk::Box* _chip_box;
		int _stack_size = 1;

		Gtk::Image* _image;

};

#endif