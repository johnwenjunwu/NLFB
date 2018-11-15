#ifndef NLFB_AP_RECEIVE_FROM_PRODUCER_H
#define NLFB_AP_RECEIVE_FROM_PRODUCER_H

#include <object/ap.h>
#include "process.h"
class ApReceiveFromProducer : public Process {
 public:
  ApReceiveFromProducer(double time, Ap *ap, Client *client, int block);
 private:
  void TimeOut() override;
 private:
  Ap *ap_;
  Client *client_;
  int block_;
};

#endif //NLFB_AP_RECEIVE_FROM_PRODUCER_H
