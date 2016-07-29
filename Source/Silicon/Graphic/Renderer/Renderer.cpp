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
			
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD bfsize = { GetSystemMetrics(SM_CXSIZE), GetSystemMetrics(SM_CYSIZE) };
		COORD pos = { 0,0 };
		SMALL_RECT zone = { 0, 0, GetSystemMetrics(SM_CXSIZE), GetSystemMetrics(SM_CYSIZE) };

		CHAR_INFO ** charInfo = new CHAR_INFO * [GetSystemMetrics(SM_CXSIZE)];

		for (unsigned i = 0; i < GetSystemMetrics(SM_CXSIZE); ++i)
			charInfo[i] = new CHAR_INFO[SM_CYSIZE];

		for (Pixel & px : m_buffer)
		{
			charInfo[px.m_position.x][px.m_position.y].Char.AsciiChar = px.m_look;
			charInfo[px.m_position.x][px.m_position.y].Attributes = px.m_foregroundColor | px.m_backgroundColor << 4;
			/*in::SetCursorPosition(px.m_position);
			in::SetTextColor(px.m_foregroundColor, px.m_backgroundColor);
			fwrite(&px.m_look, 1, 1, stderr);*/
			//std::cerr << px.m_look;
		}
		WriteConsoleOutput(console, *charInfo, bfsize, pos, &zone);

		for (unsigned i = 0; i < GetSystemMetrics(SM_CXSIZE); ++i)
			delete[] charInfo[i];

		delete[] charInfo;
	}
}

