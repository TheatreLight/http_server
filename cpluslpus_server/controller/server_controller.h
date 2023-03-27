#ifndef _HTTP_SERVER_CPLUSPLUS_SERVER_CONTROLLER_SERVER_CONTROLLER_H
#define _HTTP_SERVER_CPLUSPLUS_SERVER_CONTROLLER_SERVER_CONTROLLER_H

#include "../model/server_model.h"

class ServerController {
  public:
    explicit ServerController(ServerModel* model);
    ServerController(const ServerController& other) = delete;
    ServerController(ServerController&& other) = delete;
    ~ServerController();
    void GetProcess();
  private:
    ServerModel *server_;
};

#endif  // _HTTP_SERVER_CPLUSPLUS_SERVER_CONTROLLER_SERVER_CONTROLLER_H