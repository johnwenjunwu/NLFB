#include <iostream>
#include <process/client_send.h>
#include <object/multi_ap.h>
#include "process/add_client.h"
#include "test.h"
void Test::Run() {
  while (auto timer = NextTimer()) {
    if (timer->IsEmpty()) break;
    timer->Run();
  }
  std::cout << "Finish at time: " << Timer::GetCurrentTime() << '\n';
}
Timer *Test::NextTimer() {
  return *std::min_element(timers_.begin(), timers_.end(), timer_cmp);
}
Test::Test(int client_num, bool multi) : client_num_(client_num), multi_(multi) {
  Create();
  Set();
}
void Test::Set() const {
  SetWifi();
  SetAp();
  SetProducer();
}
void Test::SetWifi() const {
  wifi_->SetAp(ap_);
  wifi_->SetClients(&clients_);
}
void Test::Create() {
  CreateWifi();
  CreateClients(multi_);
  if (multi_) {
//    CreateMultiClients();
    CreateMultiAp();
  } else {
    CreateAp();
  }
  CreateProducer();
}
void Test::CreateAp() {
  auto timer = new Timer();
  timers_.push_back(timer);
  ap_ = new Ap{timer};
}
void Test::CreateClients(bool multi) {
  auto *timer = new Timer();
  timers_.push_back(timer);
  for (int i = 0; i < client_num_; ++i) {
    timer->Add(new AddClient(i * 100, this, i, multi));
  }
}
void Test::CreateClient(int i, bool b) {
  auto *timer = new Timer();
  timers_.push_back(timer);
  auto client = new Client{timer, i, 10'000, b};
  client->Add(new ClientSend(Timer::GetCurrentTime(), client));
  client->SetWifi(wifi_);
  clients_.push_back(client);
}
void Test::CreateWifi() {
  Object::SetSendGap(0.1);
  auto timer = new Timer();
  wifi_ = new Wifi{timer};
  timers_.push_back(timer);
}
Test::~Test() {
  delete ap_;
  delete wifi_;
  for (auto p: clients_) {
    delete p;
  }
  for (auto t: timers_) {
    delete t;
  }
}
void Test::CreateProducer() {
  producer_ = new Producer();
}
void Test::SetAp() const {
  ap_->SetWifi(wifi_);
  ap_->SetProducer(producer_);
}
void Test::SetProducer() const {
  producer_->SetAp(ap_);
}
void Test::CreateMultiAp() {
  auto timer = new Timer();
  timers_.push_back(timer);
  ap_ = new MultiAp{timer};
}
void Test::CreateMultiClients() {
  std::cerr << "CreateMultiClients\n";
  for (int i = 0; i < client_num_; ++i) {
    auto *timer = new Timer();
    timers_.push_back(timer);
    auto client = new Client{timer, i, 10'000};
    client->Add(new ClientSend(0, client));
    clients_.push_back(client);
  }
}
bool Test::TimerCmp::operator()(const Timer *a, const Timer *b) const {
  if (a->IsEmpty()) return false;
  if (b->IsEmpty()) return true;
  return a->GetTop()->GetTime() < b->GetTop()->GetTime();
}
void Test::SetLeader() {
  auto client = std::find_if(clients_.begin(), clients_.end(), [](const Client *client) { return !client->IsFinish();});
  if (client != clients_.end()) {
    (*client)->SetIsLeader(true);
  }
}
