#include "Time.hpp"


namespace se
{
	Time::Time() :
		m_microseconds(0)
	{}

	Time::Time(const int64_t & microseconds) :
		m_microseconds(microseconds)
	{}

	Time::~Time()
	{}


	float Time::AsSeconds() const
	{
		return m_microseconds / 1000000.f;
	}

	int32_t Time::AsMilliseconds() const
	{
		return static_cast<int32_t>(m_microseconds / 1000);
	}

	int64_t Time::AsMicroseconds() const
	{
		return m_microseconds;
	}

	Time & Time::operator=(const Time & other)
	{
		this->m_microseconds = other.m_microseconds;

		return *this;
	}

	Time Seconds(float val)
	{
		return Time(static_cast<int64_t>(val * 1000000));
	}

	Time Milliseconds(const int32_t & val)
	{
		return Time(static_cast<int64_t>(val) * 1000);
	}

	Time Microseconds(const int64_t & val)
	{
		return Time(val);
	}
}
