#ifndef NLFB_PRODUCER_H
#define NLFB_PRODUCER_H

class Ap;
class Client;
class Producer {
 public:
  explicit Producer(double speed = 4'000'000, double delay = 0.1);
  void SetAp(Ap *ap);
  void Receive(Client *client, int block);
  static double GetPacketSize();
 private:
  double Time();
  Ap *ap_;
  double speed_;
  static double size_;
  double delay_;
};

#endif //NLFB_PRODUCER_H
