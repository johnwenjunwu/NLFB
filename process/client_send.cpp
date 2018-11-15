#include <iostream>
#include "client_send.h"
#include "object/client.h"

void ClientSend::TimeOut() {
    client_->Send();
}
ClientSend::ClientSend(double time, Client *client) : Process(time), client_(client) {
  std::cout << "Client:" << client->GetId() << " tries to send at time:" << time << '\n';
}
