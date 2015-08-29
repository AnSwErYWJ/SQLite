SRC = example1.c
OBJS = example1.o
CC = gcc

test: sqlite3.o $(OBJS)
	$(CC) -o test sqlite3.o $(OBJS) -ldl -lpthread
sqlite3.o: sqlite3.c sqlite3.h
	$(CC) -c sqlite3.c -o sqlite3.o  
example1.o: $(SRC) sqlite3.h
	$(CC) -c $(SRC) -o example1.o

clean:
	rm -f *.o test
