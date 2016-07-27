#include "Image.hpp"


namespace se
{
	Image::Image()
	{}

	Image::Image(const std::string & pathToFile)
	{
		LoadFromFile(pathToFile);
	}

	Image::~Image()
	{}

	std::vector<Pixel> Image::GetPixels()
	{
		return m_pixels;
	}

	Vector2u16 Image::GetSize()
	{
		return m_size;
	}

	const std::vector<Pixel>& Image::GetPixelsReference()
	{
		return m_pixels;
	}

	bool Image::LoadFromFile(const std::string & pathToFile)
	{
		/*
			File format:
			width height
			pixel_look pixel_fg_color pixel_bg_color pixel_position (relative to 0,0) <- repat 
			
		*/
		Vector2u16 size;
		Pixel temporaryPixel;
		uint16_t temporaryInt;
		std::vector<Pixel> pixels;
		std::ifstream file(pathToFile);

		if (!file.good())
			return false;

		file >> size.x;
		file >> size.y;

		while (!file.eof())
		{
			file >> temporaryInt;
			temporaryPixel.SetLook(temporaryInt);
			file >> temporaryInt;
			temporaryPixel.SetFGColor(Color(temporaryInt));
			file >> temporaryInt;
			temporaryPixel.SetBGColor(Color(temporaryInt));
			file >> temporaryInt;
			temporaryPixel.SetPosition(Vector2i(temporaryInt, temporaryPixel.GetPosition().y));
			file >> temporaryInt;
			temporaryPixel.SetPosition(Vector2i(temporaryPixel.GetPosition().y, temporaryInt));

			pixels.push_back(temporaryPixel);
		}

		file.close();

		if (pixels.size() < size.x * size.y || pixels.size() > size.x * size.y)
			return false;

		m_pixels = pixels;
		m_size = size;

		return true;
	}



}
