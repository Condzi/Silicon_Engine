#include "Renderer.hpp"


namespace se
{
	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}


	void Renderer::AddSprite(Sprite & sprite)
	{
		for (Pixel & px : sprite.GetImagePointer()->m_pixels)
			m_buffer.push_back(px);
	}

	void Renderer::Clear()
	{
		m_buffer.clear();
	}

	void Renderer::Display()
	{
		for (Pixel & px : m_buffer)
			std::cout << px;
	}
}

