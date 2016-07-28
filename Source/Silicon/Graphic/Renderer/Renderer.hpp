#pragma once
#include "Silicon/Graphic/Sprite.hpp"


namespace se
{
	class Sprite; 
	class Pixel;

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void AddSprite(Sprite & sprite);

		void Clear();
		void Display();
	
	private:
		std::vector<Pixel*> m_buffer;
	};
}


