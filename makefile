CXX=g++
CXXFLAGS=-std=c++11 `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs` -I include/
SRC_DIR=./src
OBJ_DIR=./obj
CLIENT_DIR=./src/client
SERVER_DIR=./src/server
BUILD_DIR=./build
OUTPUT=Poker++

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
CLIENT_FILES := $(wildcard $(CLIENT_DIR)/*.cpp)
SERVER_FILES := $(wildcard $(SERVER_DIR)/*.cpp)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
CLIENT_OBJ := $(patsubst $(CLIENT_DIR)/%.cpp,$(OBJ_DIR)/client/%.o,$(CLIENT_FILES))
SERVER_OBJ:= $(patsubst $(SERVER_DIR)/%.cpp,$(OBJ_DIR)/server/%.o,$(SERVER_FILES))


default: client server
	rm ./build/Images
	ln -sr Images ./build/Images

client: ${OBJ_FILES} ${CLIENT_OBJ}
	${CXX} $^ ${CXXFLAGS} -o ${BUILD_DIR}/Poker++_Client

server: ${OBJ_FILES} ${SERVER_OBJ}
	${CXX} $^ ${CXXFLAGS} -o ${BUILD_DIR}/Poker++_Server

debug: CXXFLAGS+=-g 
debug: clean default 


${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp 
	$(CXX) -c -o $@ $< ${CXXFLAGS}

*/%.o: ${SRC_DIR}/%.cpp 
	$(CXX) -c -o $@ $< ${CXXFLAGS}
clean:
	-rm -rf ${BUILD_DIR}/*
	-rm -rf ${OBJ_DIR}/*.o
	-rm -rf ${OBJ_DIR}/*/*.o
