#ifndef _HTTP_SERVER_C_SERVER_SERVER_H
#define _HTTP_SERVER_C_SERVER_SERVER_H

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct input_args {
  int port;
  char* addr;
  char* path;
};

void set_args(struct input_args*, char**, int);
int file_read(FILE*, char**);
void construct_content(char**, char*, int);
char* get_filename(char*, char*);
int is_html(char*);

int set_connection(struct sockaddr_in*);
void process(struct sockaddr_in*, FILE*, int, char*);

#endif  // _HTTP_SERVER_C_SERVER_SERVER_H