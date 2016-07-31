#include "Silicon/Silicon.hpp"

using namespace se;

int main()
{
	//Framerate Limiter
	Time fpsDelta(0);
	Time fpsLimit = Seconds(1.f / 32.f);
	Clock fpsClock;
	//Framerate Counter
	unsigned fpsCounter = 0;
	unsigned fpsCounterBuff = fpsCounter;
	Time fpsCounterUpdate = Seconds(1);
	Clock fpsCounterClock;

	
	bool isRunning = true;

	while (isRunning)
	{	
		Sleep(abs(fpsLimit.AsMilliseconds() - fpsDelta.AsMilliseconds()));

		if (fpsCounterClock.GetEleapsedTime().AsMicroseconds() >= fpsCounterUpdate.AsMicroseconds())
		{
			fpsCounterClock.Restart();
			fpsCounterBuff = fpsCounter;
			fpsCounter = 0;
		}

		in::SetCursorPosition(0, 0);
		std::cout << fpsCounterBuff << " FPS\n";

		++fpsCounter;
		fpsDelta = fpsClock.Restart();
	}

}