CC=gcc
CFLAG=-g -Wall
OBJS=DirOffset.o
TARGET=DirOffset.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)