
all: quad
	g++ main.o


main.o: main.cpp
	g++ main.cpp -c