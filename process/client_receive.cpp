#include <iostream>
#include "client_receive.h"
#include "object/client.h"
ClientReceive::ClientReceive(double time, Client *client, int block) : Process(time), client_(client), block_(block) {
  std::cout << "Client:" << client->GetId() << " will receive packet: " << block_ << " at time:" << time << '\n';
}
void ClientReceive::TimeOut() {
  std::cout << "Client:" << client_->GetId() << " receives Packet: " << block_ << " from Ap at time:" << Timer::GetCurrentTime() << '\n';
  client_->Receive(block_);
}
