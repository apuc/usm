all: build

build:
	g++ usm.cpp libs/User.cpp libs/Params.cpp -o usm

debug:
	g++ usm.cpp libs/User.cpp libs/Params.cpp -g -o usm.o