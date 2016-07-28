#include "Image.hpp"


namespace se
{
	void Image::deletePixels()
	{
		for (Pixel * px : m_pixels)
			delete px;
	}

	Image::Image()
	{}

	Image::Image(const std::string & pathToFile)
	{
		LoadFromFile(pathToFile);
	}

	Image::~Image()
	{
		deletePixels();
	}

	Vector2u16 Image::GetSize()
	{
		return m_size;
	}

	bool Image::LoadFromFile(const std::string & pathToFile)
	{
		/*
			File format:
			width height
			pixel_look pixel_fg_color pixel_bg_color pixel_position (relative to 0,0) <- repat 
			
		*/
		Vector2u16 size = Vector2u16();
		Pixel temporaryPixel = Pixel();
		uint16_t temporaryInt = 0;
		std::vector<Pixel> pixels;
		std::ifstream file(pathToFile);

		if (!file.good())
			return false;

		file >> size.x;
		file >> size.y;


		for(unsigned i = 0; i < size.x * size.y; ++i)
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
			temporaryPixel.SetPosition(Vector2i(temporaryPixel.GetPosition().x, temporaryInt));

			pixels.push_back(temporaryPixel);
		}

		file.close();

		if (pixels.size() != size.x * size.y)
			return false;

		deletePixels();
		m_pixels.clear();
		m_pixels.resize(pixels.size());

		for (unsigned i = 0; i < m_pixels.size(); ++i)
		{
			m_pixels[i] = new Pixel(pixels[i]);
		}

		m_size = size;

		return true;
	}



}
