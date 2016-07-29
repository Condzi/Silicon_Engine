#include "NewRenderer.hpp"


namespace se
{
	void NewRenderer::addPixel(Pixel & px)
	{
		if (px.GetPosition().x * px.GetPosition().y > GetSystemMetrics(SM_CXSCREEN) * GetSystemMetrics(SM_CYSCREEN))
			return;

		//m_pixels[px.GetPosition().x][px.GetPosition().y] = px;
		m_pixels[1][1] = Pixel(Color::White, Color::Red, Vector2i(10, 10));

	}

	void NewRenderer::fillBlanks()
	{
		for (unsigned x = 0; x < m_pixels.size(); ++x)
			for (unsigned y = 0; y < m_pixels.at(0).size(); ++y)
				m_pixels.at(x).at(y) = Pixel(Color::Black, Color::Black, Vector2i(0,0));
	}

	NewRenderer::NewRenderer() :
		m_hConsoleBuffer(GetStdHandle(STD_OUTPUT_HANDLE))
	{
		m_pixels.resize(GetSystemMetrics(SM_CYSCREEN));

		for (std::vector<Pixel> & vec : m_pixels)
			vec.resize(GetSystemMetrics(SM_CXSCREEN));

		fillBlanks();
	}

	NewRenderer::NewRenderer(const HANDLE & console) :
		m_hConsoleBuffer(console)
	{
		m_pixels.resize(GetSystemMetrics(SM_CYSCREEN));

		for (std::vector<Pixel> & vec : m_pixels)
			vec.resize(GetSystemMetrics(SM_CXSCREEN));

		fillBlanks();
	}

	NewRenderer::~NewRenderer()
	{
	}


	void NewRenderer::Clear()
	{
		m_pixels.clear();
		fillBlanks();
	}

	void NewRenderer::Draw(Sprite & spr)
	{
	//	for (Pixel & px : spr.GetImagePointer()->m_pixels)
			addPixel(Pixel());
	}

	void NewRenderer::Display()
	{
		CHAR_INFO ** buff = new CHAR_INFO * [GetSystemMetrics(SM_CYSCREEN)];
		COORD size = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
		COORD start = { 0,0 };
		SMALL_RECT srect = { 0,0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };

		for (uint16_t i = 0; i < GetSystemMetrics(SM_CYSCREEN); ++i)
			buff[i] = new CHAR_INFO[GetSystemMetrics(SM_CXSCREEN)];

		for(uint16_t y = 0; y < GetSystemMetrics(SM_CYSCREEN); ++y)
			for (uint16_t x = 0; x < GetSystemMetrics(SM_CXSCREEN); ++x)
			{
				buff[x][y].Char.AsciiChar = m_pixels[x][y].GetLook();
				buff[x][y].Attributes = m_pixels[x][y].GetFGColor() | m_pixels[x][y].GetBGColor() << 4;
			}

		WriteConsoleOutput(m_hConsoleBuffer, (CHAR_INFO*)buff, size, start, &srect);
	}

}

