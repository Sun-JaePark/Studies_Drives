CC=gcc
CFLAGS=-g -Wall
OBJS=FD_Flag.o
TARGET=FD_Flag.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)