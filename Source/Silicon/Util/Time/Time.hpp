#pragma once
#include <cinttypes>


namespace se
{
	class Time
	{
	public:
		Time();
		Time(const int64_t & microseconds);
		~Time();

		float AsSeconds() const;
		int32_t AsMilliseconds() const;
		int64_t AsMicroseconds() const;

		friend Time Seconds(float val);
		friend Time Milliseconds(int32_t val);
		friend Time Microseconds(int64_t val);

		Time& operator=(const Time & other);
		
	private:
		// 1 second - 1 000 000 microseconds
		// 1 millisecond - 1 000 microseconds
		int64_t m_microseconds;
	};
}

