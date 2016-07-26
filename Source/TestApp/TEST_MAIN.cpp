#include "../Silicon/Silicon.hpp"
#include <iostream>

int main()
{
	se::Vector2<int> test(3,3);
	se::Vector2<int> test2(2, 2);

	test = test2;
	std::cout <<test<<"\n";

	std::cin.get();
}