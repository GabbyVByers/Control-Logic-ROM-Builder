
#include <iostream>



int main()
{

	unsigned int accumulator = 0;
	for (int i = 0; i < 30; i++)
	{
		accumulator += std::pow(2, i);
		std::cout << (unsigned)accumulator << "\n";
	}

	std::cout << "Hello World!\n";
	return 0;
}

