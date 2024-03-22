CC=gcc
CFLAGS=-g -Wall
OBJS=producer.o
TARGET=producer.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)