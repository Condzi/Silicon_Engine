#pragma once
#include <windows.h>
#include <cstdio>
#include <iostream>
#include "Silicon/Silicon.hpp"


namespace se
{
	namespace in
	{
		/*
			Sets console cursor on X and Y position in CONSOLE handle
			Prefered Vector2u16 version.
		*/
		void SetCursorPosition(uint16_t x, uint16_t y, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));
		/*
			Sets console cursor on pos.X and pos.Y position in CONSOLE handle
		*/
		void SetCursorPosition(const Vector2u16 & pos, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		/*
			Clears CONSOLE screen, fills it with cleanChar
		*/
		void ClearScreen(char cleanChar = ' ', const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		/*
			Sets console screen width and height in CONSOLE handle
			Prefered Vector2u16 version.
		*/
		void SetScreenSize(uint16_t width, uint16_t height, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));
		/*
			Sets console screen width and height in CONSOLE handle
		*/
		void SetScreenSize(Vector2u16 size, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		/*
			Sets CONSOLE foreground (character) and background color. 
			To colors use se::Color enum.
		*/
		void SetTextColor(const uint8_t & foreground, const uint8_t & background = 0, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		/*
			Sets CONSOLE font (text) size.
		*/
		void SetTextSize(TextSize size, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));


		Vector2u16 getTextSize(TextSize & size);

	}
}