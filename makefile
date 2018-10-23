# makefile

all: main

AI.o: Player.o
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/AI.cpp

Player.o: 
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/Player.cpp

Game.o: Player.o AI.o
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/Game.cpp

GraphicsEngine.o: Game.o
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/GraphicsEngine.cpp


test_AI: AI.o Player.o
	g++ -std=c++11 -Wall -I $(CATCH_SINGLE_INCLUDE):include -o test/test_AI AI.o Player.o test/test_AI.cpp 

test_GraphicsEngine: GraphicsEngine.o Game.o AI.o Player.o
	g++ -std=c++11 -Wall -I $(CATCH_SINGLE_INCLUDE):include -o test/test_GraphicsEngine AI.o Player.o Game.o GraphicsEngine.o test/test_GraphicsEngine.cpp 

main: GraphicsEngine.o Game.o AI.o Player.o
	g++ -g -w -Wall -O1 -std=c++11 -I include -o src/main src/main.cpp GraphicsEngine.o Game.o AI.o Player.o

clean:
	rm -r *.o
