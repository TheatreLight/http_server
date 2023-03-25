#include "server.h"

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