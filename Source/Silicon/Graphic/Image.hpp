#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Pixel.hpp"


namespace se
{
	class Pixel;

	class Image
	{
		friend class Sprite;
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

