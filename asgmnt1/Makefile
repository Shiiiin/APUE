CC=gcc
TARGET=hello
CFLAGS=-g -Wall -ansi -pedantic

all:$(TARGET)

$(TARGET):$(TARGET).o
	$(CC) -o $@ $^
$(TARGET).o:$(TARGET).c
	$(CC) -c $(TARGET).c

.PHONY:clean

clean:
	rm -f *.o

