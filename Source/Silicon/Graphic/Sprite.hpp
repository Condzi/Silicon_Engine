#pragma once
#include "Image.hpp"


namespace se
{
	class Image; 

	class Sprite
	{
	public:
		Sprite();
		Sprite(Image & imagePointer, Vector2i position);
		~Sprite();

		Vector2i GetPosition();
		Image GetImage();

		void SetPosition(Vector2i newPosition);
		void Move(Vector2i offset);
		void SetImagePointer(Image & imageReference);

		void Draw();
		//void Draw(Pixels buffer[]) instead of Draw()

	private:
		Image * m_imagePointer;
		Vector2i m_position;
	};

}
