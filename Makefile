CXX=g++
CXXFLAGS=-std=c++11 `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
OUTPUT=Poker++

default: CARD.o CHIP_BOX.o CHIP.o DISPLAY.o GLOBAL.o OTHER_PLAYER.o PLAYER.o Poker++.o USER.o
	${CXX} CARD.o CHIP_BOX.o CHIP.o DISPLAY.o GLOBAL.o OTHER_PLAYER.o PLAYER.o Poker++.o USER.o ${CXXFLAGS} -o Poker++

debug: 
	${CXX} -g CARD.o CHIP_BOX.o CHIP.o DISPLAY.o GLOBAL.o OTHER_PLAYER.o PLAYER.o Poker++.o USER.o ${CXXFLAGS} -o Debug

%.o: %.cpp %.h 
	    $(CXX) -c $< ${CXXFLAGS}

clean:
	-rm -rf *.o Poker++  Debug
