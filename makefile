CXX=g++
CXXFLAGS=-std=c++11 `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` -I include/
SRC_DIR=./src
OBJ_DIR=./obj
BUILD_DIR=./build
OUTPUT=Poker++

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

default: ${OBJ_FILES}
	${CXX} $^ ${CXXFLAGS} -o ${BUILD_DIR}/Poker++

debug: CXXFLAGS+=-g 
debug: clean debug_compile
debug_compile: ${OBJ_FILES}
	${CXX}  $^ ${CXXFLAGS} -o ${BUILD_DIR}/Debug


${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp 
	$(CXX) -c -o $@ $< ${CXXFLAGS}

clean:
	-rm -rf ${BUILD_DIR}/*
	-rm -rf ${OBJ_DIR}/*.o
