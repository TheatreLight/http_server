CC=g++ -std=c++17
CFLAGS= -Wall -Werror -Wextra

all: libs build clean

libs:
	$(CC) $(CFLAGS) -c model/server_model.cc controller/server_controller.cc
	ar -rcs lib/libserver.a server_model.o server_controller.o
	ranlib lib/libserver.a

build:
	$(CC) $(CFLAGS) main.cc view/args_handler.cc -o server -L./lib -lserver

debug:
	$(CC) $(CFLAGS) main.cc view/args_handler.cc model/server_model.cc controller/server_controller.cc -o server_dbg -g

clean:
	rm -rf *.o *.a