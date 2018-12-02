all: main

window.o: window.cpp window.h
	g++ window.cpp -c -lglut -lGL -lGLU

main: main.cpp window.o
	g++ main.cpp window.o -o -lglut -lGL -lGLU
