#include "../Silicon/Silicon.hpp"
#include <iostream>

int main()
{

	se::in::SetTextColor(se::Color::Light_Red, se::Color::Light_Green);
	std::cout << 'x';
	//for (int i = 0; i < 240; ++i)
	//{
	//	se::in::SetTextColor(i);
	//	std::cout<<i;
	//}
	std::cin.get();
	return 0;
}