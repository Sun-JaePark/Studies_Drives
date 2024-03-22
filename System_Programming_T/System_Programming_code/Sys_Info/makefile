CC=gcc
CFLAGS=-g -Wall
OBJS=SysConf.o
TARGET=SysConf.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)