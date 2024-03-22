CC=gcc
CFLAGS=-g -Wall
OBJS=addEnv.o
TARGET=addEnv.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)