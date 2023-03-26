#ifndef _HTTP_SERVER_CPLUSPLUS_SERVER_VIEW_ARGS_HANDLER_H
#define _HTTP_SERVER_CPLUSPLUS_SERVER_VIEW_ARGS_HANDLER_H

#include <string>

class ArgsHandler {
  public:
    explicit ArgsHandler(int argc, char** argv);
    ArgsHandler(const ArgsHandler& other) = default;
    ArgsHandler(ArgsHandler&& other) = default;
    ~ArgsHandler() = default;
    ArgsHandler& operator=(const ArgsHandler& other) = delete;
    ArgsHandler operator=(ArgsHandler&& other) = delete;
    int get_port() {
      return port_;
    }
    std::string get_address() {
      return address_;
    }
    std::string get_path() {
      return path_;
    }
  private:
    int port_ = 8080;
    std::string address_ = "0.0.0.0";
    std::string path_ = "../materials";
    void Handler(int argc, char** argv);
};

#endif  // _HTTP_SERVER_CPLUSPLUS_SERVER_VIEW_ARGS_HANDLER_H