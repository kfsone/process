#include <cstdlib>
#include <iostream>
#include <string_view>
#include <string>
#include <unistd.h>

int main(int argc, const char* argv[])
{
	auto pid = getpid();

	std::string cmd = std::string(argv[1]) + " 60000";
	std::cout << "middle:" << pid << ": launching: " << cmd << "\n";
	system(cmd.c_str());
	std::cout << "middle:" << pid << ": finished\n";
}
