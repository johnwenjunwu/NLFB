#include "ap.h"
#include "wifi.h"
#include <iostream>
#include <process/ap_send_to_client.h>
#include "producer.h"
#include "process/client_receive.h"
#include "client.h"
void Ap::SetWifi(Wifi *wifi) {
  wifi_ = wifi;
}
void Ap::SendToClient(Client *client, int block) {
  if (wifi_->IsEmpty()) {
    wait_ = GetSendGap();
    wifi_->ApSend(client, block);
  } else {
    Add(new ApSendToClient(Timer::GetCurrentTime() + wait_, this, client, block));
    wait_ *= 2;
  }
}
void Ap::SetProducer(Producer *producer) {
  producer_ = producer;
}
void Ap::SendToProducer(Client *client, int block) {
  std::cout << "Producer receives request from Client:" << client->GetId() << '\n';
  producer_->Receive(client, block);
}
