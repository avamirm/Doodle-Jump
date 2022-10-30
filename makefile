CC=g++ --std=c++11
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
EXE_FILE=doodleJump.out
all: $(EXE_FILE) 

doodleJump.out: main.o rsdl.o game.o enemy.o jumpable.o player.o
	$(CC) main.o rsdl.o game.o enemy.o jumpable.o player.o $(CCFLAGS) -o $(EXE_FILE)

main.o: rsdl.hpp game.hpp player.hpp enemy.hpp jumpable.hpp main.cpp
	$(CC) -c main.cpp -o main.o

rsdl.o: rsdl.hpp rsdl.cpp
	$(CC) -c rsdl.cpp -o rsdl.o

game.o: rsdl.hpp game.hpp player.hpp jumpable.hpp enemy.hpp game.cpp
	$(CC) -c game.cpp -o game.o	

player.o: rsdl.hpp player.hpp jumpable.hpp enemy.hpp player.cpp
	$(CC) -c player.cpp -o player.o	

jumpable.o: rsdl.hpp jumpable.hpp jumpable.cpp
	$(CC) -c jumpable.cpp -o jumpable.o	

enemy.o: rsdl.hpp enemy.hpp enemy.cpp
	$(CC) -c enemy.cpp -o enemy.o	
		
clean:
	rm *.o $(EXE_FILE)	