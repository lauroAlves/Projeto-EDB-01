CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: restaurante

restaurante: main.o pedido.o
	$(CC) $(CFLAGS) -o restaurante main.o pedido.o

main.o: main.c pedido.h
	$(CC) $(CFLAGS) -c main.c

pedido.o: pedido.c pedido.h
	$(CC) $(CFLAGS) -c pedido.c

clean:
	rm -f *.o restaurante
