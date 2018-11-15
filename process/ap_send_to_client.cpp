#include <iostream>
#include <object/client.h>
#include "ap_send_to_client.h"
#include "object/ap.h"

ApSendToClient::ApSendToClient(double time, Ap *ap, Client *client, int block)
    : Process(time), ap_(ap), client_(client), block_(block) {
  if (client) {
    std::cout << "Ap tries to send packet:" << block << " back to Client" << client_->GetId() << " at time:" << time << '\n';
  } else {
    std::cout << "Ap tries to broadcast packet:" << block << " at time: " << time << '\n';
  }
}
void ApSendToClient::TimeOut() {
  ap_->SendToClient(client_, block_);
}
