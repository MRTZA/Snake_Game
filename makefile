all: game

window.o: window.cpp window.h
	g++ window.cpp -c -lglut -lGL -lGLU

game: main.cpp window.o
	g++ -o game main.cpp window.o -lglut -lGL -lGLU
