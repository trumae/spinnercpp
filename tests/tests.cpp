#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "../spinnercpp.h"

using namespace std;

TEST_CASE ("spinnercpp") {
	{
		auto spin = std::make_unique<spinnercpp::spinner>(100ms, 10, "final msg", "> ", " |");
		spin->start();
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}

	for (int i = 0; i < spinnercpp::CharSets.size(); i++) {
		cout << endl;
		auto spin = std::make_unique<spinnercpp::spinner>(100ms, i);
		spin->start();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
