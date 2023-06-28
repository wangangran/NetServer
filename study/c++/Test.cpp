#include <iostream>
#include <string>

int main(int argc, char **argv) {
    std::string cmd = "tar --use-compress-program=\"pigz -p2\" -xvpf ";
	std::cout << cmd << std::endl;
    return 0;
}