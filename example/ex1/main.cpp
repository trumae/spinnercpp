#include "../../spinnercpp.h"

int main() {
  auto spin = new spinnercpp::spinner();
  
  spin->start();
  std::this_thread::sleep_for(std::chrono::milliseconds(4000)); 
  spin->stop();
  
  delete spin;
  
  return 0;
}
