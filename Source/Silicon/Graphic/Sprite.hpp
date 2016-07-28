#pragma once
#include "Image.hpp"
#include "Silicon/Graphic/Renderer/Renderer.hpp"


namespace se
{
	class Image; 
	class Renderer;

	class Sprite
	{
	private:
		void setImagePixelsAbsolutePosition();
		void setImagePixelsRelativePosition();

	public:
		Sprite();
		Sprite(Image & imagePointer, Vector2i position);
		~Sprite();

		Vector2i GetPosition();
		Vector2u16 GetSize();
		Image * GetImagePointer();
		bool HaveImage();

		void SetPosition(Vector2i newPosition);
		void Move(Vector2i offset);
		void SetImagePointer(Image & imageReference);

		void Draw();
		void Draw(Renderer & renderer);

	private:
		Image * m_imagePointer;
		Vector2i m_position;
	};

}
