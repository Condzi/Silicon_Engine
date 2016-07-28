#include "Sprite.hpp"


namespace se
{
	void Sprite::setImagePixelsAbsoltePosition()
	{
		for (Pixel & px : m_imagePointer->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x - m_position.x, px.GetPosition().y - m_position.y));
	}

	void Sprite::setImagePixelsRelativePosition()
	{
		for (Pixel & px : m_imagePointer->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x + m_position.x, px.GetPosition().y + m_position.y));
	}


	Sprite::Sprite() :
		m_imagePointer(0),
		m_position(0, 0)
	{}

	Sprite::Sprite(Image & imagePointer, Vector2i position) :
		m_imagePointer(&imagePointer),
		m_position(position)
	{}

	Sprite::~Sprite()
	{}


	Vector2i Sprite::GetPosition()
	{
		return m_position;
	}

	Image Sprite::GetImage()
	{
		return *m_imagePointer;
	}

	void Sprite::SetPosition(Vector2i newPosition)
	{
		setImagePixelsAbsoltePosition();
		m_position = newPosition;
		setImagePixelsRelativePosition();

	}

	void Sprite::Move(Vector2i offset)
	{
		setImagePixelsAbsoltePosition();
		m_position += offset;
		setImagePixelsRelativePosition();
	}

	void Sprite::SetImagePointer(Image & imageReference)
	{
		m_imagePointer = &imageReference;
	}

	void Sprite::Draw()
	{
		for (Pixel & px : m_imagePointer->m_pixels)
			std::cout << px;
	}
}
