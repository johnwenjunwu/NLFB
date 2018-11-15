#include <iostream>
#include <tools/test.h>
#include <fstream>

int main() {
  std::ofstream out{"out.txt"};
  std::cout.rdbuf(out.rdbuf());
  Test test(20, true);
  test.Run();
  return 0;
}