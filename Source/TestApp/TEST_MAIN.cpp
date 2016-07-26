#include "../Silicon/Silicon.hpp"
#include <iostream>

int main()
{
	se::Time maxTime = se::Milliseconds(1000);
	se::Clock clock;

	while (clock.GetEleapsedTime().AsMicroseconds() < maxTime.AsMicroseconds())
	{
		std::cout << clock.GetEleapsedTime().AsSeconds() <<"\n";
	}

	std::cin.get();
	return 0;
}