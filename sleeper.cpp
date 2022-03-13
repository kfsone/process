#include <cstdlib>
#include <iostream>
#include <unistd.h>


int main(int argc, const char* argv[])
{
	auto pid = getpid();

	std::string cmd = "python3 -c \"import os, time; print('python:%s: sleeping' % os.getpid()); time.sleep(300)\"";
	std::cout << "sleeper:" << pid << ": launching: " << cmd << "\n";

	system(cmd.c_str());

	std::cout << "sleeper:" << pid << ": done\n";
}
