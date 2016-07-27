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


	bool operator==(const Pixel & left, const Pixel & right)
	{
		return (left.m_look == right.m_look) && (left.m_foregroundColor == right.m_foregroundColor) &&
			(left.m_backgroundColor == right.m_backgroundColor) && (left.m_position == right.m_position);
	}

	bool operator!=(const Pixel & left, const Pixel & right)
	{
		return !(left == right);
	}

	std::ostream & operator<<(std::ostream & os, const Pixel & pixel)
	{
		in::SetCursorPosition(pixel.m_position);
		in::SetTextColor(pixel.m_foregroundColor, pixel.m_backgroundColor);
		os << pixel.m_look;

		return os;
	}

}
