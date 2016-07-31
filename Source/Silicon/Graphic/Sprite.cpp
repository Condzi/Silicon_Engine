#include "Sprite.hpp"


namespace se
{
	void Sprite::setImagePixelsAbsolutePosition()
	{
		for (Pixel & px : m_image->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x - m_position.x, px.GetPosition().y - m_position.y));
	}

	void Sprite::setImagePixelsRelativePosition()
	{
		for (Pixel & px : m_image->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x + m_position.x, px.GetPosition().y + m_position.y));
	}


	Sprite::Sprite() :
		m_image(nullptr),
		m_position(0, 0)
	{}

	Sprite::Sprite(Image & imagePointer, Vector2i position)
	{
		m_image = nullptr;
		SetImagePointer(imagePointer);
		SetPosition(position);
	}

	Sprite::~Sprite()
	{
		if (HaveImage())
			delete m_image;
	}


	Vector2i Sprite::GetPosition()
	{
		return m_position;
	}

	Vector2u16 Sprite::GetSize()
	{
		return m_image->m_size;
	}

	bool Sprite::HaveImage()
	{
		return m_image != nullptr;
	}

	void Sprite::SetPosition(Vector2i newPosition)
	{
		setImagePixelsAbsolutePosition();
		m_position = newPosition;
		setImagePixelsRelativePosition();
	}

	void Sprite::Move(Vector2i offset)
	{
		for (Pixel & px : m_image->m_pixels)
			px.Move(offset);

		m_position += offset;
	}

	void Sprite::SetImagePointer(Image & imageReference)
	{
		if (m_image != nullptr)
			delete m_image;

		m_image = new Image;
		m_image->m_pixels = imageReference.m_pixels;
		m_image->m_size = imageReference.m_size;
	}
}
