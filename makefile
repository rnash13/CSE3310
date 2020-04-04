
EXE = Poker++

all : 
	g++ *.cpp -g -std=c++11 `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` -o Poker++