#pragma once
#include <windows.h>
#include <cstdio>
#include <iostream>
#include "Silicon/Silicon.hpp"


namespace se
{
	namespace in
	{
		void SetCursorPosition(uint16_t x, uint16_t y, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));
		void SetCursorPosition(const Vector2u16 & pos, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		void ClearScreen(char cleanChar = ' ', const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		void SetScreenSize(uint16_t width, uint16_t height, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));
		void SetScreenSize(Vector2u16 size, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		void SetTextColor(const uint8_t & foreground, const uint8_t & background = 0, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));

		void SetTextSize(TextSize size, const HANDLE & console = GetStdHandle(STD_OUTPUT_HANDLE));


		Vector2u16 getTextSize(TextSize & size);

	}
}