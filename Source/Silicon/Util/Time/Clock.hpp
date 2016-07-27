#pragma once
#include <chrono>
#include "Silicon/Util/Time/Time.hpp"

namespace se
{
	class Clock
	{
	public:
		Clock();
		~Clock();

		/*
			Returns time in microseconds
		*/
		Time GetEleapsedTime();
		/*
			Restarts clock and returns eleapsed time in microseconds
		*/
		Time Restart();
	
	private:
		std::chrono::high_resolution_clock::time_point m_startTime;
	};
}


