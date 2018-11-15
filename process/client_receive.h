#ifndef NLFB_CLIENT_RECEIVE_H
#define NLFB_CLIENT_RECEIVE_H

#include "process.h"
class Client;
class ClientReceive : public Process{
 public:
  ClientReceive(double time, Client *client, int block);
  void TimeOut() override;
 private:
  Client *client_;
  int block_;
};

#endif //NLFB_CLIENT_RECEIVE_H
