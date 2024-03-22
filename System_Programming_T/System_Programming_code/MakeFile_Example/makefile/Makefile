# main.out: main.o foo.o bar.o
# 	gcc -o main.out main.o foo.o bar.o

# main.o: foo.h bar.h main.c
# foo.o: foo.h foo.c
# bar.o: bar.h bar.c

CC=gcc
CFLAGS=-g -Wall
OBJS=main.o foo.o bar.o
TARGET=app.out

all: $(TARGET)

$(TARGET): $(OBJS)
		   $(CC) -o $@ $(OBJS)

main.o: foo.h bar.h main.c
foo.o: foo.h foo.c
bar.o: bar.h bar.c

clean:
		rm -f *.o
		rm -f $(TARGET)