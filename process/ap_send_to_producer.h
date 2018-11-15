#ifndef NLFB_AP_SEND_TO_PRODUCER_H
#define NLFB_AP_SEND_TO_PRODUCER_H

#include "process.h"
class Ap;
class ApSendToProducer : public Process{
 public:
  ApSendToProducer(double time,
                     Ap *ap,
                     Client *client,
                     int block);
  void TimeOut() override;
 private:
  Ap *ap_;
  Client *client_;
  int block_;
};

#endif //NLFB_AP_SEND_TO_PRODUCER_H
