#include "../Silicon/Silicon.hpp"
#include <iostream>

int main()
{
	se::Time maxTime = se::Milliseconds(1000);
	se::Clock clock;

	se::in::SetTextSize(se::TextSize::G);
	se::in::SetScreenSize(se::Vector2u16(64, 32));


	while (clock.GetEleapsedTime().AsMicroseconds() < maxTime.AsMicroseconds())
	{
		se::in::SetCursorPosition(se::Vector2u16(5, 5));
		se::in::SetTextColor(se::Color::Light_White);
		std::cout << char(1);

		se::in::SetCursorPosition(se::Vector2u16(0, 0));
		se::in::SetTextColor(se::Color::Gray);
		std::cout << clock.GetEleapsedTime().AsSeconds() <<"\n";
	}

	std::cin.get();
	return 0;
}