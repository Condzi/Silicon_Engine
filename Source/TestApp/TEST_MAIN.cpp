#include "../Silicon/Silicon.hpp"
#include <iostream>

using namespace se;

int main()
{
	Image img("image.SEgraphics");

	for (int i = 0; i < img.GetSize().x * img.GetSize().y; ++i)
	{
		std::cout << img.GetPixelsReference()[i];
	}
	
	std::cin.get();
	return 0;
}