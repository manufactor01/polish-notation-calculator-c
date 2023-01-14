CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -lm
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
EXEC = dc
OBJFILE = main.o notacion_posfija.o pila.o cola.o strutil.o
TEXTFILE = oper.txt

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

$(EXEC): $(OBJFILE)
	$(CC) $(CFLAGS) $(OBJFILE) -o $(EXEC)

all: $(EXEC)

run: all
	clear
	./$(EXEC) < $(TEXTFILE) 

free: $(OBJFILE)
	rm -f $(EXEC) *.o

valgrind: all
	clear
	valgrind $(VFLAGS) ./$(EXEC) < $(TEXTFILE) 
