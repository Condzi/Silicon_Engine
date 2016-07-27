#pragma once
#include "Silicon/Silicon.hpp"

namespace se
{
	class Pixel
	{
	public:
		Pixel();
		Pixel(Color fgColor, Color bgColor, Vector2i position);
		~Pixel();

		char GetLook();
		Color GetFGColor();
		Color GetBGColor();
		Vector2u16 GetPosition();

		void SetLook(char newLook);
		void SetFGColor(Color newColor);
		void SetBGColor(Color newColor);
		void SetPosition(Vector2i newPosition);

		void Move(Vector2i offset);


		friend bool operator==(const Pixel & left, const Pixel & right);
		friend bool operator!=(const Pixel & left, const Pixel & right);
		friend std::ostream & operator<<(std::ostream & os, const Pixel & pixel);

	private:
		char m_look;
		Color m_foregroundColor;
		Color m_backgroundColor;
		Vector2i m_position;
	};
}

