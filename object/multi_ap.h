#ifndef NLFB_MULTI_AP_H
#define NLFB_MULTI_AP_H
#include "ap.h"
class Wifi;
class Client;
class Producer;
class MultiAp : public Ap {
 public:
  explicit MultiAp(Timer *timer) : Ap(timer) {};
  void SendToClient(Client *client, int block) override;
 private:
};

#endif //NLFB_MULTI_AP_H
