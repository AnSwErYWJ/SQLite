CC = gcc

all:
	$(CC) -o test sqlite3.c example1.c -lpthread -ldl
