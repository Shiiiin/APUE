CC=gcc
TARGET=hello
OBJECT=hello.o
CPP=hello.c
CFLAGS=-Wall -ansi -pedantic

all:$(TARGET)

$(TARGET):$(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECT):$(CPP)
	$(CC) $(CFLAGS) -c $^

.PHONY:clean

clean:
	rm -f *.o

