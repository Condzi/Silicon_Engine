#pragma once

#include "Silicon/Graphic/Sprite.hpp"

namespace se
{
	class Pixel;
	class Sprite;

	class NewRenderer
	{
	private:
		void addPixel(Pixel & px);
		void fillBlanks();

	public:
		NewRenderer();
		NewRenderer(const HANDLE & console);
		~NewRenderer();

		void Clear();
		void Draw(Sprite & spr);
		void Display();

	private:
		HANDLE m_hConsoleBuffer;
		std::vector<std::vector<Pixel>> m_pixels;
	};
}

