#ifndef NLFB_WIFI_H
#define NLFB_WIFI_H

#include <vector>
#include "object.h"

class Ap;
class Client;
class Wifi : public Object {
 public:
  explicit Wifi(Timer *timer, int speed = 1'000'000);
  void ClientSend(Client *client, int block);
  void ApSend(Client *client, int block);
  void SetAp(Ap *ap);
  bool IsEmpty() override;
  void SetClients(const std::vector<Client *> *clients);
 private:
  int speed_;
  Ap *ap_;
  const std::vector<Client *> *clients_ = nullptr;
};

#endif //NLFB_WIFI_H
