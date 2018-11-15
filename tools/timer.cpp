#include "timer.h"

#include <vector>
#include <iostream>
double Timer::current_time_ = 0;
void Timer::Add(Process *process) {
  processes_.push(process);
}
void Timer::Run() {
  std::cout << "process size:" << processes_.size() << '\n';
  auto p = processes_.top();
  processes_.pop();
  SetCurrentTime(p->GetTime());
  std::cout << "current time: " << GetCurrentTime() << '\n';
  p->TimeOut();
  delete p;
}
Process *Timer::GetTop() const {
  return processes_.top();
}
bool Timer::IsEmpty() const {
  return processes_.empty();
}
unsigned long Timer::GetSize() const {
  return processes_.size();
}
