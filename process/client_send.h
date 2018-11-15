#ifndef NLFB_CLIENT_SEND_H
#define NLFB_CLIENT_SEND_H

#include "process.h"

class Client;
class ClientSend : public Process{
 public:
  explicit ClientSend(double time, Client *client);
  void TimeOut() override;
 private:
  Client *client_;
};

#endif //NLFB_CLIENT_SEND_H
