#include "Pixel.hpp"


namespace se
{
	Pixel::Pixel() :
		m_look(219),
		m_foregroundColor(Color::White),
		m_backgroundColor(Color::Black),
		m_position(0,0)
	{}

	Pixel::Pixel(Color fgColor, Color bgColor, Vector2i position) :
		m_look(219),
		m_foregroundColor(fgColor),
		m_backgroundColor(bgColor),
		m_position(position)
	{}

	Pixel::~Pixel()
	{}

	char Pixel::GetLook()
	{
		return m_look;
	}

	Color Pixel::GetFGColor()
	{
		return m_foregroundColor;
	}

	Color Pixel::GetBGColor()
	{
		return m_backgroundColor;
	}

	Vector2u16 Pixel::GetPosition()
	{
		return m_position;
	}

	void Pixel::SetLook(char newLook)
	{
		m_look = newLook;
	}

	void Pixel::SetFGColor(Color newColor)
	{
		m_foregroundColor = newColor;
	}

	void Pixel::SetBGColor(Color newColor)
	{
		m_backgroundColor = newColor;
	}

	void Pixel::SetPosition(Vector2i newPosition)
	{
		m_position = newPosition;
	}

	void Pixel::Move(Vector2i offset)
	{
		m_position += offset;
	}

	void Pixel::Draw()
	{
		//DWORD len = 1;
		//DWORD dwBytesWritten = 0;
		//COORD pos = { m_position.x, m_position.y };
		//in::SetTextColor(m_foregroundColor, m_backgroundColor);
		//WriteConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), LPCWSTR(m_look), len, pos, &dwBytesWritten);

		in::SetCursorPosition(m_position);
		in::SetTextColor(m_foregroundColor, m_backgroundColor);
		fwrite(&m_look, 1, 1, stderr);
		//putc(m_look, stderr);
		//std::cout << m_look;
		//putchar(m_look);
	}
}
