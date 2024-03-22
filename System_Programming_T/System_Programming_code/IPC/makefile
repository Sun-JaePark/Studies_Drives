CC=gcc
CFLAGS=-g -Wall
OBJS=sem.o
TARGET=sem.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f *.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)