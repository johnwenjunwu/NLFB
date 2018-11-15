#ifndef NLFB_TIMER_H
#define NLFB_TIMER_H

#include <set>
#include <queue>
#include "process/process.h"

class Timer {
 public:
  void Add(Process *process);
  void Run();
  static double GetCurrentTime() {
    return current_time_;
  }
  static void SetCurrentTime(double current_time) {
    current_time_ = current_time;
  }
  Process * GetTop() const;
  bool IsEmpty() const;
  unsigned long GetSize() const;
 private:
  struct ProcessCmp {
    bool operator()(const Process *a, const Process *b) const {
      return a->GetTime() > b->GetTime();
    };
  };
  std::priority_queue<Process *, std::vector<Process *>, ProcessCmp> processes_;
  static double current_time_;
};

#endif //NLFB_TIMER_H
