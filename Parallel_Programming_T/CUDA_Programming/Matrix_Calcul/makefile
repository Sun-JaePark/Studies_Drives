CC=nvcc
CFLAGS=-g -Wall
OBJS=Matrix_Multiplication.cu
TARGET=Matrix_Multiplication.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f *.out

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)