CC=gcc
CFLAGS=-g -Wall
OBJS=Pointer_to_Ds.o
TARGET=Pointer_to_Ds.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
