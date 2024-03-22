CC=gcc
CFLAGS=-g -Wall
OBJS=waitpid.o
TARGET=waitpid.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)