#include "Sprite.hpp"


namespace se
{

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
		for (Pixel & px : m_imagePointer->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x - m_position.x, px.GetPosition().y - m_position.y));

		m_position = newPosition;

		for(Pixel & px : m_imagePointer->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x + m_position.x, px.GetPosition().y + m_position.y));
	}

	void Sprite::Move(Vector2i offset)
	{
		for (Pixel & px : m_imagePointer->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x - m_position.x, px.GetPosition().y - m_position.y));

		m_position += offset;
		
		for (Pixel & px : m_imagePointer->m_pixels)
			px.SetPosition(Vector2i(px.GetPosition().x + m_position.x, px.GetPosition().y + m_position.y));
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
