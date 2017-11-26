OBJS = pytak.o base.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

pytak.exe : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o pytak.exe

base.o : base.cpp base.h
	$(CC) $(CFLAGS) base.cpp

pytak.o : pytak.cpp base.cpp base.h
	$(CC) $(CFLAGS) pytak.cpp

clean:
	rm *.o pytak.exe -f
