ifeq ($(OS),Windows_NT)
    EXE = exe
else
    EXE = out
endif

OBJS = Pytak.o Game.o Record.o
CC = g++
DEBUG = -g
LFLAGS = -Wall -Wextra -Wpedantic -std=c++14 $(DEBUG)
CFLAGS = $(LFLAGS) -c

pytak.$(EXE) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o pytak.$(EXE)

Record.o : Record.cpp Record.h
	$(CC) $(CFLAGS) Record.cpp

Game.o : Game.cpp Game.h Record.cpp Record.h
	$(CC) $(CFLAGS) Game.cpp

Pytak.o : Pytak.cpp Game.cpp Game.h
	$(CC) $(CFLAGS) Pytak.cpp

clean:
	rm *.o -f
	rm pytak.exe -f
	rm pytak.out -f
