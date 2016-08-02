#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Silicon/Graphic/Pixel.hpp"


namespace se
{
	class Pixel;

	/*
		Storage for in::Pixel - s loaded from file.
		Used in: in::Sprite
	*/
	class Image
	{
		friend class Sprite;
		friend class Renderer;

	public:
		Image();
		Image(const std::string & pathToFile);
		~Image();

		Vector2u16 GetSize();
		bool LoadFromFile(const std::string & pathToFile);

	private:
		std::vector<Pixel> m_pixels;
		Vector2u16 m_size;
	};

}

