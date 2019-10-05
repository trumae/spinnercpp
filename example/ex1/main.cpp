#include "../../spinnercpp.h"

using std::chrono_literals::operator ""ms;

int main() {
	auto spin = std::make_unique<spinnercpp::spinner>(500ms);
	spin->start();
	std::this_thread::sleep_for(std::chrono::milliseconds(8000));

	return 0;
}
