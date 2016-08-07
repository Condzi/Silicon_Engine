#include "ConsoleManip.hpp"
#include <iostream>

namespace se
{
	namespace in
	{
		void SetCursorPosition(uint16_t x, uint16_t y, const HANDLE & console)
		{
			in::SetCursorPosition(se::Vector2u16(x, y), console);
		}

		void SetCursorPosition(const Vector2u16 & pos, const HANDLE & console)
		{
			COORD coord = { pos.x, pos.y };
			
			SetConsoleCursorPosition(console, coord);
		}


		void ClearScreen(char cleanChar, const HANDLE & console)
		{
			COORD coordScreen = { 0, 0 };  
			DWORD cCharsWritten;
			DWORD dwConSize;
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(console, &csbi);
			dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
			FillConsoleOutputCharacter(console, TCHAR(cleanChar), dwConSize, coordScreen, &cCharsWritten);
		}


		void SetScreenSize(uint16_t width, uint16_t height, const HANDLE & console)
		{
			in::SetScreenSize(Vector2u16(width, height), console);
		}

		void SetScreenSize(Vector2u16 size, const HANDLE & console)
		{
			COORD coord;
			SMALL_RECT Rect;

			coord.X = size.x;
			coord.Y = size.y;

			Rect.Left = 0;
			Rect.Top = 0;
			Rect.Right = size.x;
			Rect.Bottom = size.y;

			SetConsoleScreenBufferSize(console, coord);            // Set Buffer Size 
			SetConsoleWindowInfo(console, TRUE, &Rect);            // Set Window Size 
		}


		void SetTextColor(const uint8_t & foreground, const uint8_t & background, const HANDLE & console)
		{
			SetConsoleTextAttribute(console, foreground + (background * 16));
		}


		void SetTextSize(TextSize size, const HANDLE & console)
		{
			CONSOLE_FONT_INFOEX info { sizeof(CONSOLE_FONT_INFOEX) };

			GetCurrentConsoleFontEx(console, false, &info);
			info.dwFontSize.X = getTextSize(size).x;
			info.dwFontSize.Y = getTextSize(size).y;
			SetCurrentConsoleFontEx(console, false, &info);
		}


		Vector2u16 getTextSize(TextSize & size)
		{
			switch (size)
			{
			case TextSize::A: return Vector2u16(4, 6);

			case TextSize::B: return Vector2u16(16, 8);

			case TextSize::C: return Vector2u16(6, 9);

			case TextSize::D: return Vector2u16(8, 9);
			
			case TextSize::E: return Vector2u16(5, 12);
			
			case TextSize::F: return Vector2u16(7, 12);
			
			case TextSize::G: return Vector2u16(8, 12);

			case TextSize::H: return Vector2u16(16, 12);

			case TextSize::I: return Vector2u16(12, 16);

			case TextSize::J: return Vector2u16(10, 18);
			}

			return Vector2u16(8, 12);
		}
	}
}

