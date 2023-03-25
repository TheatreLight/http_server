all: libs build clean

libs:
	gcc -c server.c
	ar -rcs lib/libserver.a server.o
	ranlib lib/libserver.a

build:
	gcc main.c -o server -L./lib -lserver

clean:
	rm -rf *.o *.a