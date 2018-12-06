all: game

# window.o: window.cpp window.h
# 	g++ window.cpp -c -lglut -lGL -lGLU

# game.o: game.cpp game.h
# 	g++ game.cpp -c -lglut -lGL -lGLU

snake.o: snake.cpp snake.h
	g++ snake.cpp -c -lglut -lGL -lGLU

game: main.cpp snake.o
	g++ -o game main.cpp snake.o -lglut -lGL -lGLU
