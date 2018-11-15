#include <iostream>
#include <object/client.h>
#include "ap_send_to_producer.h"
#include "object/ap.h"
ApSendToProducer::ApSendToProducer(double time, Ap *ap, Client *client, int block)
    : Process(time), ap_(ap), client_(client), block_(block) {
  std::cout << "Ap tries to send data:" << block << " at time:" << time << '\n';
}
void ApSendToProducer::TimeOut() {
  ap_->SendToProducer(client_, block_);
}
