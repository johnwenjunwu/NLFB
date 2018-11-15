#include <iostream>
#include "add_client.h"
AddClient::AddClient(int time, Test *test, int id, bool b) : Process(time), test_(test), id_(id), multi_(b){
}
void AddClient::TimeOut() {
  std::cout << "AddClient:" << id_ << '\n';
  test_->CreateClient(id_, multi_);
  test_->SetLeader();
}
