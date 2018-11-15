#ifndef NLFB_AP_H
#define NLFB_AP_H

#include "object.h"

class Wifi;
class Client;
class Producer;
class Ap : public Object {
 public:
  explicit Ap(Timer *timer) : Object(timer) {};
  void SetWifi(Wifi *wifi);
  virtual void SendToClient(Client *client, int block);
  void SendToProducer(Client *client, int block);
  void SetProducer(Producer *producer);
 private:
  Wifi *wifi_ = nullptr;
  Producer *producer_ = nullptr;
  double wait_ = GetSendGap();
};

#endif //NLFB_AP_H
