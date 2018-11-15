#include <process/client_receive.h>
#include <iostream>
#include "process/ap_receive_from_client.h"
#include "wifi.h"
#include "client.h"
#include "producer.h"

Wifi::Wifi(Timer *timer, int speed) : Object(timer), speed_(speed) {
}
void Wifi::ClientSend(Client *client, int block) {
  Add(new ApReceiveFromClient(Timer::GetCurrentTime() + Client::GetInterestSize() / speed_, ap_, client, block));
}
void Wifi::SetAp(Ap *ap) {
  ap_ = ap;
}
void Wifi::SetClients(const std::vector<Client *> *clients) {
  clients_ = clients;
}
void Wifi::ApSend(Client *client, int block) {
  double time = Timer::GetCurrentTime() + Producer::GetPacketSize() / speed_;
  if (client) {
    Add(new ClientReceive(time, client, block));
  } else {
    std::cout << "Broadcast packet:" << block << " \n";
    for (auto c: *clients_) {
      Add(new ClientReceive(time, c, block));
    }
  }
}
bool Wifi::IsEmpty() {
  return Object::IsEmpty() || Timer::GetCurrentTime() + 1e-6 > GetTime();
}

