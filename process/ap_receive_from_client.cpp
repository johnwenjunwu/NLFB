#include <iostream>
#include <object/client.h>
#include "ap_receive_from_client.h"
#include "object/ap.h"
ApReceiveFromClient::ApReceiveFromClient(double time, Ap *ap, Client *client, int block)
    : Process(time), ap_(ap), client_(client), block_(block) {
  std::cout << "Ap tries to receive Interest with id: " << block_ << " from Client:" << client_->GetId()
            << " at time:" << time << '\n';
}
void ApReceiveFromClient::TimeOut() {
  std::cout << "Ap receives Interest: " << block_ << " from Client:" << client_->GetId() << '\n';
  ap_->SendToProducer(client_, block_);
}
