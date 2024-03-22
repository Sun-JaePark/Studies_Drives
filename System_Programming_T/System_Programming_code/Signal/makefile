CC=gcc
CFLAGS=-g -Wall
OBJS=WaitingSig.o
TARGET=WaitingSig.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)