CC=gcc
CFALGS=-g -Wall
OBJS=allocFD.o
TARGET=allocFD.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)