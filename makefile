CC = g++
STD = -std=c++11
CFLAGS = -g -Wall -Wextra -Wpedantic
OBJS = life.o utility.o
TARGET = gol

all: $(TARGET)

gol: $(OBJS)
	$(CC) $(CFLAGS) $(STD) $(OBJS) -o $(TARGET)

life.o: life.cc life.hh
	$(CC) $(CFLAGS) $(STD) -c life.cc life.hh
	
utility.o: utility.cc utility.hh
	$(CC) $(CFLAGS) $(STD) -c utility.cc utility.hh

clean:
	$(RM) $(TARGET) *.o *~ *.gch

