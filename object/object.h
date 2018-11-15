#ifndef NLFB_OBJECT_H
#define NLFB_OBJECT_H

#include <memory>
#include "tools/timer.h"

class Object {
 public:
  explicit Object(Timer *timer) : timer_(timer) {}
  virtual bool IsEmpty();
  void Add(Process *process);
  static double GetSendGap();
  static void SetSendGap(double send_gap);
  double GetTime();
 private:
  Timer *timer_;
  static double send_gap_;
};


#endif //NLFB_OBJECT_H
