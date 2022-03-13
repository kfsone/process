#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <unistd.h>

int main(int argc, const char* argv[])
{
	auto pid = getpid();

	std::string_view path = argv[0];
	auto slash = path.find_last_of("/");
	path = slash != path.npos ? path.substr(0, slash) : ".";

	std::string middle = std::string(path) + "/middle";
	std::string child  = std::string(path) + "/sleeper";

	std::string cmd = middle + " " + child;

	std::cout << "parent:" << pid << ": launching: " << cmd << "\n";
	system(cmd.c_str());
	std::cout << "parent:" << pid << ": finished\n";
}
