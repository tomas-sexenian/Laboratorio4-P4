SOURCE= makefile
DESTINATION='Laboratorio4-P4-main/'
OBJS=*.o
CLSS=src/*.cpp
DEF=include/*.hh include/interfaces/*.hh include/controladores/*.hh include/cabezales/*.hh

all: compile menu generate

compile: $(DEF)
	g++ -c $(CLSS) -Wall -ggdb

menu: $(DEF)
	g++ -c menu.cpp -Wall -ggdb

generate:
	g++ $(OBJS) -o menu -Wall -ggdb

clean:
	rm -f $(OBJS) menu
