CC=gcc
CFLAGS=-g -Wall
OBJS=GetLink.o
TARGET=GetLink.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

