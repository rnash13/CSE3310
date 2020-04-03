
#ifndef _GLOBAL_
#define _GLOBAL_

#include<gtkmm.h>
#include<map>



extern Gdk::RGBA* COLOR_RED;
extern Gdk::RGBA* COLOR_GREEN;
extern Gdk::RGBA* COLOR_BLUE;
extern Gdk::RGBA* COLOR_WHITE;
extern Gdk::RGBA* COLOR_BLACK;


#define DEFAULT_CHIP_AMOUNT 200

#define WHITE_CHIP_VAL 1
#define RED_CHIP_VAL 5
#define BLUE_CHIP_VAL 10


#define IMG_PATH "./Images/"

// card name, card image name
extern std::map<std::string, std::string> CARD_NAMES_AND_IMAGES;

#endif