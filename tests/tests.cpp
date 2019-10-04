#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../spinnercpp.h"

using namespace std;

TEST_CASE("simple working") {
  int a = 5;
  int b = 5;
  //
  //CHECK(throw_if(true, std::runtime_error("whops!")) == 42);
  //
  //	CHECK_FALSE(!(a == b));
  //
  REQUIRE(a == b);
  
  CHECK_EQ(a, b);
  
  //	CHECK(doctest::Approx(0.1000001) == 0.1000002);
  //	CHECK(doctest::Approx(0.502) == 0.501);
}


TEST_CASE("spinnercpp") {
  {
    auto spin = std::make_unique<spinnercpp::spinner>(100ms, 10, "final msg", "> ", " |");
    spin->start();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  }
  
  for(int i = 0 ; i < spinnercpp::CharSets.size(); i++){
    cout << endl;
    auto spin = std::make_unique<spinnercpp::spinner>(100ms, i);
    spin->start();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}
