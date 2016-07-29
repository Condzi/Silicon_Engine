#include "Silicon/Silicon.hpp"
#include <iostream>

using namespace se;

int main()
{
	Image img;
	Sprite spr;
	Renderer ren;

	Clock fpsClock;
	Clock counterClock;
	unsigned fpsCounter = 0;
	short fpsLimit = 0;
	Time fpsDelta = 0;

	if (!img.LoadFromFile(("Resource/image.SEgraphics")))
		std::cout << "Failed";

	spr.SetImagePointer(img);

	while (true)
	{
		/*	if(fpsLimit > 0)
		Sleep(fpsLimit + fpsDelta.AsMilliseconds() / 1015);*/

		ren.Clear();
		//in::ClearScreen();
		for (int i = 0; i < 50; ++i)
			ren.AddSprite(spr);
		ren.Display();

		if (counterClock.GetEleapsedTime().AsMilliseconds() >= 1000)
		{
			in::SetCursorPosition(0, 10);
			in::SetTextColor(Color::Green, Color::Gray);
			std::cout << "FPS: " << fpsCounter << "/" << fpsLimit;

			counterClock.Restart();
			fpsCounter = 0;
		}

		++fpsCounter;
		//fpsDelta = fpsClock.Restart();
	}

	std::cin.get();
	return 0;
}