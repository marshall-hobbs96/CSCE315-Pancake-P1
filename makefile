# makefile

all: main

AI.o: 
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/AI.cpp

Player.o: 
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/Player.cpp

Game.o: 
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/Game.cpp

GraphicsEngine.o: 
	g++ -g -w -Wall -O1 -std=c++11 -I include -c src/GraphicsEngine.cpp


test_AI: AI.o Player.o
	g++ -std=c++11 -Wall -I test/$(CATCH_SINGLE_INCLUDE):include -o test/test_AI AI.o Player.o test/AI_test.cpp 

main: GraphicsEngine.o Game.o AI.o Player.o
	g++ -g -w -Wall -O1 -std=c++11 -I include -o src/main src/main.cpp GraphicsEngine.o Game.o AI.o Player.o

clean:
	rm -r *.o
