#include "server.h"

void set_args(struct input_args* args, char** argv, int argc) {
  args->port = 9000;
  args->addr = "0.0.0.0";
  args->path = "../materials";
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      if (i == 1) args->port = atoi(argv[i]);
      if (i == 2) args->addr = argv[i];
      if (i == 3) args->path = argv[i];
    }
  }
}

char* get_filename(char* str, char* path) {
  char* tok = strtok(str, " ");
  tok = strtok(NULL, " ");
  if (strcmp(tok, "/") == 0) {
    tok = "/index.html";
  }
  size_t full_length = strlen(path) + strlen(tok) + 1;
  char* result = (char*)malloc(full_length * sizeof(char));
  snprintf(result, full_length, "%s%s", path, tok);
  return result;
}

int is_html(char* name) {
  return strstr(name, ".html") != NULL ? 1 : 0;
}

int file_read(FILE *f, char**buffer) {
  int length = 0;
  if (f != NULL) {
    int err = 0;
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    *buffer = (char*)malloc(length * sizeof(char));
    fread(*buffer, 1, length, f);
  } else {
    *buffer = NULL;
  }
  return length;
}

void construct_content(char**output, char*buffer, int length) {
  if (length != 0) {
    char* header = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
    int full_length = length + strlen(header) + 1;
    *output = (char*)malloc(full_length * sizeof(char));
    snprintf(*output, full_length, "%s%d%s%s", header, length, "\n\n", buffer);
  } else {
    *output = (char*)calloc(1, sizeof(char));;
  }
}

int set_connection(struct sockaddr_in *address) {
  int server_fd;
   if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creating error: ");
    return 0;
  }
  if (bind(server_fd, (struct sockaddr*)address, sizeof(*address)) < 0) {
    perror("Bind creating error: ");
    return 0;
  }
  if (listen(server_fd, 3) < 0) {
    perror("Listen error: ");
    return 0;
  }
  return server_fd;
}

void process(struct sockaddr_in* address, FILE* f, int server_fd, char* path) {
  if (server_fd == 0) return;
  char *buffer = NULL;
  char* output = NULL;
  int addrlen = sizeof(*address);
  while (1) {
    int new_socket = accept(server_fd, (struct sockaddr*)address, (socklen_t*)&addrlen);
    //print_request(new_socket);
    char buf [20000] = {0};
    read(new_socket, buf, 20000);
    if (buf[0] == '\0') continue;
    printf("%s\n", buf);
    char* name = get_filename(buf, path);
    if (is_html(name))
      if((f = fopen(name, "r")) == NULL) {
        perror("Open error: ");
      }
    free(name);
    int length = file_read(f, &buffer);
    construct_content(&output, buffer, length);
    write(new_socket, output, strlen(output));
    if (buffer != NULL) free(buffer);
    if (output != NULL) free(output);
    close(new_socket);
    if (f != NULL) fclose(f);
    f = NULL;
  }
}
