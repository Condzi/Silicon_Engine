#include "Renderer.hpp"


namespace se
{
	Renderer::Renderer()
	{
	}

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

	void Renderer::Clear()
	{
		m_buffer.clear();
	}

	void Renderer::Display()
	{
		if (!m_buffer.size())
			return;

		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD bfsize = { 100, 100 };
		COORD pos = { 0,0 };
		SMALL_RECT zone{ 0,0,100,100 };

		CHAR_INFO charInfo[100][100];

		for (Pixel * px : m_buffer)
		{
			charInfo[px->m_position.y][px->m_position.x].Char.AsciiChar = px->m_look;
			charInfo[px->m_position.y][px->m_position.x].Attributes = px->m_foregroundColor | px->m_backgroundColor << 4;
		}

		WriteConsoleOutput(console, *charInfo, bfsize, pos, &zone);

		//for (Pixel & px : m_buffer)
		//{
		//	in::SetCursorPosition(px->m_position);
		//	in::SetTextColor(px->m_foregroundColor, px->m_backgroundColor);
		//	fwrite(&px->m_look, 1, 1, stderr);
		//}
	}
}

