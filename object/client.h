#ifndef NLFB_CLIENT_H
#define NLFB_CLIENT_H

#include "object.h"

class Wifi;
class Client : public Object {
 public:
  Client(Timer *timer, int id, unsigned int block_num = 100'000, bool multi = false)
      : Object(timer), id_(id), block_num_(block_num), isReceived(block_num), is_leader_(!multi) {};
  void Start();
  void Send();
  void SetWifi(Wifi *wifi);
  int GetId() const;
  static double GetInterestSize();
  void Receive(int block);
  static void SetInterestSize(double interest_size);
  bool IsFinish() const;
  void SetIsFinish(bool is_finish);
  bool GetIsLeader() const;
  void SetIsLeader(bool is_leader);
 private:
  std::vector<bool> isReceived;
  int id_;
  int block_num_;
  static double interest_size_;
  Wifi *wifi_ = nullptr;
  double wait_ = GetSendGap();
  unsigned long NextBlock() const;
  bool is_finish_ = false;
  bool is_leader_ = false;
};

#endif //NLFB_CLIENT_H
