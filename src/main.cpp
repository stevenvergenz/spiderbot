#include <iostream>

int main(int argc, char **argv)
{
	const double inputValue = std::stod(argv[1]);
	std::cout << "Hello world!" << inputValue << std::endl;
	return 0;
}
