#include "Sprite.hpp"


namespace se
{
	void Sprite::setImagePixelsAbsolutePosition()
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
		m_imagePointer(nullptr),
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

	Vector2u16 Sprite::GetSize()
	{
		return m_imagePointer->m_size;
	}

	Image Sprite::GetImage()
	{
		if (!HaveSprite())
			return Image();

		return *m_imagePointer;
	}

	bool Sprite::HaveSprite()
	{
		return m_imagePointer != nullptr;
	}

	void Sprite::SetPosition(Vector2i newPosition)
	{
		setImagePixelsAbsolutePosition();
		m_position = newPosition;
		setImagePixelsRelativePosition();
	}

	void Sprite::Move(Vector2i offset)
	{
		setImagePixelsAbsolutePosition();
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

	void Sprite::Draw(Renderer & renderer)
	{
		renderer.AddSprite(*this);
	}
}
