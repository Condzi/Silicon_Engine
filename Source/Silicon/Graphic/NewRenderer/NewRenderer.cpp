#include "NewRenderer.hpp"


namespace se
{
	NewRenderer::NewRenderer() :
		m_hConsoleBuffer(GetStdHandle(STD_OUTPUT_HANDLE))
	{}

	NewRenderer::NewRenderer(const HANDLE & console) :
		m_hConsoleBuffer(console)
	{}

	NewRenderer::~NewRenderer()
	{
	}


	void NewRenderer::Clear()
	{
		m_pixels.clear();
	}

	void NewRenderer::Draw(Sprite & spr)
	{
		for (Pixel & px : spr.GetImagePointer()->m_pixels)
			m_pixels.push_back(px);
	}

	void NewRenderer::Display()
	{
		CHAR_INFO ** buff = new CHAR_INFO * [GetSystemMetrics(SM_CYSCREEN)];
		COORD size = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
		COORD start = { 0,0 };
		SMALL_RECT srect = { 0,0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

		for (uint16_t i = 0; i < GetSystemMetrics(SM_CYSCREEN); ++i)
			buff[i] = new CHAR_INFO[GetSystemMetrics(SM_CXSCREEN)];

		for (Pixel & px : m_pixels)
		{
			buff[px.GetPosition().x][px.GetPosition().y].Char.AsciiChar = px.GetLook();
			buff[px.GetPosition().x][px.GetPosition().y].Attributes = px.GetFGColor() | px.GetBGColor() << 4;
		}

		WriteConsoleOutput(m_hConsoleBuffer, (CHAR_INFO*)buff, size, start, &srect);
	}

}

