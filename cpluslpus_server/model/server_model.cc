#include "server_model.h"

ServerModel::ServerModel(int port, std::string ip, std::string path) : path_(path) {
  address_.sin_addr.s_addr = inet_addr(ip.c_str());
  address_.sin_family = AF_INET;
  address_.sin_port = htons(port);
  address_length_ = sizeof(address_);
}

ServerModel::~ServerModel() {
  close(socket_);
  close(new_socket_);
}

void ServerModel::SetConnection() {
  if ((socket_ = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    throw std::out_of_range("Can't create the socket");
  }
  if ((bind(socket_, (sockaddr*)&address_, address_length_)) < 0) {
    throw std::out_of_range("Bind error");
  }
  if ((listen(socket_, 3)) < 0) {
    throw std::out_of_range("Listen error");
  }
}

std::string ServerModel::Process() {
  while(true) {
    std::string request = ReceiveRequest();
    std::string pth = ConstrustFullPath(request);
    if (IsHtml(pth)) {
      SendResponse(pth);
    }
  }
}

std::string ServerModel::ReceiveRequest() {
  new_socket_ = accept(socket_, (sockaddr*)&address_, (socklen_t*)&address_length_);
  char buf[buffer_size] = {0};
  read(new_socket_, buf, buffer_size);
  std::string request(buf);
  return request;
}

void ServerModel::SendResponse(std::string path_to_dir) {
  std::string response = PageBuild(path_to_dir);
  write(new_socket_, response.c_str(), response.length());
}

std::string ServerModel::ConstrustFullPath(const std::string& request) {
  auto found_start = request.find(" ")+1;
  auto s = request.substr(found_start);
  auto found_end = s.find(" ");
  std::string file_path = request.substr(found_start, found_end);
  return path_ + file_path;
}

bool ServerModel::IsHtml(const std::string& path) {
  size_t found;
  if ((found = path.find_last_of(".")) == std::string::npos) return false;
  return path.substr(found) == ".html";
}

std::string ServerModel::PageBuild(std::string path_to_dir) {
  std::ifstream i_file;
  i_file.open(path_to_dir, std::ios::in);
  std::string i_line;
  std::string content;
  while(getline(i_file, i_line)) {
    content += i_line;
  }
  std::string page = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
  int length = content.length();
  return page += std::to_string(length) + "\n\n" + content;
}