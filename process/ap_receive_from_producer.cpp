#include <iostream>
#include "ap_receive_from_producer.h"
#include "object/client.h"
ApReceiveFromProducer::ApReceiveFromProducer(double time, Ap *ap, Client *client, int block)
    : Process(time), ap_(ap), client_(client), block_(block) {}
void ApReceiveFromProducer::TimeOut() {
  std::cout << "Ap receives Data:" << block_ << " from Producer for Client:" << client_->GetId() << '\n';
  ap_->SendToClient(client_, block_);
}
