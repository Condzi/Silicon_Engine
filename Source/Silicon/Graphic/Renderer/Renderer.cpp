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
		m_buffer.push_back(&sprite);
	}

	void Renderer::Clear()
	{
		m_buffer.clear();
	}

	void Renderer::Display()
	{
		for (Sprite * spr : m_buffer)
			for (Pixel & px : spr->GetImagePointer()->m_pixels)
			{
				in::SetCursorPosition(px.m_position);
				in::SetTextColor(px.m_foregroundColor, px.m_backgroundColor);
				fwrite(&px.m_look, 1, 1, stderr);
				//std::cerr << px.m_look;
			}
	}
}

