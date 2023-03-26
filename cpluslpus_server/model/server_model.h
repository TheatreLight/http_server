#ifndef _HTTP_SERVER_CPLUSPLUS_SERVER_MODEL_SERVER_MODEL_H
#define _HTTP_SERVER_CPLUSPLUS_SERVER_MODEL_SERVER_MODEL_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

constexpr int buffer_size = 30000;

class ServerModel {
  public:
    explicit ServerModel(int port, std::string ip, std::string path);
    ServerModel(const ServerModel& other) = default;
    ServerModel(ServerModel&& other) = default;
    ~ServerModel();
    void SetConnection();
    std::string Process();
  private:
    struct sockaddr_in address_;
    size_t address_length_;
    int socket_;
    int new_socket_;
    int port_;
    std::string ip_address_;
    std::string path_;
    std::string ReceiveRequest();
    void SendResponse(std::string path_to_dir);
    std::string ConstrustFullPath(const std::string& request);
    std::string PageBuild(std::string path_to_dir);
    bool IsHtml(const std::string& path);
};

#endif  // _HTTP_SERVER_CPLUSPLUS_SERVER_MODEL_SERVER_MODEL_H