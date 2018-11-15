#include <iostream>
#include "producer.h"
#include "ap.h"
#include "client.h"
#include "process/ap_receive_from_producer.h"
void Producer::SetAp(Ap *ap) {
  ap_ = ap;
}
void Producer::Receive(Client *client, int block) {
  ap_->Add(new ApReceiveFromProducer(Timer::GetCurrentTime() + Time(), ap_, client, block));
}
Producer::Producer(double speed, double delay) : speed_(speed), delay_(delay){}
double Producer::size_ = 1000;
double Producer::Time() {
  return size_ / speed_ + delay_;
}
double Producer::GetPacketSize() {
  return size_;
}
