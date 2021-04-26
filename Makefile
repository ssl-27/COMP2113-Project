##this file must be named makefile

.PHONY: clean
clean:
	rm -f main main.o
main.o: main.cpp battle.h headers.h inventory.h playerstatus.h randomMonster.h
	g++ -c main.cpp
main: main.o
	g++ main.o -o main
