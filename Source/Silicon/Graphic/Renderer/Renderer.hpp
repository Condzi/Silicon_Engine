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
		Renderer(HANDLE hConsole);
		~Renderer();

		void Draw(Sprite & sprite);
		void Draw(Pixel & px);
		void Draw(Pixel * px, uint32_t size);
		void Draw(const char * chr, Color fgColor, Color bgColor, Vector2i position);

		void Clear();
		void Display(const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));
	
	private:
		std::vector<Pixel*> m_buffer;
		// position in m_buffer of allocated (x = new x) memory that need to be delete
		std::vector<unsigned> m_allocatedPosition;
		HANDLE m_hConsoleOutput;
		static const uint16_t BUFF_X = 500;
		static const uint16_t BUFF_Y = 500;
	};
}


