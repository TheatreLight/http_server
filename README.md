# http_server

An example of a simple http_server written in both C and C++

To build the server, you need to go to the appropriate directory and type "make build" - the program will be built with a precompiled library (look in the lib/ directory). If you decide to recompile the library, just type "make libs".

To start the server, you can simply do ./server in the current directory and it will run with the default options (port is 8080, address is "0.0.0.0", content directory is "materials"). If you want to enter custom options, use command line arguments:

  server [PORT] [ADDRESS] [DIRECTORY]

For example, ./server 9000 127.0.0.1 my_dir/my_folder. Make sure the dir parameter do not end with "/".
