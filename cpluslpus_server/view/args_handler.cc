#include "args_handler.h"

ArgsHandler::ArgsHandler(int argc, char** argv) {
  Handler(argc, argv);
}

void ArgsHandler::Handler(int argc, char** argv) {
  if (argc == 1) return;
  for (int i = 1; i < argc; ++i) {
    if (i == 1) port_ = atoi(argv[i]);
    if (i == 2) {
      std::string adr(argv[i]);
      address_ = adr;
    }
    if (i == 3) {
      std::string pth(argv[i]);
      path_ = pth;
    }
  }
}