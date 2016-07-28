#include "Silicon/Silicon.hpp"
#include <iostream>

using namespace se;

int main()
{
	Image img;
	Sprite spr;

	if (!img.LoadFromFile(("Resource/image.SEgraphics")))
		std::cout << "Failed";
	
	spr.SetImagePointer(img);

	spr.Draw();

	std::cin.get();
	spr.SetPosition(Vector2i(10, 10));
	spr.Draw();

	std::cin.get();
	spr.Move(Vector2i(0, 10));
	spr.Draw();
	
	std::cin.get();
	return 0;
}