#ifndef NLFB_PROCESS_H
#define NLFB_PROCESS_H

#include <memory>

class Process {
 public:
  explicit Process(double time) : time_{time} {}
  double GetTime() const {
    return time_;
  }
  virtual void TimeOut() = 0;
  virtual ~Process() = default;
 private:
  double time_;
};

#endif //NLFB_PROCESS_H
