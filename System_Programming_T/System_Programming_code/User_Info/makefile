CC=gcc
CFLAGS=-g -Wall
OBJS=GroupInfo.o
TARGET=GroupInfo.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)