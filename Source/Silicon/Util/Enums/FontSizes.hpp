#pragma once
#include "Silicon/Silicon.hpp"


namespace se
{
	//Normal size - G [8 x 12]
	enum class TextSize : uint8_t
	{
		//4 x 6
		A = 0,
		//16 x 8
		B,
		//6 x 9
		C,
		//8 x 9
		D,
		//5 x 12
		E,
		//7 x 12
		F,
		//8 x 12
		G,
		//16 x 12
		H,
		//12 x 16
		I,
		//10 x 18
		J
	};
}