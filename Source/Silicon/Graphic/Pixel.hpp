#pragma once
#include "Silicon/Util/ConsoleManip/ConsoleManip.hpp"
#include "Silicon/Math/Vector2.hpp"


namespace se
{
	/*
		Pixel class - use to display chars using in::Renderer
	*/
	class Pixel
	{
		friend class Renderer;

	public:
		Pixel();
		Pixel(Color fgColor, Color bgColor, Vector2i position);
		Pixel(char look);
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

	private:
		char m_look;
		Color m_foregroundColor;
		Color m_backgroundColor;
		Vector2i m_position;
	};
}

