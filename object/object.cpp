#include "object.h"
bool Object::IsEmpty() {
  return timer_->IsEmpty();
}
void Object::Add(Process *process) {
  timer_->Add(process);
}
double Object::send_gap_ = 0.01;
double Object::GetSendGap() {
  return send_gap_;
}
void Object::SetSendGap(double send_gap) {
  send_gap_ = send_gap;
}
double Object::GetTime() {
  return timer_->GetTop()->GetTime();
}
