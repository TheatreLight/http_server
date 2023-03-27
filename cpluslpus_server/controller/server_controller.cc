#include "server_controller.h"

ServerController::ServerController(ServerModel* model) 
: server_(model) {}

ServerController::~ServerController() {
  server_ = nullptr;
}

void ServerController::GetProcess() {
  server_->SetConnection();
  server_->Process();
}