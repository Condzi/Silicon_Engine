#include "Renderer.hpp"


namespace se
{
	Renderer::Renderer() :
		m_hConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE))
	{}

	Renderer::Renderer(HANDLE hConsole) :
		m_hConsoleOutput(hConsole)
	{}

	Renderer::~Renderer()
	{
	}


	void Renderer::Draw(Sprite & sprite)
	{
		for (Pixel & px : sprite.m_image->m_pixels)
			m_buffer.push_back(&px);
	}

	void Renderer::Draw(Pixel & px)
	{
		m_buffer.push_back(&px);
	}

	void Renderer::Draw(Pixel * px, uint32_t size)
	{
		for (uint16_t i = 0; i < size; ++i)
			m_buffer.push_back(&px[i]);
	}

	void Renderer::Draw(const char * chr, Color fgColor, Color bgColor, Vector2i position)
	{
		Pixel * px;

		for (uint16_t i = 0; chr[i] != '\0'; ++i)
		{
			px = new Pixel(fgColor, bgColor, position);
			px->m_look = chr[i];

			m_buffer.push_back(px);
			m_allocatedPosition.push_back(m_buffer.size() - 1);
			
			position.x += 1;
		}
	}

	void Renderer::Clear()
	{
		if (m_allocatedPosition.size())
			for (unsigned & i : m_allocatedPosition)
				delete m_buffer[i];

		m_buffer.clear();
		m_allocatedPosition.clear();
	}

	void Renderer::Display(const HANDLE & cons)
	{
		if (!m_buffer.size())
			return;

		//Gdzie ma sie skonczyc tablica
		COORD maxWrite{ 0,0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD bfsize = { BUFF_X, BUFF_Y };
		COORD pos = { 0,0 };
		SMALL_RECT zone{ 0, 0, 0, 0 };

		CHAR_INFO charInfo[BUFF_X][BUFF_Y];

		for (Pixel * px : m_buffer)
		{
			charInfo[px->m_position.y][px->m_position.x].Char.AsciiChar = px->m_look;
			charInfo[px->m_position.y][px->m_position.x].Attributes = px->m_foregroundColor | px->m_backgroundColor << 4;

			if (px->m_position.x > maxWrite.X)
				maxWrite.X = px->m_position.x;

			if (px->m_position.y > maxWrite.Y)
				maxWrite.Y = px->m_position.y;
		}

		zone = { 0,0, maxWrite.X, maxWrite.Y };


		WriteConsoleOutput(console, *charInfo, bfsize, pos, &zone);

		//for (Pixel * px : m_buffer)
		//{
		//	in::SetCursorPosition(px->m_position);
		//	in::SetTextColor(px->m_foregroundColor, px->m_backgroundColor);
		//	fwrite(&px->m_look, 1, 1, stderr);
		//}
	}
}

