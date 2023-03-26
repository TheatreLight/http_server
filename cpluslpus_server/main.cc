#include "view/args_handler.h"
#include "controller/server_controller.h"

int main(int argc, char** argv) {
  ArgsHandler handler(argc, argv);
  int port = handler.get_port();
  std::string address = handler.get_address();
  std::string path = handler.get_path();
  ServerModel model(port, address, path);
  ServerController controller(&model);
  auto request = controller.GetProcess();
  std::cout << request << std::endl;
  return 0;
}