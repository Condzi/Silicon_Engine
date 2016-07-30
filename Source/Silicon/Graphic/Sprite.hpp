#pragma once
#include "Image.hpp"
#include "Silicon/Graphic/Renderer/Renderer.hpp"


namespace se
{
	class Image; 
	class Renderer;

	class Sprite
	{
		friend class Renderer;
	private:
		void setImagePixelsAbsolutePosition();
		void setImagePixelsRelativePosition();

	public:
		Sprite();
		Sprite(Image & imagePointer, Vector2i position);
		~Sprite();

		Vector2i GetPosition();
		Vector2u16 GetSize();
		bool HaveImage();

		void SetPosition(Vector2i newPosition);
		void Move(Vector2i offset);
		void SetImagePointer(Image & imageReference);

	private:
		Image * m_image;
		Vector2i m_position;
	};

}
