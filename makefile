# makefile

all: main

AI.o: Player.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/AI.cpp

Node.o:
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/Node.cpp

Player.o: 
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/Player.cpp

Game.o: Player.o AI.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include -c src/Game.cpp

GraphicsEngine.o: Game.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses1 -I include -c src/GraphicsEngine.cpp

# Tests:

test_AI: AI.o Player.o Node.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I $(CATCH_SINGLE_INCLUDE):include -o test/test_AI AI.o Player.o Node.o test/test_AI.cpp 

test_GraphicsEngine: GraphicsEngine.o Game.o AI.o Player.o MMTree.o Node.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o test/test_GraphicsEngine AI.o Player.o Game.o GraphicsEngine.o MMTree.o Node.o test/test_GraphicsEngine.cpp 

test_Player: Player.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o test/test_Player Player.o test/test_Player.cpp 

# Main:

test_Player: Player.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o test/test_Player Player.o test/test_Player.cpp 

test_Node: Node.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o test/test_Node Node.o test/test_Node.cpp 

test_MMTree: MMTree.o Node.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -Wall -I $(CATCH_SINGLE_INCLUDE):include -o test/test_MMTree Node.o MMTree.o test/test_MMTree.cpp 

# Main:

main: GraphicsEngine.o Game.o AI.o Player.o
	g++-8.2.0 -std=c++2a -Wall -Wextra -pedantic -fsanitize=address,undefined,pointer-compare,pointer-subtract -fstack-clash-protection -g -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses -I include AI.o Player.o Game.o GraphicsEngine.o -o main src/main.cpp 

clean:
	rm -r *.o
