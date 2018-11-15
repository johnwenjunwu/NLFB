#ifndef NLFB_AP_SEND_TO_CLIENT_H
#define NLFB_AP_SEND_TO_CLIENT_H

#include "process.h"
class Ap;
class Client;
class ApSendToClient : public Process{
 public:
  ApSendToClient(double time, Ap *ap, Client *client, int block);
  void TimeOut() override;
 private:
  Ap *ap_;
  Client *client_;
  int block_;
};

#endif //NLFB_AP_SEND_TO_CLIENT_H
