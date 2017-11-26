OBJS = Pytak.o Game.o Record.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

pytak.exe : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o pytak.exe

Record.o : Record.cpp Record.h
	$(CC) $(CFLAGS) Record.cpp

Game.o : Game.cpp Game.h Record.cpp Record.h
	$(CC) $(CFLAGS) Game.cpp

Pytak.o : Pytak.cpp Game.cpp Game.h
	$(CC) $(CFLAGS) Pytak.cpp

clean:
	rm *.o pytak.exe -f
