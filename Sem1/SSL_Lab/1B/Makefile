INCLUDE=headers/
CFLAGS += -Wall
LDLIBS += -lm
CC=g++
DEP1=list
DEP2=Queue

SRC_PGM=main.cpp

compile: main.o $(DEP1).o $(DEP2).o
	$(CC) main.o $(DEP1).o $(DEP2).o $(LDLIBS) -o pgm

$(DEP1).o: sources/list.cpp
	$(CC) -I $(INCLUDE) -c sources/$(DEP1).cpp -o $(DEP1).o

$(DEP2).o: sources/Queue.cpp
	$(CC) -I $(INCLUDE) -c sources/$(DEP2).cpp -o $(DEP2).o

main.o: $(SRC) 
	$(CC) -I $(INCLUDE) -c $(SRC_PGM) 
	
clean:
	rm -rf *.o
	rm pgm
