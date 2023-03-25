#include "server.h"

void set_args(struct input_args* args, char** argv, int argc) {
  args->port = 9000;
  args->addr = "0.0.0.0";
  args->path = "materials/";
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      if (i == 1) args->port = atoi(argv[i]);
      if (i == 2) args->addr = argv[i];
      if (i == 3) args->path = argv[i];
    }
  }
}

int main(int argc, char **argv) {
  FILE *f = NULL;
  struct sockaddr_in address;
  struct input_args args;
  const int PORT = 9000;
  set_args(&args, argv, argc);
  memset((char*)&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(args.addr);
  address.sin_port = htons(args.port);
  int addrlen = sizeof(address);
  int server_fd = set_connection(&address);
  process(&address, f, server_fd, args.path);
  return 0;
}