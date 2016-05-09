
CC=g++
C-FLAGS=-g -c -Wall -std=c++11
C-FLAGS-LINK=-g -Wall -std=c++11 -lSDL2 -lSDL2_image -lSDL2_ttf

all: flappy_game

flappy_game: engine flappy
	$(CC) game.o input.o logger.o renderer.o bird.o background.o flappygame.o floor.o pipe.o main.cpp -o flappy_game $(C-FLAGS-LINK)

flappy: bird.o background.o flappygame.o floor.o pipe.o

bird.o: game/bird.cpp
	$(CC) $(C-FLAGS) game/bird.cpp

background.o: game/background.cpp
	$(CC) $(C-FLAGS) game/background.cpp

flappygame.o: game/flappygame.cpp
	$(CC) $(C-FLAGS) game/flappygame.cpp

floor.o: game/floor.cpp
	$(CC) $(C-FLAGS) game/floor.cpp

pipe.o: game/pipe.cpp
	$(CC) $(C-FLAGS) game/pipe.cpp

engine: game.o input.o logger.o renderer.o

game.o: engine/game.cpp
	$(CC) $(C-FLAGS) engine/game.cpp

input.o: engine/input.cpp
	$(CC) $(C-FLAGS) engine/input.cpp

logger.o: engine/logger.cpp
	$(CC) $(C-FLAGS) engine/logger.cpp

renderer.o: engine/renderer.cpp
	$(CC) $(C-FLAGS) engine/renderer.cpp

clean:
	rm *.o flappy_game
