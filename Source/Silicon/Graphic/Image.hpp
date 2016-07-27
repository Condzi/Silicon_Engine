#pragma once
#include "Silicon/Silicon.hpp"
#include <vector>
#include <fstream>

namespace se
{
	class Image
	{
	public:
		Image();
		Image(const std::string & pathToFile);
		~Image();

		std::vector<se::Pixel> GetPixels();
		Vector2u16 GetSize();
		const std::vector<se::Pixel> & GetPixelsReference();

		bool LoadFromFile(const std::string & pathToFile);

	private:
		std::vector<se::Pixel> m_pixels;
		Vector2u16 m_size;
	};

}

