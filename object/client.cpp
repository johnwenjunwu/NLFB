#include "client.h"
#include "wifi.h"
#include <iostream>
#include "process/client_send.h"

void Client::Start() {
  std::cout << "Client::Start with id=" << id_ << '\n';
}
void Client::SetWifi(Wifi *wifi) {
  wifi_ = wifi;
}
void Client::Send() {
  auto index = NextBlock();
  if (index < block_num_) {
    if (!GetIsLeader()) return;
    if (wifi_->IsEmpty()) {
      wait_ = GetSendGap();
      wifi_->ClientSend(this, index);
    } else {
      Add(new ClientSend(Timer::GetCurrentTime() + wait_, this));
      wait_ *= 2;
    }
  } else {
    std::cerr << "Client: " << id_ << " finishes at time: " << Timer::GetCurrentTime() << std::endl;
    SetIsFinish(true);
  }
}
unsigned long Client::NextBlock() const {
  auto index = find(isReceived.begin(), isReceived.end(), false) - isReceived.begin();
  return index;
}
int Client::GetId() const {
  return id_;
}
double Client::interest_size_ = 100;
double Client::GetInterestSize() {
  return interest_size_;
}
void Client::Receive(int block) {
  isReceived[block] = true;
  Send();
}
void Client::SetInterestSize(double interest_size) {
  interest_size_ = interest_size;
}
bool Client::IsFinish() const {
  return is_finish_;
}
void Client::SetIsFinish(bool is_finish) {
  is_finish_ = is_finish;
}
bool Client::GetIsLeader() const {
  return is_leader_;
}
void Client::SetIsLeader(bool is_leader) {
  is_leader_ = is_leader;
}
