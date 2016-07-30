#include "Silicon/Silicon.hpp"
#include <iostream>

using namespace se;

int main()
{
	std::cerr.sync_with_stdio(false);
	Image img;
	Sprite sprites[1];
	Renderer ren;

	Clock fpsClock;
	Clock counterClock;
	unsigned fpsCounter = 0;
	unsigned fpsCounter2 = 0;
	short fpsLimit = 0;
	Time fpsDelta = 0;

	if (!img.LoadFromFile(("Resource/image.SEgraphics")))
		std::cout << "Failed";

	for (Sprite & spr : sprites)
	{
		spr.SetImagePointer(img);
		spr.SetPosition(Vector2i(0, 0));
	}


	while (true)
	{
		/*	if(fpsLimit > 0)
		Sleep(fpsLimit + fpsDelta.AsMilliseconds() / 1015);*/

		ren.Clear();
		for(Sprite & spr : sprites)
			ren.Draw(spr);
		ren.Display();

		if (counterClock.GetEleapsedTime().AsMilliseconds() >= 1000)
		{
			fpsCounter2 = fpsCounter;
			counterClock.Restart();
			fpsCounter = 0;
		}

		in::SetCursorPosition(0, 10);
		in::SetTextColor(Color::Green, Color::Gray);
		std::cerr << "FPS: " << fpsCounter2 << "/" << fpsLimit;


		++fpsCounter;
		//fpsDelta = fpsClock.Restart();
	}

	std::cin.get();
	return 0;
}