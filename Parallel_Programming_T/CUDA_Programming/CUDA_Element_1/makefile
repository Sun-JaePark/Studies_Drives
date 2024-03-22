CC=nvcc
CFLAGS=-g -Wall
OBJS=Vector_Sum.cu
TARGET=Vector_Sum.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f *.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)