#ifndef NLFB_AP_RECEIVE_H
#define NLFB_AP_RECEIVE_H

#include "process.h"
class Ap;
class Client;
class ApReceiveFromClient : public Process{
 public:
  ApReceiveFromClient(double time, Ap *ap, Client *client, int block);
  void TimeOut() override;
 private:
  Ap *ap_;
  Client *client_;
  int block_;
};

#endif //NLFB_AP_RECEIVE_H
