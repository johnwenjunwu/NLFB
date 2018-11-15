#include "multi_ap.h"
#include "client.h"
void MultiAp::SendToClient(Client *client, int block) {
  Ap::SendToClient(nullptr, block);
}
