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
			spr->Draw();
	}
}

