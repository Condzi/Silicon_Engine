#include "Silicon/Silicon.hpp"
#include <iostream>

using namespace se;

int main()
{
	Image img;

	if (!img.LoadFromFile(("Resource/image.SEgraphics")))
		std::cout << "Failed";
	std::vector<Pixel> px = img.GetPixels();


	for (int i = 0; i < px.size(); ++i)
	{
		std::cout << img.GetPixelsReference()[i];
	}
	
	std::cin.get();
	return 0;
}