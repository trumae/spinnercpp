#include "../../spinnercpp.h"

int main() {
  auto spin = std::make_unique<spinnercpp::spinner>();
  spin->start();
  std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
  
  return 0;
}
