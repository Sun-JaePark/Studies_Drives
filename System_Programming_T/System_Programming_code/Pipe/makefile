CC=gcc
CFLAGS=-g -Wall
OBJS=communicate_pipe2.o
TARGET=communicate_pipe2.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)