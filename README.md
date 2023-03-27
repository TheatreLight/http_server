# http_server

An example of a simple http_server written in both C and C++

To build the server, you need to go to the appropriate directory and type "make build" - the program will be built with a precompiled library (look in the lib/ directory). If you decide to recompile the library, just type "make libs".

To start the server, you can simply do ./server in the current directory and it will run with the default options (port is 8080, address is "0.0.0.0", content directory is "materials"). If you want to enter custom options, use command line arguments:

  server [PORT] [ADDRESS] [DIRECTORY]

where the PORT-paarameter is choosen port,
ADDRESS - your ip-address,
DIRECTORY - path to folder where server is looking for your files. By default, server is looking for index.html. Make sure file with same name and extension exist.

For example, ./server 9000 127.0.0.1 my_dir/my_folder. Make sure the dir parameter do not end with "/".

Do not try to change places of the parameters in arguments line - it may cause of undefined behavior.

Cplusplus-version is more stable then c-version.
