#include "Silicon/Silicon.hpp"
#include <string>

using namespace se;

int main()
{
	Renderer ren;
	std::string keyPressed = "'L' Key pressed";
	bool end = false;


	while (!end)
	{
		ren.Clear();
		if (se::IsKeyPressed(Key::L))
			ren.Draw(keyPressed.c_str(), Color::White, Color::Black, Vector2i(0,1));
		ren.Draw(Pixel());
		ren.Display();
	}

	return 0;
}
