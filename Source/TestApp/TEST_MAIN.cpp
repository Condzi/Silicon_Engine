#include "Silicon/Silicon.hpp"
#include <string>

using namespace se;

int main()
{
	Renderer ren;
	bool end = false;
	char text[] = "This is sample text!";
	std::string text2 = "Other sample text, hey!";
	Vector3i16 vec(1, 2, 3);

	in::SetTextSize(TextSize::G);

	while (!end)
	{
		ren.Clear();
		ren.Draw(text, Color::Black, Color::Light_White, Vector2i(0, 0));
		ren.Draw(text2.c_str(), Color::Black, Color::Light_White, Vector2i(0, 1));
		ren.Draw(vec.GetInString().c_str(), Color::Black, Color::Light_White, Vector2i(0, 2));
		ren.Display();
	}

	return 0;
}
