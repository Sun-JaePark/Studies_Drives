CC=nvcc
CFLAGS=-g -Wall
OBJS=Query_GPU.cu
TARGET=Query_GPU.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f *.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)