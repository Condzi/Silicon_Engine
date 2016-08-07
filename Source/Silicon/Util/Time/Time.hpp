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
		friend Time Milliseconds(const int32_t & val);
		friend Time Microseconds(const int64_t & val);

		Time& operator=(const Time & other);
		Time & operator+=(Time & other);
		Time & operator-=(Time & other);
		Time & operator*=(Time & other);
		Time & operator/=(Time & other);
		
	private:
		// 1 second - 1 000 000 microseconds
		// 1 millisecond - 1 000 microseconds
		int64_t m_microseconds;


		friend bool operator==(Time & left, Time & right);
		friend bool operator!=(Time & left, Time & right);
		friend bool operator<(Time & left, Time & right);
		friend bool operator>(Time & left, Time & right);
		friend Time & operator+(Time left, Time & right);
		friend Time & operator-(Time left, Time & right);
		friend Time & operator*(Time left, Time & right);
		friend Time & operator/(Time left, Time & right);
	};
}

