CC=gcc
BIZZLE=rizzle.h
MAIN=main.c
COMM=command.c
#CFLAGS= -Werror -Wall -std=c11
#$(CFLAGS)

%.o: %.c $(BIZZLE)
		$(CC) -c -o $@ $<
all:
	$(CC) -c $(COMM) $(MAIN)
	$(CC) -o runme.exe main.o command.o
command.o : $(COMM)
	$(CC) -c $(COMM)
main.o : $(MAIN)
	$(CC) -c $(MAIN)
clean:
	rm -vf *.o
	rm runme.exe
