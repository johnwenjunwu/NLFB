#ifndef NLFB_ADD_CLIENT_H
#define NLFB_ADD_CLIENT_H

#include <tools/test.h>
#include "process.h"
class AddClient : public Process{
 public:
  explicit AddClient(int time, Test *test, int id, bool b);
  void TimeOut() override;
 private:
  int id_;
  Test *test_;
  bool multi_;
};

#endif //NLFB_ADD_CLIENT_H
