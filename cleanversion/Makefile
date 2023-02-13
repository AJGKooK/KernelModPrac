CC=gcc
MAIN=main.c
#CFLAGS= -Werror -Wall -std=c11
#$(CFLAGS)

%.o: %.c
		$(CC) -c -o $@ $<
all:
	$(CC) -c $(MAIN)
	$(CC) -o runme.exe main.o
main.o : $(MAIN)
	$(CC) -c $(MAIN)
clean:
	rm -vf *.o
	rm runme.exe
