CC = gcc
CFLAGS = -O3 -Wall

all : setteemezzo

setteemezzo : setteemezzo.c
	$(CC) $(CFLAGS) setteemezzo.c -o setteemezzo -lm

run : setteemezzo
	./setteemezzo

.PHONY : clean
clean :
	rm -f setteemezzo
