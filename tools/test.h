#ifndef NLFB_TEST_H
#define NLFB_TEST_H

#include <vector>
#include "timer.h"
#include "object/ap.h"
#include "object/client.h"
#include "object/wifi.h"
#include "object/producer.h"

class Test {
 public:
  void Run();
  Timer *NextTimer();
  explicit Test(int client_num, bool multi);
  virtual ~Test();
  virtual void CreateAp();
  void CreateMultiAp();
  virtual void CreateClients(bool multi);
  void CreateMultiClients();
  void CreateClient(int i, bool b);
  void SetLeader();
 private:
  bool multi_;
  void CreateWifi();
  void CreateProducer();
  void Create();
  void Set() const;
  void SetWifi() const;
  std::vector<Timer *> timers_;
  struct TimerCmp {
    bool operator()(const Timer *a, const Timer *b) const;
  } timer_cmp;
  Ap *ap_;
  std::vector<Client *> clients_;
  Wifi *wifi_;
  Producer *producer_;
  int client_num_;
  void SetClients() const;
  void SetAp() const;
  void SetProducer() const;
};

#endif //NLFB_TEST_H
