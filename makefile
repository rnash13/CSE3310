CXX=g++
CXXFLAGS=-std=c++11 `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` -I include/
SRC_DIR=./src
OBJ_DIR=./obj
CLIENT_DIR=./src/client
SERVER_DIR=./src/server
TEST_DIR=./tests
BUILD_DIR=./build

BRACKET_STYLE=java

OUTPUT=Poker++

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
CLIENT_FILES := $(wildcard $(CLIENT_DIR)/*.cpp)
SERVER_FILES := $(wildcard $(SERVER_DIR)/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
CLIENT_OBJ := $(patsubst $(CLIENT_DIR)/%.cpp,$(OBJ_DIR)/client/%.o,$(CLIENT_FILES))
SERVER_OBJ := $(patsubst $(SERVER_DIR)/%.cpp,$(OBJ_DIR)/server/%.o,$(SERVER_FILES))
TEST_FILES := $(patsubst $(TEST_DIR)/%.cpp,$(TEST_DIR)/%.test,$(TEST_FILES))

default: client server
	ln -srf Images ./build/Images

client: ${OBJ_FILES} ${CLIENT_OBJ}
	${CXX} $^ ${CXXFLAGS} -o ${BUILD_DIR}/${OUTPUT}_Client

server: ${OBJ_FILES} ${SERVER_OBJ}
	${CXX} $^ ${CXXFLAGS} -o ${BUILD_DIR}/${OUTPUT}_Server

test: clean ${OBJ_FILES} ${TEST_FILES}	

debug: CXXFLAGS+=-g 
debug: clean default 

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp 
	$(CXX) -c -o $@ $< ${CXXFLAGS}

${TEST_DIR}/%.test: ${TEST_DIR}/%.cpp
	$(CXX) -o $@ ${OBJ_FILES} $< ${CXXFLAGS}
	$@

*/%.o: ${SRC_DIR}/%.cpp 
	$(CXX) -c -o $@ $< ${CXXFLAGS}

prettify:
	find -type f \( -iname \*.h -o -iname \*.hpp -o -iname \*.cpp \) -exec astyle --style=${BRACKET_STYLE} {} \; | grep ^Formatted*

clean:
	-rm -rf ${BUILD_DIR}/*
	-rm -rf ${OBJ_DIR}/*.o
	-rm -rf ${OBJ_DIR}/*/*.o
	-rm -rf ${TEST_DIR}/*.o
