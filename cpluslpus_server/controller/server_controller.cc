#include "server_controller.h"

ServerController::ServerController(ServerModel* model) 
: server_(model) {}

ServerController::~ServerController() {
  server_ = nullptr;
}

std::string ServerController::GetProcess() {
  server_->SetConnection();
  return server_->Process();
}